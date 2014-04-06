--- gqrx.pro.orig	2014-03-10 08:41:02.000000000 +0100
+++ gqrx.pro	2014-03-26 18:16:08.000000000 +0100
@@ -56,12 +56,12 @@
     #QMAKE_CFLAGS_DEBUG += '-g -O0'
 
     # Define version string (see below for releases)
-    VER = $$system(git describe --abbrev=8)
+    #VER = $$system(git describe --abbrev=8)
 
 } else {
     DEFINES += QT_NO_DEBUG
     DEFINES += QT_NO_DEBUG_OUTPUT
-    VER = $$system(git describe --abbrev=1)
+    #VER = $$system(git describe --abbrev=1)
 
     # Release binaries with gr bundled
     # QMAKE_RPATH & co won't work with origin
@@ -206,7 +206,7 @@
                  gnuradio-osmosdr
 
     LIBS += -lboost_system$$BOOST_SUFFIX -lboost_program_options$$BOOST_SUFFIX
-    LIBS += -lrt  # need to include on some distros
+    #LIBS += -lrt  # need to include on some distros
 }
 
 macx {
