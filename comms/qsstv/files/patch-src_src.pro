--- ./src/src.pro.orig	2012-01-04 21:11:46.000000000 +0000
+++ ./src/src.pro	2014-01-07 16:53:34.793505558 +0000
@@ -9,7 +9,6 @@
 
 QMAKE_CXXFLAGS_DEBUG -= -O2
 QMAKE_CXXFLAGS_DEBUG += -g3 -O0
-QMAKE_STRIP = echo
 VERSION=7.1.7
 
 message(directory2 $$PWD)
@@ -180,15 +179,14 @@
 QMAKE_EXTRA_TARGETS   +=   dox
 message(dox will be generated)
 }
-dox.path=/usr/share/doc/$$TARGET
+dox.path=$$PREFIX/share/doc/$$TARGET
 dox.files= $$PWD/documentation/html/*
 
- LIBS += -L/usr/lib64 \
+ LIBS += \
   -lfftw3 \
   -lasound \
   -lhamlib
 
-target.path=/usr/local/bin
-target.extra = strip $(TARGET); cp -f $(TARGET) $${PREFIX}/bin/$(TARGET)
+target.path=$$PREFIX/bin
 INSTALLS +=target
 INSTALLS +=dox
