--- src/plugins_3rdparty/variants/variants.pri.orig	2016-03-31 12:22:09 UTC
+++ src/plugins_3rdparty/variants/variants.pri
@@ -20,7 +20,7 @@ use_bundled_zlib() {
 win32 : LIBS += -lwsock32
 
 
-INCLUDEPATH += src ../../include /usr/include
+INCLUDEPATH += src ../../include
 INCLUDEPATH += ../../libs_3rdparty/samtools/src/samtools 
 INCLUDEPATH += ../../libs_3rdparty/samtools/src
 INCLUDEPATH += ../../libs_3rdparty/samtools/src/samtools/bcftools
