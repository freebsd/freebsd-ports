--- ../vcl/unx/source/gdi/native-msgbox/makefile.mk.orig	Thu Feb 20 18:29:08 2003
+++ ../vcl/unx/source/gdi/native-msgbox/makefile.mk	Wed Mar  5 19:25:00 2003
@@ -75,8 +75,12 @@
 
 HASGNOME2=
 
-.IF "$(OS)$(CPU)"=="LINUXI" || "$(OS)$(CPU)"=="FREEBSDI"
+.IF "$(OS)$(CPU)"=="LINUXI"
 MSGBOX_GNOME=msgbox-gnome-linux-intel
+HASGNOME2=TRUE
+.ENDIF
+.IF "$(OS)$(CPU)"=="FREEBSDI"
+MSGBOX_GNOME=msgbox-gnome-freebsd-intel
 HASGNOME2=TRUE
 .ENDIF
 .IF "$(OS)$(CPU)"=="SOLARISS"
