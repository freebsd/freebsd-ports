--- plugins/CuePack/CuePack.cpp.orig	2012-06-28 14:58:11 UTC
+++ plugins/CuePack/CuePack.cpp
@@ -55,7 +55,7 @@ void CuePack::DumpCue(const string& dir,
     string genre;
     int year = -1;
 
-    char* data = NULL;
+    const char* data = NULL;
     Cdtext* cdt = cd_get_cdtext(cd);
     Rem* rem = cd_get_rem(cd);
 
