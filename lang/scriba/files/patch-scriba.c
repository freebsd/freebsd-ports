--- scriba.c.orig	Tue Mar  1 23:06:45 2005
+++ scriba.c	Wed Mar  2 01:07:07 2005
@@ -98,7 +98,7 @@
 #define CONFIG_FILE  "SCRIBA.INI"
 #else
 #define CONFIG_ENVIR "SCRIBACONF"
-#define CONFIG_FILE  "/etc/scriba/basic.conf"
+#define CONFIG_FILE  "%%PREFIX%%/etc/scriba/basic.conf"
 #endif
 
 
