--- modules/file-method-acl.c.orig	Mon Jul 24 18:47:12 2006
+++ modules/file-method-acl.c	Mon Jul 24 22:01:34 2006
@@ -45,7 +45,7 @@
 #endif
 
 #ifdef HAVE_POSIX_ACL
-# include <acl/libacl.h>
+# include <sys/acl.h>
 #define HAVE_ACL 1
 #endif
 
