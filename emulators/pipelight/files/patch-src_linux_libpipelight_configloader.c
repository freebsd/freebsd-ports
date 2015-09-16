--- src/linux/libpipelight/configloader.c.orig	2015-01-11 04:48:05 UTC
+++ src/linux/libpipelight/configloader.c
@@ -46,6 +46,7 @@
 #include <string>								// for std::string
 #include <map>									// for std::map
 #include <dlfcn.h>
+#include <errno.h>
 
 #include "common/common.h"
 #include "configloader.h"
@@ -663,4 +664,4 @@ bool loadPluginInformation(){
 err:
 	fclose(file);
 	return false;
-}
\ No newline at end of file
+}
