--- ./gqrx.pro.orig	2014-08-08 08:21:20.000000000 -0500
+++ ./gqrx.pro	2014-09-05 22:50:58.000000000 -0500
@@ -206,7 +206,6 @@
 
 unix:!macx {
     LIBS += -lboost_system$$BOOST_SUFFIX -lboost_program_options$$BOOST_SUFFIX
-    LIBS += -lrt  # need to include on some distros
 }
 
 macx {
