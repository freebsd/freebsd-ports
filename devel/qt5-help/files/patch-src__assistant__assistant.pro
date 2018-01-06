Only enter the directories we want to build, otherwise we might fail due to
missing dependencies.

assistant/ is built in devel/qt5-assistant.

--- src/assistant/assistant.pro.orig	2016-06-10 14:46:48 UTC
+++ src/assistant/assistant.pro
@@ -2,18 +2,15 @@ TEMPLATE = subdirs
 
 SUBDIRS += \
            help \
-           assistant \
            qhelpgenerator \
            qcollectiongenerator \
            qhelpconverter
 
-assistant.depends = help
 qhelpgenerator.depends = help
 qcollectiongenerator.depends = help
 qhelpconverter.depends = help
 
 qtNomakeTools( \
-    assistant \
     qhelpgenerator \
     qcollectiongenerator \
     qhelpconverter \
