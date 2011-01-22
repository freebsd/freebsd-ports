--- arcread.cpp.orig	2011-01-04 20:28:47.000000000 +0800
+++ arcread.cpp	2011-01-21 22:59:22.000000000 +0800
@@ -629,6 +629,7 @@
 
 void Archive::ConvertUnknownHeader()
 {
+  int big5=0;
   if (NewLhd.UnpVer<20 && (NewLhd.FileAttr & 0x10))
     NewLhd.Flags|=LHD_DIRECTORY;
   if (NewLhd.HostOS>=HOST_MAX)
@@ -640,6 +641,16 @@
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
