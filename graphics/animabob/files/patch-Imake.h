--- Imake.h~	Mon Jul 22 07:50:48 2002
+++ Imake.h	Mon Jul 22 07:52:51 2002
@@ -3,9 +3,9 @@
 XCOMM package binaries and reference pages installed.
 XCOMM
 
-INSTALL_BIN	= /usr/local/X11/bin
-INSTALL_MAN	= /usr/local/X11/man/man1
-INSTALL_DEF	= /usr/local/X11/lib/X11/app-defaults
+INSTALL_BIN	= ${PREFIX}/bin
+INSTALL_MAN	= ${PREFIX}/man/man1
+INSTALL_DEF	= ${PREFIX}/lib/X11/app-defaults
 
 XCOMM 
 XCOMM If you are using Mesa3D as your OpenGL implementation, and your libraries
@@ -14,7 +14,7 @@
 XCOMM OpenGL libraries.
 XCOMM
 
-XCOMM GLPATH	= -L/usr/local/lib
+GLPATH	= -L${X11BASE}/lib
 
 XCOMM
 XCOMM -------------------- DO NOT EDIT BELOW THIS LINE ------------------------
