--- ../vcl/unx/source/gdi/native-msgbox/makefile.mk.orig	Thu Feb 20 17:29:08 2003
+++ ../vcl/unx/source/gdi/native-msgbox/makefile.mk	Tue Mar 11 16:39:29 2003
@@ -75,9 +75,15 @@
 
 HASGNOME2=
 
-.IF "$(OS)$(CPU)"=="LINUXI" || "$(OS)$(CPU)"=="FREEBSDI"
+.IF "$(OS)$(CPU)"=="LINUXI"
 MSGBOX_GNOME=msgbox-gnome-linux-intel
 HASGNOME2=TRUE
+.ENDIF
+.IF "$(_HAS_GNOME2)"=="TRUE"
+.IF "$(OS)$(CPU)"=="FREEBSDI"
+MSGBOX_GNOME=msgbox-gnome-freebsd-intel
+HASGNOME2=TRUE
+.ENDIF
 .ENDIF
 .IF "$(OS)$(CPU)"=="SOLARISS"
 MSGBOX_GNOME=msgbox-gnome-solaris-sparc
