--- ../vcl/unx/source/gdi/getstyle/makefile.mk.orig	Thu Feb 20 17:28:59 2003
+++ ../vcl/unx/source/gdi/getstyle/makefile.mk	Tue Mar 11 16:43:43 2003
@@ -78,6 +78,12 @@
 GETSTYLE_GNOME=getstyle-gnome-linux-intel
 HASGNOME2=TRUE
 .ENDIF
+.IF "$_(HAS_GNOME2)"=="TRUE"
+.IF "$(OS)$(CPU)"=="FREEBSDI"
+GETSTYLE_GNOME=getstyle-gnome-freebsd-intel
+HASGNOME2=TRUE
+.ENDIF
+.ENDIF
 .IF "$(OS)$(CPU)"=="SOLARISS"
 GETSTYLE_GNOME=getstyle-gnome-solaris-sparc
 HASGNOME2=TRUE
