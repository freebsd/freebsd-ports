--- src/appwin_pub.h.orig	2013-10-03 09:22:51 UTC
+++ src/appwin_pub.h
@@ -55,7 +55,7 @@ class TopWinPub: public FXObject { (public)
   static void ParseCommands(FXString &commands);
   static FXMainWindow* instantiate(FXApp*a);
   static void create();
-  static FXbool close(FXbool notify=FALSE);
+  static FXbool close(FXbool notify=false);
   static FXMainWindow* instance();
   static void DumpLexers();
   static void FindText(const char*searchfor, FXuint searchmode, bool forward);
