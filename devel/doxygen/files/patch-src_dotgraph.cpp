--- src/dotgraph.cpp.orig	2022-12-25 19:00:20 UTC
+++ src/dotgraph.cpp
@@ -15,6 +15,7 @@
 
 #include <mutex>
 #include <regex>
+#include <sys/types.h>
 
 #include "config.h"
 #include "doxygen.h"
@@ -155,12 +156,9 @@ bool DotGraph::prepareDotFile()
     term("Output dir %s does not exist!\n", m_dir.path().c_str());
   }
 
-  char sigStr[33];
-  uchar md5_sig[16];
-  // calculate md5
-  MD5Buffer(m_theGraph.data(), m_theGraph.length(), md5_sig);
-  // convert result to a string
-  MD5SigToString(md5_sig, sigStr);
+  QCString sigStr(33);
+  // calculate md5 and convert result to a string
+  MD5Data((const unsigned char*)m_theGraph.data(), m_theGraph.length(), sigStr.rawData());
 
   // already queued files are processed again in case the output format has changed
 
