--- src/fileexporterbibtex.cpp.orig	2010-02-01 19:08:49.000000000 +0100
+++ src/fileexporterbibtex.cpp	2010-02-01 19:17:03.000000000 +0100
@@ -258,7 +258,7 @@
         for ( i = 0; i < encodeMaxTries && utf8datasize != 0; ++i )
         {
             QCString utf8 = workingText.utf8();
-            char *utf8data = utf8.data();
+            const char *utf8data = utf8.data();
             utf8datasize = utf8.length();
             char *outputdata = m_iconvBuffer;
             size_t outputdatasize = m_iconvBufferSize;
