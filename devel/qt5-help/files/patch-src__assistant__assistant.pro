Only enter the directories we want to build, otherwise we might fail due to
missing dependencies.

assistant/ is built in devel/qt5-assistant.

--- src/assistant/assistant.pro.orig	2020-08-24 09:20:54 UTC
+++ src/assistant/assistant.pro
@@ -8,7 +8,6 @@ TEMPLATE = subdirs
 
 SUBDIRS += \
            help \
-           assistant \
            qhelpgenerator \
            qcollectiongenerator
 
@@ -16,7 +15,6 @@ assistant.depends = help
 qhelpgenerator.depends = help
 
 qtNomakeTools( \
-    assistant \
     qhelpgenerator \
     qcollectiongenerator \
 )
