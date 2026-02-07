--- base.pro.orig	2020-04-16 18:47:44 UTC
+++ base.pro
@@ -25,7 +25,7 @@ exists(repoint.pri) {
 }
 
 include(bq-files.pri)
-include(vamp-plugin-sdk-files.pri)
+#include(vamp-plugin-sdk-files.pri)
 include(svcore/files.pri)
 include(capnp-regen.pri)
 
@@ -40,8 +40,8 @@ CLIENT_HEADERS=$$fromfile(piper-vamp-cpp/vamp-client/q
 for (file, BQ_SOURCES)       { SOURCES += $$file }
 for (file, BQ_HEADERS)       { HEADERS += $$file }
 
-for (file, VAMP_SOURCES)     { SOURCES += $$file }
-for (file, VAMP_HEADERS)     { HEADERS += $$file }
+#for (file, VAMP_SOURCES)     { SOURCES += $$file }
+#for (file, VAMP_HEADERS)     { HEADERS += $$file }
 
 for (file, DATAQUAY_SOURCES) { SOURCES += $$sprintf("dataquay/%1", $$file) }
 for (file, DATAQUAY_HEADERS) { HEADERS += $$sprintf("dataquay/%1", $$file) }
