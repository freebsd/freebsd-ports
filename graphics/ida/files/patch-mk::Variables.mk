--- mk/Variables.mk.orig	Sun Feb 22 14:27:19 2004
+++ mk/Variables.mk	Fri Aug 20 19:15:12 2004
@@ -4,10 +4,10 @@
 # directories
 DESTDIR	=
 srcdir	?= .
-prefix	?= /usr/local
-bindir	=  $(DESTDIR)$(prefix)/bin
-mandir	=  $(DESTDIR)$(prefix)/share/man
-locdir  =  $(DESTDIR)$(prefix)/share/locale
+prefix	?= $(PREFIX)
+bindir	=  $(DESTDIR)$(PREFIX)/bin
+mandir	=  $(DESTDIR)$(PREFIX)/man
+locdir  =  $(DESTDIR)$(PREFIX)/share/locale
 
 # package + version
 empty	:=
