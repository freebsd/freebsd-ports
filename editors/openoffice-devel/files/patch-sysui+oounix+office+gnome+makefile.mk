--- ../sysui/oounix/office/gnome/makefile.mk.orig	Tue Mar 11 16:53:53 2003
+++ ../sysui/oounix/office/gnome/makefile.mk	Tue Mar 11 16:55:28 2003
@@ -84,7 +84,9 @@
 APP1TARGET=$(TARGET)
 APP1OBJS=$(OBJFILES)
 APP1LIBS=
+.IF "$(OS)"!="FREEBSD"
 APP1STDLIBS=-ldl
+.ENDIF
 
 GNOMEFILES= \
 	locales.tab
