--- arcread.cpp.orig	2013-12-01 16:10:14.000000000 +0800
+++ arcread.cpp	2014-02-04 09:23:21.669710373 +0800
@@ -1272,6 +1272,7 @@
 
 void Archive::ConvertFileHeader(FileHeader *hd)
 {
+  int big5=0;
   if (Format==RARFMT15 && hd->UnpVer<20 && (hd->FileAttr & 0x10))
     hd->Dir=true;
   if (hd->HSType==HSYS_UNKNOWN)
@@ -1282,6 +1283,16 @@
 
   for (wchar *s=hd->FileName;*s!=0;s++)
   {
+    if (big5==1) /* skip Big5 second byte */
+    {
+      big5=0;
+      continue;
+    }
+    if ((byte)*s>127) /* Big5 first byte */
+    {
+      big5=1;
+      continue;
+    }
 #ifdef _UNIX
     // Backslash is the invalid character for Windows file headers,
     // but it can present in Unix file names extracted in Unix.
