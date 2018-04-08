--- src/designer/src/lib/lib.pro.orig	2018-01-11 05:19:33 UTC
+++ src/designer/src/lib/lib.pro
@@ -1,7 +1,8 @@
 TARGET = QtDesigner
 MODULE = designer
 
-QT = core-private gui-private widgets-private xml uiplugin
+QT = core-private gui-private widgets-private xml
+QT_PRIVATE = uiplugin
 
 DEFINES += \
     QDESIGNER_SDK_LIBRARY \
