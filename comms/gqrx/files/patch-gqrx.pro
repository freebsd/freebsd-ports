--- gqrx.pro.orig	2020-11-01 13:40:49 UTC
+++ gqrx.pro
@@ -294,7 +294,7 @@ INCPATH += src/
 
 unix:!macx {
     LIBS += -lboost_system$$BOOST_SUFFIX
-    LIBS += -lrt  # need to include on some distros
+    LIBS += -llog4cpp
 }
 
 macx {
