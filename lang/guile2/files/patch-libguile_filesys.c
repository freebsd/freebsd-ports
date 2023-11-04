--- libguile/filesys.c.orig	2019-06-30 14:31:23 UTC
+++ libguile/filesys.c
@@ -1513,6 +1513,9 @@ SCM_DEFINE (scm_i_mkstemp, "mkstemp!", 1, 1, 0,
       mode_bits = scm_i_mode_bits (mode);
     }
 
+#ifdef __FreeBSD__
+  open_flags &= O_APPEND | O_DIRECT | O_SHLOCK | O_EXLOCK | O_CLOEXEC;
+#endif
   SCM_SYSCALL (rv = mkostemp (c_tmpl, open_flags));
   if (rv == -1)
     SCM_SYSERROR;
