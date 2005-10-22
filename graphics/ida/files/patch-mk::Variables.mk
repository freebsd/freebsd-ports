--- mk/Variables.mk.orig	Sun Feb 22 14:27:19 2004
+++ mk/Variables.mk	Sat Oct 22 22:54:34 2005
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
@@ -34,9 +34,9 @@
 	   -Wpointer-arith -Wunused
 
 # add /usr/local to the search path if something is in there ...
-ifneq ($(wildcard /usr/local/include/*.h),)
-  CFLAGS  += -I/usr/local/include
-  LDFLAGS += -L/usr/local/$(LIB)
+ifneq ($(wildcard $(LOCALBASE)/include/*.h),)
+  CFLAGS  += -I$(LOCALBASE)/include
+  LDFLAGS += -L$(LOCALBASE)/$(LIB)
 endif
 
 # fixup include path for $(srcdir) != "."
