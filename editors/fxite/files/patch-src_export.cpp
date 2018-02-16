--- src/export.cpp.orig	2013-10-03 09:22:51 UTC
+++ src/export.cpp
@@ -73,7 +73,7 @@ void SaveToHTML(SciDoc*sci, FILE *fp )
   fprintf(fp, "<title>%s</title>\n", FXPath::name(sci->Filename()).text());
   // Probably not used by robots, but making a little advertisement for those looking
   // at the source code doesn't hurt...
-  fputs("<meta name=\"Generator\" content=\""APP_NAME" HTML export\" />\n", fp);
+  fputs("<meta name=\"Generator\" content=\"" APP_NAME " HTML export\" />\n", fp);
   if ( sci->sendMessage(SCI_GETCODEPAGE,0,0) == SC_CP_UTF8) {
     fputs("<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />\n", fp);
   }
@@ -464,7 +464,7 @@ void SaveToPDF(SciDoc*sci,  FILE *fp)
       }
       // start to write PDF file here (PDF1.4Ref(p63))
       // ASCII>127 characters to indicate binary-possible stream
-      oT->write("%PDF-1.3\n%Çì¢\n");
+      oT->write("%PDF-1.3\n%\267\276\255\252\n");
       styleCurrent = STYLE_DEFAULT;
 
       // build objects for font resources; note that font objects are
