--- arcread.cpp.orig	2017-04-28 17:28:45 UTC
+++ arcread.cpp
@@ -1308,6 +1308,7 @@ void Archive::ConvertAttributes()
 
 void Archive::ConvertFileHeader(FileHeader *hd)
 {
+  int big5=0;
   if (Format==RARFMT15 && hd->UnpVer<20 && (hd->FileAttr & 0x10))
     hd->Dir=true;
   if (hd->HSType==HSYS_UNKNOWN)
@@ -1323,6 +1324,16 @@ void Archive::ConvertFileHeader(FileHead
 
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
