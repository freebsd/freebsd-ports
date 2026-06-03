--- src/libdk4c/dk4fs.c.orig	2026-03-28 18:46:03 UTC
+++ src/libdk4c/dk4fs.c
@@ -134,7 +134,7 @@ dk4fs_check_regular_file(
 #if DK4_ON_WINDOWS && (DK4_WIN_AVOID_CRT || DK4_WIN_DENY_CRT)
 #if DK4_CHAR_SIZE > 1
   WIN32_FIND_DATAW	ffdata;
-#els
+#else
   WIN32_FIND_DATAA	ffdata;
 #endif
   HANDLE		ha;
