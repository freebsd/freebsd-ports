--- arcread.cpp.orig	Sun Aug  1 01:55:38 2004
+++ arcread.cpp	Sun Aug  1 01:57:56 2004
@@ -540,6 +540,7 @@
 
 void Archive::ConvertUnknownHeader()
 {
+  int big5=0;
   if (NewLhd.UnpVer<20 && (NewLhd.FileAttr & 0x10))
     NewLhd.Flags|=LHD_DIRECTORY;
   if (NewLhd.HostOS>=HOST_MAX)
@@ -551,6 +552,16 @@
   }
   for (char *s=NewLhd.FileName;*s!=0;s=charnext(s))
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
     if (*s=='/' || *s=='\\')
       *s=CPATHDIVIDER;
 #if defined(_APPLE) && !defined(UNICODE_SUPPORTED)
