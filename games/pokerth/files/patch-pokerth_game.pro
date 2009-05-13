--- pokerth_game.pro.orig	2009-05-03 21:19:24.000000000 +0200
+++ pokerth_game.pro	2009-05-10 13:48:21.535041464 +0200
@@ -357,8 +357,7 @@
     # QMAKE_CXXFLAGS += -ffunction-sections -fdata-sections
     # QMAKE_LFLAGS += -Wl,--gc-sections
     LIBPATH += lib
-    LIB_DIRS = $${PREFIX}/lib \
-        $${PREFIX}/lib64
+    LIB_DIRS = $${PREFIX}/lib
     BOOST_FS = boost_filesystem \
         boost_filesystem-mt
     BOOST_THREAD = boost_thread \
