--- src/common/z-file.c.orig	2021-02-18 22:29:46 UTC
+++ src/common/z-file.c
@@ -84,8 +84,9 @@ unsigned _cdecl _dos_getfileattr(const char *, unsigne
 /**
  * Player info
  */
-int player_uid;
-int player_egid;
+int player_uid = 0;
+int player_euid = 0;
+int player_egid = 0;
 
 
 
