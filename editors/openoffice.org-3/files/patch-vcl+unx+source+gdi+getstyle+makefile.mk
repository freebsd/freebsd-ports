--- ../vcl/unx/source/gdi/getstyle/makefile.mk.orig	Sat Oct 19 19:11:55 2002
+++ ../vcl/unx/source/gdi/getstyle/makefile.mk	Sat Oct 19 19:11:58 2002
@@ -73,7 +73,7 @@
 
 # --- Files --------------------------------------------------------
 
-.IF "$(OS)$(CPU)"=="LINUXI"
+.IF "$(OS)$(CPU)"=="LINUXI" || "$(OS)$(CPU)"=="FREEBSDI"
 GETSTYLE_GNOME=getstyle-gnome-linux-intel
 .ENDIF
 .IF "$(OS)$(CPU)"=="SOLARISS"
