--- glN64/Config_linux.cpp	2005-08-26 14:52:17.000000000 -0500
+++ glN64/Config_linux.cpp	2007-10-08 03:14:27.000000000 -0500
@@ -1,4 +1,3 @@
-#include <features.h>
 #include <dlfcn.h>
 #include <unistd.h>
 #include "../main/winlnxdefs.h"
@@ -35,29 +34,9 @@
 {
         static char path[PATH_MAX];
 
-#ifdef __USE_GNU
-        Dl_info info;
-        void *addr = (void*)GetPluginDir;
-        if(dladdr(addr, &info) != 0)
-        {
-	        strncpy(path, info.dli_fname, PATH_MAX);
-	        *(strrchr(path, '/')) = '\0';
-        }
-        else
-        {
-	        fprintf(stderr, "(WW) Couldn't get path of .so, trying to get emulator's path\n");
-#endif // __USE_GNU
-	        if(readlink("/proc/self/exe", path, PATH_MAX) == -1)
-	        {
-	                fprintf(stderr, "(WW) readlink() /proc/self/exe failed: %s\n", strerror(errno));
-		        path[0] = '.';
-		        path[1] = '\0';
-	        }
-	        *(strrchr(path, '/')) = '\0';
-	        strncat(path, "/plugins", PATH_MAX);
-#ifdef __USE_GNU
-	}
-#endif
+	strcpy(path, getenv("HOME"));
+	strncat(path, "/.mupen64/plugins", PATH_MAX);
+
         return path;
 }
 
