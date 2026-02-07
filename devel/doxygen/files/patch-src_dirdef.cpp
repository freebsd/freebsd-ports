--- src/dirdef.cpp.orig	2022-12-18 12:21:42 UTC
+++ src/dirdef.cpp
@@ -14,6 +14,7 @@
  */
 
 #include <algorithm>
+#include <sys/types.h>
 
 #include "dirdef.h"
 #include "md5.h"
@@ -181,10 +182,8 @@ static QCString encodeDirName(const QCString &anchor)
 static QCString encodeDirName(const QCString &anchor)
 {
   // convert to md5 hash
-  uchar md5_sig[16];
-  char sigStr[33];
-  MD5Buffer(anchor.data(),anchor.length(),md5_sig);
-  MD5SigToString(md5_sig,sigStr);
+  QCString sigStr(33);
+  MD5Data((const unsigned char *)anchor.data(),anchor.length(),sigStr.rawData());
   return sigStr;
 
   // old algorithm
