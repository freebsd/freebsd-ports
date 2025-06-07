--- internfile/mh_xslt.cpp.orig	2022-01-14 09:19:06 UTC
+++ internfile/mh_xslt.cpp
@@ -65,7 +65,7 @@ class FileScanXML : public FileScanDo { (public)
     xmlDocPtr getDoc() {
         int ret;
         if ((ret = xmlParseChunk(ctxt, nullptr, 0, 1))) {
-            xmlError *error = xmlGetLastError();
+            const xmlError *error = xmlGetLastError();
             LOGERR("FileScanXML: final xmlParseChunk failed with error " <<
                    ret << " error: " <<
                    (error ? error->message :
@@ -94,7 +94,7 @@ class FileScanXML : public FileScanDo { (public)
         }            
         int ret;
         if ((ret = xmlParseChunk(ctxt, buf, cnt, 0))) {
-            xmlError *error = xmlGetLastError();
+            const xmlError *error = xmlGetLastError();
             LOGERR("FileScanXML: xmlParseChunk failed with error " <<
                    ret << " for [" << buf << "] error " <<
                    (error ? error->message :
