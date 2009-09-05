--- src/fingerprint/fingerprint.pro.orig	2009-06-05 03:41:27.000000000 +1100
+++ src/fingerprint/fingerprint.pro	2009-09-02 23:24:41.000000000 +1100
@@ -20,8 +20,7 @@
         INCLUDEPATH += /opt/local/include
     }
     else{
-        CONFIG += link_pkgconfig
-        PKGCONFIG += fftw3f samplerate
+    LIBS += -lsamplerate -lfftw3f
     }
 }
 
