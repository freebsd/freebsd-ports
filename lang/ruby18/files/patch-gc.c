--- gc.c.orig	2009-12-24 00:28:08.000000000 -0800
+++ gc.c	2010-01-05 18:02:16.000000000 -0800
@@ -30,6 +30,10 @@
 #include <sys/resource.h>
 #endif
 
+#if defined(HAVE_PTHREAD_NP_H)
+#include <pthread_np.h>
+#endif
+
 #if defined _WIN32 || defined __CYGWIN__
 #include <windows.h>
 #endif
@@ -75,6 +79,7 @@
 static void run_final();
 static VALUE nomem_error;
 static void garbage_collect();
+static void set_stack_limit();
 
 int ruby_gc_stress = 0;
 
@@ -485,6 +490,8 @@
 # define STACK_LEVEL_MAX 655300
 #endif
 
+VALUE *stack_bottom_addr = 0x0;
+
 #ifdef C_ALLOCA
 # define SET_STACK_END VALUE stack_end; alloca(0);
 # define STACK_END (&stack_end)
@@ -534,9 +541,22 @@
 
 #define GC_WATER_MARK 512
 
-#define CHECK_STACK(ret) do {\
+#define CHECK_STACK(ret, prev) do {\
     SET_STACK_END;\
-    (ret) = (STACK_LENGTH > STACK_LEVEL_MAX + GC_WATER_MARK);\
+    ssize_t avail;\
+    if (stack_bottom_addr != 0) {\
+	if (STACK_UPPER(&avail, 1, -1) > 0)\
+	    avail = stack_bottom_addr - STACK_END;\
+	else\
+	    avail = STACK_END - stack_bottom_addr;\
+    } else {\
+	avail = STACK_LEVEL_MAX + GC_WATER_MARK - STACK_LENGTH;\
+    }\
+    if (avail <= 0 || (prev != 0 && (prev - avail) > avail))\
+	(ret) = 1;\
+    else\
+	(ret) = 0;\
+    (prev) = avail;\
 } while (0)
 
 size_t
@@ -552,8 +572,9 @@
 ruby_stack_check()
 {
     int ret;
+    static ssize_t prev = 0;
 
-    CHECK_STACK(ret);
+    CHECK_STACK(ret, prev);
     return ret;
 }
 
@@ -1607,18 +1628,72 @@
     }
     rb_gc_stack_start = addr;
 #endif
+    set_stack_limit();
+}
+
+static void set_stack_limit()
+{
+	size_t stacksize = 0;
+
 #ifdef HAVE_GETRLIMIT
     {
 	struct rlimit rlim;
 
-	if (getrlimit(RLIMIT_STACK, &rlim) == 0) {
-	    unsigned int space = rlim.rlim_cur/5;
+	if (getrlimit(RLIMIT_STACK, &rlim) == 0)
+	    stacksize = rlim.rlim_cur;
+    }
+#elif defined _WIN32
+    {
+	MEMORY_BASIC_INFORMATION mi;
 
-	    if (space > 1024*1024) space = 1024*1024;
-	    STACK_LEVEL_MAX = (rlim.rlim_cur - space) / sizeof(VALUE);
+	if (VirtualQuery(&mi, &mi, sizeof(mi))) {
+	    stacksize = (char *)mi.BaseAddress - (char *)mi.AllocationBase;
+	}
+    }
+#endif
+#if defined(_THREAD_SAFE) && defined(HAVE_PTHREAD_NP_H)
+    {
+	pthread_attr_t  attr;
+	size_t          size;
+	void		*addr;
+
+	pthread_attr_init(&attr);
+	if (pthread_attr_get_np(pthread_self(), &attr) == 0) {
+	    pthread_attr_getstack(&attr, &addr, &size);
+	    if (stacksize == 0 || size < stacksize)
+		stacksize = size;
+            stack_bottom_addr = addr;
+	}
+	pthread_attr_destroy(&attr);
+    }
+#endif
+    if (stacksize) {
+	unsigned int space = stacksize / 5;
+
+	if (space > 1024*1024)
+	    space = 1024*1024;
+	STACK_LEVEL_MAX = (stacksize - space) / sizeof(VALUE);
+#if defined(__FreeBSD__)
+#include <sys/sysctl.h>
+    if (stack_bottom_addr == 0) {
+	size_t len;
+	void *usrstack;
+	int mib[2];
+	int error;
+
+	len = sizeof(usrstack);
+	mib[0] = CTL_KERN;
+	mib[1] = KERN_USRSTACK;
+	error = sysctl(mib, 2, &usrstack, &len, NULL, 0);
+	if (error == 0) {
+	    if (STACK_UPPER(&avail, 1, -1) > 0)
+		stack_bottom_addr = usrstack + (stacksize - space);
+	    else
+		stack_bottom_addr = usrstack - (stacksize - space);
 	}
     }
 #endif
+    }
 }
 
 void ruby_init_stack(VALUE *addr
@@ -1639,31 +1714,7 @@
         rb_gc_register_stack_start = (VALUE*)bsp;
     }
 #endif
-#ifdef HAVE_GETRLIMIT
-    {
-        struct rlimit rlim;
-
-        if (getrlimit(RLIMIT_STACK, &rlim) == 0) {
-            unsigned int space = rlim.rlim_cur/5;
-
-            if (space > 1024*1024) space = 1024*1024;
-            STACK_LEVEL_MAX = (rlim.rlim_cur - space) / sizeof(VALUE);
-        }
-    }
-#elif defined _WIN32
-    {
-	MEMORY_BASIC_INFORMATION mi;
-	DWORD size;
-	DWORD space;
-
-	if (VirtualQuery(&mi, &mi, sizeof(mi))) {
-	    size = (char *)mi.BaseAddress - (char *)mi.AllocationBase;
-	    space = size / 5;
-	    if (space > 1024*1024) space = 1024*1024;
-	    STACK_LEVEL_MAX = (size - space) / sizeof(VALUE);
-	}
-    }
-#endif
+    set_stack_limit();
 }
 
 /*
