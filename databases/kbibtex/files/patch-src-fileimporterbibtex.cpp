--- src/fileimporterbibtex.cpp.orig	2010-02-01 19:17:54.000000000 +0100
+++ src/fileimporterbibtex.cpp	2010-02-01 19:18:23.000000000 +0100
@@ -67,7 +67,7 @@
         {
             evaluateParameterComments( iconvHandle, m_lineBuffer );
 
-            char *raw = m_lineBuffer;
+            const char *raw = m_lineBuffer;
             char *enc = convertedLine;
             size_t encLen = m_lineBufferSize, rawLen = ( size_t )len;
             size_t result = iconv( iconvHandle, &raw, &rawLen, &enc, &encLen );
