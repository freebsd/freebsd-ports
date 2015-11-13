--- include/sane/sanei_backend.h.orig	2013-08-25 21:22:58 UTC
+++ include/sane/sanei_backend.h
@@ -68,9 +68,11 @@
 
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
@@ -96,7 +98,9 @@
 #  undef SIG_SETMASK
 # endif
 
+#if 0
 # define sigset_t               int
+#endif
 # define sigemptyset(set)       do { *(set) = 0; } while (0)
 # define sigfillset(set)        do { *(set) = ~0; } while (0)
 # define sigaddset(set,signal)  do { *(set) |= sigmask (signal); } while (0)
