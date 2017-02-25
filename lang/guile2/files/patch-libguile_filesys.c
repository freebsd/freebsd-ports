--- libguile/filesys.c.orig	2017-02-06 04:37:29 UTC
+++ libguile/filesys.c
@@ -1486,6 +1486,9 @@ SCM_DEFINE (scm_i_mkstemp, "mkstemp!", 1
       mode_bits = scm_i_mode_bits (mode);
     }
 
+#ifdef __FreeBSD__
+  open_flags &= O_APPEND | O_DIRECT | O_SHLOCK | O_EXLOCK | O_CLOEXEC;
+#endif
   SCM_SYSCALL (rv = mkostemp (c_tmpl, open_flags));
   if (rv == -1)
     SCM_SYSERROR;
