--- libguile/posix.c.orig	Mon Dec  8 17:26:35 2003
+++ libguile/posix.c	Mon Dec  8 17:31:20 2003
@@ -147,10 +147,6 @@
 #include <locale.h>
 #endif
 
-#if HAVE_LIBCRYPT && HAVE_CRYPT_H
-#  include <crypt.h>
-#endif
-
 #if HAVE_SYS_RESOURCE_H
 #  include <sys/resource.h>
 #endif
@@ -1343,7 +1339,7 @@
 #undef FUNC_NAME
 #endif /* HAVE_SYNC */
 
-#if HAVE_LIBCRYPT && HAVE_CRYPT_H
+#if HAVE_LIBCRYPT
 SCM_DEFINE (scm_crypt, "crypt", 2, 0, 0, 
             (SCM key, SCM salt),
 	    "Encrypt @var{key} using @var{salt} as the salt value to the\n"
@@ -1361,7 +1357,7 @@
   return scm_makfrom0str (p);
 }
 #undef FUNC_NAME
-#endif /* HAVE_LIBCRYPT && HAVE_CRYPT_H */
+#endif /* HAVE_LIBCRYPT */
 
 #if HAVE_CHROOT
 SCM_DEFINE (scm_chroot, "chroot", 1, 0, 0, 
