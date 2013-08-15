--- src/src.pro.orig	2012-01-04 13:11:46.000000000 -0800
+++ src/src.pro	2013-06-30 20:05:22.000000000 -0700
@@ -180,15 +180,15 @@
 QMAKE_EXTRA_TARGETS   +=   dox
 message(dox will be generated)
 }
-dox.path=/usr/share/doc/$$TARGET
+dox.path=%%DOCSDIR%%
 dox.files= $$PWD/documentation/html/*
 
- LIBS += -L/usr/lib64 \
+ LIBS += \
   -lfftw3 \
   -lasound \
   -lhamlib
 
-target.path=/usr/local/bin
-target.extra = strip $(TARGET); cp -f $(TARGET) $${PREFIX}/bin/$(TARGET)
+target.path=%%PREFIX%%/bin
+target.extra = strip $(TARGET); cp -f $(TARGET) %%PREFIX%%/bin/$(TARGET)
 INSTALLS +=target
 INSTALLS +=dox
