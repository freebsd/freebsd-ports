--- libopenjpeg1.pc.cmake~	2012-02-07 04:49:55.000000000 -0600
+++ libopenjpeg1.pc.cmake	2012-04-07 17:13:24.589503254 -0500
@@ -1,8 +1,8 @@
 prefix=@CMAKE_INSTALL_PREFIX@
-bindir=@OPENJPEG_INSTALL_BIN_DIR@
-datadir=@OPENJPEG_INSTALL_DATA_DIR@
-libdir=@OPENJPEG_INSTALL_LIB_DIR@
-includedir=@OPENJPEG_INSTALL_INCLUDE_DIR@
+bindir=${prefix}/@OPENJPEG_INSTALL_BIN_DIR@
+datadir=${prefix}/@OPENJPEG_INSTALL_DATA_DIR@
+libdir=${prefix}/@OPENJPEG_INSTALL_LIB_DIR@
+includedir=${prefix}/@OPENJPEG_INSTALL_INCLUDE_DIR@
 
 Name: openjpeg
 Description: JPEG2000 files library
