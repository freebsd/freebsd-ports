--- ../vcl/unx/source/gdi/native-msgbox/makefile.mk.orig	Sat Oct 19 19:22:47 2002
+++ ../vcl/unx/source/gdi/native-msgbox/makefile.mk	Sat Oct 19 19:23:03 2002
@@ -73,7 +73,7 @@
 
 # --- Files --------------------------------------------------------
 
-.IF "$(OS)$(CPU)"=="LINUXI"
+.IF "$(OS)$(CPU)"=="LINUXI" || "$(OS)$(CPU)"=="FREEBSDI"
 MSGBOX_GNOME=msgbox-gnome-linux-intel
 .ENDIF
 .IF "$(OS)$(CPU)"=="SOLARISS"
