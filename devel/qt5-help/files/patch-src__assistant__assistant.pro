Only enter the directories we want to build, otherwise we might fail due to
missing dependencies.

assistant/ is built in devel/qt5-assistant.

--- src/assistant/assistant.pro.orig	2018-10-12 10:07:26 UTC
+++ src/assistant/assistant.pro
@@ -3,13 +3,11 @@ TEMPLATE = subdirs
 
 SUBDIRS += \
            help \
-           assistant \
            qhelpgenerator
 
 assistant.depends = help
 qhelpgenerator.depends = help
 
 qtNomakeTools( \
-    assistant \
     qhelpgenerator \
 )
