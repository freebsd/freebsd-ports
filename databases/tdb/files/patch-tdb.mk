--- ./tdb.mk.orig	2010-01-09 02:39:48.000000000 +0000
+++ ./tdb.mk	2010-01-09 02:42:49.000000000 +0000
@@ -6,7 +6,7 @@
 ALL_PROGS = $(PROGS) $(PROGS_NOINSTALL)
 
 TDB_SONAME = libtdb.$(SHLIBEXT).1
-TDB_SOLIB = libtdb.$(SHLIBEXT).$(PACKAGE_VERSION)
+TDB_SOLIB = libtdb.$(SHLIBEXT).1
 TDB_STLIB = libtdb.a
 
 TDB_LIB = $(TDB_STLIB) 
@@ -67,7 +67,7 @@
 	mkdir -p $(DESTDIR)$(bindir)
 	mkdir -p $(DESTDIR)$(includedir)
 	mkdir -p $(DESTDIR)$(libdir) 
-	mkdir -p $(DESTDIR)$(libdir)/pkgconfig
+	mkdir -p $(DESTDIR)$(prefix)/libdata/pkgconfig
 
 installbin:: all installdirs
 	cp $(PROGS) $(DESTDIR)$(bindir)
@@ -76,7 +76,7 @@
 	cp $(srcdir)/include/tdb.h $(DESTDIR)$(includedir)
 
 installlibs:: all installdirs
-	cp tdb.pc $(DESTDIR)$(libdir)/pkgconfig
+	cp tdb.pc $(DESTDIR)$(prefix)/libdata/pkgconfig
 	cp $(TDB_STLIB) $(TDB_SOLIB) $(DESTDIR)$(libdir)
 
 $(TDB_STLIB): $(TDB_OBJ)
@@ -84,6 +84,3 @@
 
 libtdb.$(SHLIBEXT): $(TDB_SOLIB)
 	ln -fs $< $@
-
-$(TDB_SONAME): $(TDB_SOLIB)
-	ln -fs $< $@
