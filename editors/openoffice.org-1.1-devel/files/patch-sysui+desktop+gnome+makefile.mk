--- ../sysui/desktop/gnome/makefile.mk.orig	Sun Jun  1 14:58:28 2003
+++ ../sysui/desktop/gnome/makefile.mk	Sun Jun  1 14:58:30 2003
@@ -78,7 +78,9 @@
 APP1TARGET=$(TARGET)
 APP1OBJS=$(OBJFILES)
 APP1LIBS=
+.IF "$(OS)"!="FREEBSD"
 APP1STDLIBS=-ldl
+.ENDIF
 
 # menu launcher files
 LAUNCHERDIR = $(MISC)$/gnome
