--- mk/Variables.mk.orig	2008-06-09 17:56:36.000000000 +0300
+++ mk/Variables.mk	2009-05-24 19:03:04.000000000 +0300
@@ -4,12 +4,12 @@
 # directories
 DESTDIR	=
 srcdir	?= .
-prefix	?= /usr/local
-bindir	=  $(DESTDIR)$(prefix)/bin
-sbindir	=  $(DESTDIR)$(prefix)/sbin
-libdir  =  $(DESTDIR)$(prefix)/$(LIB)
-shrdir  =  $(DESTDIR)$(prefix)/share
-mandir	=  $(shrdir)/man
+prefix	?= $(PREFIX)
+bindir	=  $(DESTDIR)$(PREFIX)/bin
+sbindir	=  $(DESTDIR)$(PREFIX)/sbin
+libdir  =  $(DESTDIR)$(PREFIX)/$(LIB)
+shrdir  =  $(DESTDIR)$(PREFIX)/share
+mandir	=  $(DESTDIR)$(PREFIX)/man
 locdir  =  $(shrdir)/locale
 appdir  =  $(shrdir)/applications
 
