--- src/export.cpp.orig	2014-07-24 14:11:00.000000000 +0200
+++ src/export.cpp	2014-07-24 14:11:00.000000000 +0200
@@ -464,7 +464,7 @@
       }
       // start to write PDF file here (PDF1.4Ref(p63))
       // ASCII>127 characters to indicate binary-possible stream
-      oT->write("%PDF-1.3\n%Çì¢\n");
+      oT->write("%PDF-1.3\n%\267\276\255\252\n");
       styleCurrent = STYLE_DEFAULT;
 
       // build objects for font resources; note that font objects are
