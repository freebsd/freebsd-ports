Only enter the directories we want to build, otherwise we might fail due to
missing dependencies.

assistant/ is built in devel/qt5-assistant.

--- src/assistant/assistant.pro.orig	2019-01-15 05:20:10 UTC
+++ src/assistant/assistant.pro
@@ -3,7 +3,6 @@ TEMPLATE = subdirs
 
 SUBDIRS += \
            help \
-           assistant \
            qhelpgenerator \
            qcollectiongenerator
 
@@ -11,7 +10,6 @@ assistant.depends = help
 qhelpgenerator.depends = help
 
 qtNomakeTools( \
-    assistant \
     qhelpgenerator \
     qcollectiongenerator \
 )
