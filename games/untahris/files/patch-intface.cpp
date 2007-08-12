--- intface.cpp.orig	Wed May  2 02:41:32 2007
+++ intface.cpp	Thu Aug  9 03:04:09 2007
@@ -45,7 +45,7 @@
     SDL_Quit();
     }
 
-  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 8000) != 0)
+  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 8192) != 0)
     printf("Failed to initialize audio.\n");
   else {
     Mix_AllocateChannels(16);
@@ -653,7 +653,7 @@
   Ic(icBazooka).fillWith("0", d.Res);
   Ic(icBazooka).gradFill(d.Res*4/8-1, 0, d.Res*4/8, d.Res*3/4, 0x80FFFFFF, 0xFFFFFFFF);
 
-  char buf[64];
+  char buf[1024];
   sprintf(buf, "graph%d.unt", d.Res);
   FILE *f = fopen(buf, "rt");
   if(f) {
