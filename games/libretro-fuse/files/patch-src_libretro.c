--- src/libretro.c.orig	2020-02-07 11:00:48 UTC
+++ src/libretro.c
@@ -476,7 +476,7 @@ static int get_joystick(unsigned device)
 #ifdef GIT_VERSION
 static char version[] = PACKAGE_VERSION " " GIT_VERSION;
 #else
-const char *fuse_githash;
+extern const char *fuse_githash;
 static char version[] = PACKAGE_VERSION " .......";
 #endif
 
