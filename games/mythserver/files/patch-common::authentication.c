--- common/authentication.c.orig	Sat Feb  9 15:13:18 2002
+++ common/authentication.c	Sat Feb  9 15:13:34 2002
@@ -15,6 +15,7 @@
 #include "authentication.h"
 
 /* -------- code */
+#define SERVER
 
 #ifdef SERVER
 static authentication_token global_guest_token= {0};
