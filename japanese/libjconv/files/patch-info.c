--- info.c.orig	Sat Aug  5 05:52:38 2000
+++ info.c	Fri Jan 12 02:12:40 2001
@@ -13,7 +13,7 @@
 
 #define DEBUG_DO(x)
 
-#define JCONV_DEFAULT_CONFFILE "/etc/libjconv/default.conf"
+#define JCONV_DEFAULT_CONFFILE "!!PREFIX!!/etc/libjconv/default.conf"
 
 typedef struct {
 	char *name;
