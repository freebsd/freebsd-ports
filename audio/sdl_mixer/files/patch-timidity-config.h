--- timidity/config.h.orig	2012-01-16 02:01:05.000000000 +0400
+++ timidity/config.h	2012-12-04 00:12:31.000000000 +0400
@@ -161,7 +161,7 @@
 /* You could specify a complete path, e.g. "/etc/timidity.cfg", and
    then specify the library directory in the configuration file. */
 #define CONFIG_FILE	"timidity.cfg"
-#define CONFIG_FILE_ETC "/etc/timidity.cfg"
+#define CONFIG_FILE_ETC "%%CONFIG_FILE%%"
 
 #if defined(__WIN32__) || defined(__OS2__)
 #define DEFAULT_PATH	"C:\\TIMIDITY"
