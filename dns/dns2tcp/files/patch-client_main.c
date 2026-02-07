--- client/main.c.orig	2020-08-28 19:28:55 UTC
+++ client/main.c
@@ -36,6 +36,8 @@
 #include "myerror.h"
 #include "dns.h"
 
+int debug;
+
 /**
  * @brief main part
  * @retval 0 on success
