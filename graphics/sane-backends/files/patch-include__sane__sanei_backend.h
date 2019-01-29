--- include/sane/sanei_backend.h.orig	2016-10-06 00:02:58 UTC
+++ include/sane/sanei_backend.h
@@ -64,9 +64,11 @@
 
 /* Just enough backwards compatibility that we get by in the backends
    without making handstands.  */
+#if 0
 # ifdef sigset_t
 #  undef sigset_t
 # endif
+#endif
 # ifdef sigemptyset
 #  undef sigemptyset
 # endif
@@ -92,7 +94,9 @@
 #  undef SIG_SETMASK
 # endif
 
+#if 0
 # define sigset_t               int
+#endif
 # define sigemptyset(set)       do { *(set) = 0; } while (0)
 # define sigfillset(set)        do { *(set) = ~0; } while (0)
 # define sigaddset(set,signal)  do { *(set) |= sigmask (signal); } while (0)
