--- ../vcl/unx/source/gdi/getstyle/makefile.mk.orig	Thu Feb 20 18:28:59 2003
+++ ../vcl/unx/source/gdi/getstyle/makefile.mk	Wed Mar  5 19:23:22 2003
@@ -78,6 +78,10 @@
 GETSTYLE_GNOME=getstyle-gnome-linux-intel
 HASGNOME2=TRUE
 .ENDIF
+.IF "$(OS)$(CPU)"=="FREEBSDI"
+GETSTYLE_GNOME=getstyle-gnome-freebsd-intel
+HASGNOME2=TRUE
+.ENDIF
 .IF "$(OS)$(CPU)"=="SOLARISS"
 GETSTYLE_GNOME=getstyle-gnome-solaris-sparc
 HASGNOME2=TRUE
