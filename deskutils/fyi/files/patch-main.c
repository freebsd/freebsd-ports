--- main.c.orig	2024-08-09 08:36:50 UTC
+++ main.c
@@ -14,7 +14,7 @@
 
 #include <sys/stat.h>
 
-#include <dbus-1.0/dbus/dbus.h>
+#include <dbus/dbus.h>
 
 #include "version.h"
 
@@ -365,7 +365,7 @@ main(int argc, char *const *argv)
     };
 
     const char *progname = argv[0];
-    const char *app_id = program_invocation_name;
+    const char *app_id = progname;
     const char *icon = NULL;
     const char *image_data_file = NULL;
     const char *category = NULL;
