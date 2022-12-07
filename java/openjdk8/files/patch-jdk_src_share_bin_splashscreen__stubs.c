--- jdk/src/share/bin/splashscreen_stubs.c.orig	2022-07-31 16:21:00 UTC
+++ jdk/src/share/bin/splashscreen_stubs.c
@@ -61,11 +61,11 @@ int     DoSplashLoadMemory(void* pdata, int size) {
 #define INVOKEV(name) _INVOKE(name, ,;)
 
 int     DoSplashLoadMemory(void* pdata, int size) {
-    INVOKE(SplashLoadMemory, NULL)(pdata, size);
+    INVOKE(SplashLoadMemory, 0)(pdata, size);
 }
 
 int     DoSplashLoadFile(const char* filename) {
-    INVOKE(SplashLoadFile, NULL)(filename);
+    INVOKE(SplashLoadFile, 0)(filename);
 }
 
 void    DoSplashInit(void) {
