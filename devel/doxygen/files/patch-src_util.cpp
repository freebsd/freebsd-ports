--- src/util.cpp.orig	2022-12-25 18:59:09 UTC
+++ src/util.cpp
@@ -30,6 +30,7 @@
 #include <cinttypes>
 #include <sstream>
 
+#include <sys/types.h>
 #include "md5.h"
 
 #include "regex.h"
@@ -3754,26 +3755,18 @@ QCString convertNameToFile(const QCString &name,bool a
     if (resultLen>=128) // prevent names that cannot be created!
     {
       // third algorithm based on MD5 hash
-      uchar md5_sig[16];
-      char sigStr[33];
-      MD5Buffer(result.data(),resultLen,md5_sig);
-      MD5SigToString(md5_sig,sigStr);
+      QCString sigStr(33);
+      MD5Data((const unsigned char *)result.data(),resultLen,sigStr.rawData());
       result=result.left(128-32)+sigStr;
     }
   }
   if (createSubdirs)
   {
-    int l1Dir=0,l2Dir=0;
-    int createSubdirsLevel = Config_getInt(CREATE_SUBDIRS_LEVEL);
-    int createSubdirsBitmaskL2 = (1<<createSubdirsLevel)-1;
-
     // compute md5 hash to determine sub directory to use
-    uchar md5_sig[16];
-    MD5Buffer(result.data(),result.length(),md5_sig);
-    l1Dir = md5_sig[14] & 0xf;
-    l2Dir = md5_sig[15] & createSubdirsBitmaskL2;
+    char md5[33];
+    MD5Data((const unsigned char *)result.data(),result.length(),md5);
 
-    result.prepend(QCString().sprintf("d%x/d%02x/",l1Dir,l2Dir));
+    result.prepend(QCString().sprintf("d%c/d%c%c/",md5[29],md5[30],md5[31]));
   }
   //printf("*** convertNameToFile(%s)->%s\n",qPrint(name),qPrint(result));
   return result;
@@ -7429,6 +7422,11 @@ QCString removeEmptyLines(const QCString &s)
 QCString removeEmptyLines(const QCString &s)
 {
   BufStr out(s.length()+1);
+  if (s.length()==0)
+  {
+    out.addChar('\0');
+    return out.data();
+  }
   const char *p=s.data();
   if (p)
   {
