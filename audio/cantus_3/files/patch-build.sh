--- build.sh.orig	Thu Apr 22 04:26:52 2004
+++ build.sh	Tue May 18 14:57:02 2004
@@ -165,11 +165,7 @@
 INST_LOCALEDIR="$INST_PREFIX/share/locale"
 INST_PIXMAPDIR="$INST_PREFIX/lib/$EXECUTABLE"
 INST_DOCDIR="$INST_PREFIX/doc/$EXECUTABLE"
-if [ -d "/usr/share/gnome/help/" ]; then
-  INST_GNOMEDOCDIR="/usr/share/gnome/help/$EXECUTABLE/C"
-else
-  INST_GNOMEDOCDIR="/usr/local/share/gnome/help/$EXECUTABLE/C"
-fi
+INST_GNOMEDOCDIR="$INST_PREFIX/share/gnome/help/$EXECUTABLE/C"
 
 # Preprocessor macros:
 MACROS="PACKAGE_LIB_DIR=$INST_LIBDIR/\
