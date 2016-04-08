--- mk/Variables.mk.orig	2016-03-24 14:39:02 UTC
+++ mk/Variables.mk
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
 
