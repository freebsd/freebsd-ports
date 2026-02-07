--- timidity/config.h.orig	2012-01-15 22:01:05 UTC
+++ timidity/config.h
@@ -161,7 +161,7 @@ typedef char int8;
 /* You could specify a complete path, e.g. "/etc/timidity.cfg", and
    then specify the library directory in the configuration file. */
 #define CONFIG_FILE	"timidity.cfg"
-#define CONFIG_FILE_ETC "/etc/timidity.cfg"
+#define CONFIG_FILE_ETC "%%CONFIG_FILE%%"
 
 #if defined(__WIN32__) || defined(__OS2__)
 #define DEFAULT_PATH	"C:\\TIMIDITY"
