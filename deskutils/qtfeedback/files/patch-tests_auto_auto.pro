--- tests/auto/auto.pro.orig	2018-09-03 09:16:11 UTC
+++ tests/auto/auto.pro
@@ -2,10 +2,8 @@ TEMPLATE = subdirs
 SUBDIRS += \
     qfeedbackactuator \
     qfeedbackhapticseffect \
-    qfeedbackplugin \
     qfeedbackmmk \
     qdeclarativefeedback \
-    cmake
 
 !qtHaveModule(qml): SUBDIRS -= \
     qdeclarativefeedback \
