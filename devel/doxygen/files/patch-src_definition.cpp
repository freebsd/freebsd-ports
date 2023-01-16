--- src/definition.cpp.orig	2022-12-25 19:21:45 UTC
+++ src/definition.cpp
@@ -7,6 +7,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <assert.h>
+#include <sys/types.h>
 
 #include "md5.h"
 #include "regex.h"
@@ -417,13 +418,11 @@ bool DefinitionImpl::_docsAlreadyAdded(const QCString 
 
 bool DefinitionImpl::_docsAlreadyAdded(const QCString &doc,QCString &sigList)
 {
-  uchar md5_sig[16];
-  char sigStr[33];
+  QCString sigStr(33);
   // to avoid mismatches due to differences in indenting, we first remove
   // double whitespaces...
   QCString docStr = doc.simplifyWhiteSpace();
-  MD5Buffer(docStr.data(),docStr.length(),md5_sig);
-  MD5SigToString(md5_sig,sigStr);
+  MD5Data((const unsigned char *)docStr.data(),docStr.length(),sigStr.rawData());
   //printf("%s:_docsAlreadyAdded doc='%s' sig='%s' docSigs='%s'\n",
   //    qPrint(name()),qPrint(doc),qPrint(sigStr),qPrint(sigList));
   if (sigList.find(sigStr)==-1) // new docs, add signature to prevent re-adding it
