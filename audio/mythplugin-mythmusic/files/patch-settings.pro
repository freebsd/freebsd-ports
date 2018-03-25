Prevent linking to unneccessary libraries

--- settings.pro.orig	2018-02-25 02:52:28 UTC
+++ settings.pro
@@ -34,6 +34,7 @@ QMAKE_CXXFLAGS += $$ARCHFLAGS
 QMAKE_CXXFLAGS += $$CONFIG_DIRECTFB_CXXFLAGS
 QMAKE_CXXFLAGS_SHLIB = -DPIC -fPIC
 QMAKE_CXXFLAGS += $$ECXXFLAGS
+QMAKE_LFLAGS +=	-Wl,--as-needed
 
 profile:!win32:!macx:CONFIG += debug
 
