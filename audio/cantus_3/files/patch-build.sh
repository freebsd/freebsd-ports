--- build.sh.orig	Wed Apr 21 20:26:52 2004
+++ build.sh	Mon Mar  7 12:11:44 2005
@@ -164,12 +164,8 @@
 INST_LIBDIR="$INST_PREFIX/lib/$EXECUTABLE"
 INST_LOCALEDIR="$INST_PREFIX/share/locale"
 INST_PIXMAPDIR="$INST_PREFIX/lib/$EXECUTABLE"
-INST_DOCDIR="$INST_PREFIX/doc/$EXECUTABLE"
-if [ -d "/usr/share/gnome/help/" ]; then
-  INST_GNOMEDOCDIR="/usr/share/gnome/help/$EXECUTABLE/C"
-else
-  INST_GNOMEDOCDIR="/usr/local/share/gnome/help/$EXECUTABLE/C"
-fi
+INST_DOCDIR="$INST_PREFIX/share/doc/$EXECUTABLE"
+INST_GNOMEDOCDIR="$INST_PREFIX/share/gnome/help/$EXECUTABLE/C"
 
 # Preprocessor macros:
 MACROS="PACKAGE_LIB_DIR=$INST_LIBDIR/\
