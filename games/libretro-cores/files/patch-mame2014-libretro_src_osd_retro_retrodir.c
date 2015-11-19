--- mame2014-libretro/src/osd/retro/retrodir.c.orig	2015-11-04 17:31:20 UTC
+++ mame2014-libretro/src/osd/retro/retrodir.c
@@ -37,10 +37,10 @@ typedef struct stat sdl_stat;
 #define sdl_readdir readdir
 #define sdl_stat_fn stat
 #else
-typedef struct dirent64 sdl_dirent;
-typedef struct stat64 sdl_stat;
-#define sdl_readdir readdir64
-#define sdl_stat_fn stat64
+typedef struct dirent sdl_dirent;
+typedef struct stat sdl_stat;
+#define sdl_readdir readdir
+#define sdl_stat_fn stat
 #endif
 
 #define HAS_DT_XXX defined(SDLMAME_LINUX) || defined(SDLMAME_BSD) || defined(__MACH__)
