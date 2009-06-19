--- gc.c.orig	2009-03-27 13:25:23.000000000 +0300
+++ gc.c	2009-06-19 16:26:54.000000000 +0400
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
 
@@ -534,9 +539,14 @@
 
 #define GC_WATER_MARK 512
 
-#define CHECK_STACK(ret) do {\
+#define CHECK_STACK(ret, prev) do {\
     SET_STACK_END;\
-    (ret) = (STACK_LENGTH > STACK_LEVEL_MAX + GC_WATER_MARK);\
+    ssize_t avail = STACK_LEVEL_MAX + GC_WATER_MARK - STACK_LENGTH;\
+    if (avail <= 0 || (prev != -1 && (signed)(STACK_LENGTH - prev) > avail))\
+	(ret) = 1;\
+    else\
+	(ret) = 0;\
+    (prev) = STACK_LENGTH;\
 } while (0)
 
 size_t
@@ -552,8 +562,9 @@
 ruby_stack_check()
 {
     int ret;
+    static size_t prev = -1;
 
-    CHECK_STACK(ret);
+    CHECK_STACK(ret, prev);
     return ret;
 }
 
@@ -1599,18 +1610,50 @@
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
+
+	if (VirtualQuery(&mi, &mi, sizeof(mi))) {
+	    stacksize = (char *)mi.BaseAddress - (char *)mi.AllocationBase;
+	}
+    }
+#endif
+#if defined(_THREAD_SAFE) && defined(HAVE_PTHREAD_NP_H)
+    {
+	pthread_attr_t  attr;
+	size_t          size;
 
-	    if (space > 1024*1024) space = 1024*1024;
-	    STACK_LEVEL_MAX = (rlim.rlim_cur - space) / sizeof(VALUE);
+	pthread_attr_init(&attr);
+	if (pthread_attr_get_np(pthread_self(), &attr) == 0) {
+	    pthread_attr_getstacksize(&attr, &size);
+	    if (stacksize == 0 || size < stacksize)
+		stacksize = size;
 	}
+	pthread_attr_destroy(&attr);
     }
 #endif
+    if (stacksize) {
+	unsigned int space = stacksize / 5;
+
+	if (space > 1024*1024)
+	    space = 1024*1024;
+	STACK_LEVEL_MAX = (stacksize - space) / sizeof(VALUE);
+    }
 }
 
 void ruby_init_stack(VALUE *addr
@@ -1631,31 +1674,7 @@
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
@@ -1980,7 +1999,7 @@
 chain_finalized_object(st_data_t key, st_data_t val, st_data_t arg)
 {
     RVALUE *p = (RVALUE *)key, **final_list = (RVALUE **)arg;
-    if ((p->as.basic.flags & (FL_FINALIZE|FL_MARK)) == FL_FINALIZE) {
+    if ((p->as.basic.flags & (FL_FINALIZE)) == FL_FINALIZE) {
 	if (BUILTIN_TYPE(p) != T_DEFERRED) {
 	    p->as.free.flags = FL_MARK | T_DEFERRED; /* remain marked */
 	    RDATA(p)->dfree = 0;
