--- src/memberdef.cpp.orig	2022-12-26 12:52:22 UTC
+++ src/memberdef.cpp
@@ -17,6 +17,7 @@
 #include <stdio.h>
 #include <assert.h>
 #include <mutex>
+#include <sys/types.h>
 
 #include "md5.h"
 #include "memberdef.h"
@@ -4149,10 +4150,8 @@ void MemberDefImpl::setAnchor()
   }
 
   // convert to md5 hash
-  uchar md5_sig[16];
-  char sigStr[33];
-  MD5Buffer(memAnchor.data(),memAnchor.length(),md5_sig);
-  MD5SigToString(md5_sig,sigStr);
+  QCString sigStr(33);
+  MD5Data((const unsigned char *)memAnchor.data(),memAnchor.length(),sigStr.rawData());
   m_impl->anc = QCString("a")+sigStr;
 }
 
