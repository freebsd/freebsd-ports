--- main.c.orig	2007-02-13 02:01:19.000000000 +0300
+++ main.c	2009-09-28 15:55:36.000000000 +0400
@@ -29,10 +29,21 @@
 static void objcdummyfunction( void ) { objc_msgSend(); }
 #endif
 
+#if defined(__FreeBSD__) && defined(_THREAD_SAFE)
+static int argc;
+static char **argv;
+static char **envp;
+#endif
+
+#if defined(__FreeBSD__) && defined(_THREAD_SAFE)
+void *
+main_entry(void *arg)
+#else
 int
 main(argc, argv, envp)
     int argc;
     char **argv, **envp;
+#endif
 {
 #ifdef _WIN32
     NtInitialize(&argc, &argv);
@@ -47,5 +58,61 @@
         ruby_options(argc, argv);
         ruby_run();
     }
+#if defined(__FreeBSD__) && defined(_THREAD_SAFE)
+    return (NULL);
+#else
     return 0;
+#endif
 }
+
+#if defined(__FreeBSD__) && defined(_THREAD_SAFE)
+#include <sys/types.h>
+#include <sys/time.h>
+#include <sys/resource.h>
+int
+main(main_argc, main_argv, main_envp)
+    int main_argc;
+    char **main_argv, **main_envp;
+{
+    struct rlimit rl;
+    pthread_attr_t attr;
+    pthread_t tid;
+    size_t stacksize;
+    int error;
+
+    argc = main_argc;
+    argv = main_argv;
+    envp = main_envp;
+    /* Get the system imposed limit. */
+    error = getrlimit(RLIMIT_STACK, &rl);
+    if (error != 0) {
+	fprintf(stderr, "cannot obtain resource limit\n");
+	exit(1);
+    }
+    stacksize = rl.rlim_cur * 3 / 4;	/* Set initial size to 3/4 of limit */
+    error = pthread_attr_init(&attr);
+    if (error != 0) {
+	fprintf(stderr, "cannot initialize thread attributes\n");
+	exit(1);
+    }
+    while (stacksize > 0) {
+    	error = pthread_attr_setstacksize(&attr, stacksize);
+	if (error != 0)
+		goto next;
+	error = pthread_create(&tid, &attr, &main_entry, NULL);
+	if (error == 0)
+		break;
+    next:
+	stacksize = stacksize >> 1;
+    }
+    if (stacksize != 0) {	/* Success. */
+	pthread_detach(tid);
+	pthread_exit(NULL);
+        return (0);
+    }
+    else {
+	fprintf(stderr, "Cannot create main thread\n");
+	return (1);
+    }
+}
+#endif
