--- tdb.mk.orig	2010-02-08 16:12:57.000000000 +0100
+++ tdb.mk	2010-10-29 14:36:26.000000000 +0200
@@ -5,8 +5,7 @@
 PROGS_NOINSTALL = bin/tdbtest$(EXEEXT) bin/tdbtorture$(EXEEXT)
 ALL_PROGS = $(PROGS) $(PROGS_NOINSTALL)
 
-TDB_SONAME = libtdb.$(SHLIBEXT).1
-TDB_SOLIB = libtdb.$(SHLIBEXT).$(PACKAGE_VERSION)
+TDB_SOLIB = libtdb.$(SHLIBEXT).1
 TDB_STLIB = libtdb.a
 
 TDB_LIB = $(TDB_STLIB) 
@@ -28,7 +27,7 @@
 
 test:: abi_checks
 
-test:: bin/tdbtorture$(EXEEXT) $(TDB_SONAME)
+test:: bin/tdbtorture$(EXEEXT) $(TDB_SOLIB)
 	$(LIB_PATH_VAR)=. bin/tdbtorture$(EXEEXT)
 
 abi_checks::
@@ -37,7 +36,7 @@
 
 clean:: 
 	rm -f test.db test.tdb torture.tdb test.gdbm
-	rm -f $(TDB_SONAME) $(TDB_SOLIB) $(TDB_STLIB) libtdb.$(SHLIBEXT)
+	rm -f $(TDB_SOLIB) $(TDB_STLIB) libtdb.$(SHLIBEXT)
 	rm -f $(ALL_PROGS) tdb.pc
 	rm -f tdb.exports.sort tdb.exports.check tdb.exports.check.sort
 	rm -f tdb.signatures.sort tdb.signatures.check tdb.signatures.check.sort
@@ -70,7 +69,7 @@
 	mkdir -p $(DESTDIR)`$(PYTHON) -c "import distutils.sysconfig; print distutils.sysconfig.get_python_lib(1, prefix='$(prefix)')"`
 	cp tdb.$(SHLIBEXT) $(DESTDIR)`$(PYTHON) -c "import distutils.sysconfig; print distutils.sysconfig.get_python_lib(1, prefix='$(prefix)')"`
 
-check-python:: build-python $(TDB_SONAME)
+check-python:: build-python $(TDB_SOLIB)
 	$(LIB_PATH_VAR)=. PYTHONPATH=".:$(tdbdir)" $(PYTHON) $(tdbdir)/python/tests/simple.py
 
 clean::
@@ -80,7 +79,7 @@
 	mkdir -p $(DESTDIR)$(bindir)
 	mkdir -p $(DESTDIR)$(includedir)
 	mkdir -p $(DESTDIR)$(libdir) 
-	mkdir -p $(DESTDIR)$(libdir)/pkgconfig
+	mkdir -p $(DESTDIR)$(prefix)/libdata/pkgconfig
 
 installbin:: all installdirs
 	cp $(PROGS) $(DESTDIR)$(bindir)
@@ -89,18 +88,13 @@
 	cp $(srcdir)/include/tdb.h $(DESTDIR)$(includedir)
 
 installlibs:: all installdirs
-	cp tdb.pc $(DESTDIR)$(libdir)/pkgconfig
+	cp tdb.pc $(DESTDIR)$(prefix)/libdata/pkgconfig
 	cp $(TDB_STLIB) $(TDB_SOLIB) $(DESTDIR)$(libdir)
 	rm -f $(DESTDIR)$(libdir)/libtdb.$(SHLIBEXT)
 	ln -s $(TDB_SOLIB) $(DESTDIR)$(libdir)/libtdb.$(SHLIBEXT)
-	rm -f $(DESTDIR)$(libdir)/$(TDB_SONAME)
-	ln -s $(TDB_SOLIB) $(DESTDIR)$(libdir)/$(TDB_SONAME)
 
 $(TDB_STLIB): $(TDB_OBJ)
 	ar -rv $(TDB_STLIB) $(TDB_OBJ)
 
 libtdb.$(SHLIBEXT): $(TDB_SOLIB)
 	ln -fs $< $@
-
-$(TDB_SONAME): $(TDB_SOLIB)
-	ln -fs $< $@
