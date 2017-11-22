--- makerules/global/paths.mk.orig	2017-04-14 14:21:02 UTC
+++ makerules/global/paths.mk
@@ -2,6 +2,8 @@
 # project wide include and library searchpaths
 ##############################################
 
+LIBPATHS += -L${PREFIX}/lib
+LIBPATHS += -L${PREFIX}/lib/qt4
 LIBPATHS += -L./libs/local$(MULTI_SUFFIX)/lib
 
 INCLUDEPATHS += -I./libs/local$(MULTI_SUFFIX)/include
@@ -43,5 +44,7 @@
 
 ifdef PLAT_LINUX
 INCLUDEPATHS += -I./libs/local$(MULTI_SUFFIX)/include/mesa
-INCLUDEPATHS += -I/usr/include/qt4
+INCLUDEPATHS += -I${PREFIX}/include
+INCLUDEPATHS += -I${PREFIX}/include/qt4
+INCLUDEPATHS += -I${PREFIX}/include/freetype2
 endif #PLAT_LINUX
