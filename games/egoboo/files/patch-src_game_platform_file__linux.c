--- src/game/platform/file_linux.c.orig	2021-01-29 16:26:24 UTC
+++ src/game/platform/file_linux.c
@@ -33,7 +33,7 @@
 #include <glob.h>
 #include <sys/types.h>
 #include <sys/stat.h>
-#include <sys/dir.h>
+#include <sys/syslimits.h>
 #include "egoboo_mem.h"
 
 //--------------------------------------------------------------------------------------------
@@ -75,8 +75,8 @@ void sys_fs_init()
     // .rpm or .deb package.
 
-    strncpy( linux_configPath, PREFIX "/etc/egoboo-2.x",         SDL_arraysize( linux_configPath ) );
-    strncpy( linux_binaryPath, PREFIX "/games/",                  SDL_arraysize( linux_binaryPath ) );
-    strncpy( linux_dataPath,   PREFIX "/share/games/egoboo-2.x", SDL_arraysize( linux_dataPath ) );
+    strncpy( linux_configPath, PREFIX "/etc/egoboo",         SDL_arraysize( linux_configPath ) );
+    strncpy( linux_binaryPath, PREFIX "/bin/",                  SDL_arraysize( linux_binaryPath ) );
+    strncpy( linux_dataPath,   PREFIX "/share/egoboo", SDL_arraysize( linux_dataPath ) );
 #else
     // these are read-only directories
     strncpy( linux_configPath, "/etc/egoboo-2.x/",         SDL_arraysize( linux_configPath ) );
