--- gqrx.pro.orig	2020-01-27 20:45:16 UTC
+++ gqrx.pro
@@ -290,7 +290,7 @@ INCPATH += src/
 
 unix:!macx {
     LIBS += -lboost_system$$BOOST_SUFFIX -lboost_program_options$$BOOST_SUFFIX
-    LIBS += -lrt  # need to include on some distros
+    LIBS += -llog4cpp
 }
 
 macx {
