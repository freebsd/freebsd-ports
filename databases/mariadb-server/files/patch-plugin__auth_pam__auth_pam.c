--- plugin/auth_pam/auth_pam.c.orig	2012-01-04 14:17:30.000000000 +0100
+++ plugin/auth_pam/auth_pam.c	2012-01-04 14:17:36.000000000 +0100
@@ -1,7 +1,6 @@
 #include <mysql/plugin_auth.h>
 #include <string.h>
 #include <security/pam_appl.h>
-#include <security/pam_modules.h>
 
 struct param {
   unsigned char buf[10240], *ptr;
