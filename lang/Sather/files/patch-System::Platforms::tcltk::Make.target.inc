--- System/Platforms/tcltk/Make.target.inc.orig	Thu May  2 17:21:52 2002
+++ System/Platforms/tcltk/Make.target.inc	Thu May  2 17:21:35 2002
@@ -1,2 +1,2 @@
-TCL_LIB_NAME = $(shell if [ -e /usr/lib/libtcl8.0.so ] ; then echo "tcl8.0" ; else echo "tcl"; fi)
-TK_LIB_NAME = $(shell if [ -e /usr/lib/libtk8.0.so ] ; then echo "tk8.0" ; else echo "tk"; fi)
+TCL_LIB_NAME = tcl83
+TK_LIB_NAME = tk83
