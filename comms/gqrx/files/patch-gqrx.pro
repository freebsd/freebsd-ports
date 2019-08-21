--- gqrx.pro.orig	2018-05-16 23:32:13.000000000 +0200
+++ gqrx.pro	2019-08-20 22:57:38.783794000 +0200
@@ -267,7 +267,7 @@
 
 unix:!macx {
     LIBS += -lboost_system$$BOOST_SUFFIX -lboost_program_options$$BOOST_SUFFIX
-    LIBS += -lrt  # need to include on some distros
+    LIBS += -llog4cpp
 }
 
 macx {
