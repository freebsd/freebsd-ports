--- src/Utils/zip.c.orig	2018-07-05 04:29:44 UTC
+++ src/Utils/zip.c
@@ -378,9 +378,9 @@ extern int ZEXPORT zipOpenNewFileInZip (
     zi->ci.flag = 0;
     if ((level==8) || (level==9))
       zi->ci.flag |= 2;
-    if ((level==2))
+    if (level==2)
       zi->ci.flag |= 4;
-    if ((level==1))
+    if (level==1)
       zi->ci.flag |= 6;
 
     zi->ci.crc32 = 0;
