--- gui/keymap.cc.orig	2025-02-25 01:36:13 UTC
+++ gui/keymap.cc
@@ -96,7 +96,7 @@ bx_keymap_c::~bx_keymap_c(void)
     keymapCount = 0;
 }
 
-#if defined(WIN32) || defined(__ANDROID__)
+#if defined(WIN32) || defined(__ANDROID__) || defined(__FreeBSD__)
 char* basename(char *path)
 {
   char *ptr;
