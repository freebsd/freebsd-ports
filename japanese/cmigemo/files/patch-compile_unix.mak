--- compile/unix.mak.orig	2014-12-20 04:39:02 UTC
+++ compile/unix.mak
@@ -39,36 +39,48 @@ install-mkdir:
 	$(MKDIR) $(bindir)
 	$(MKDIR) $(libdir)
 	$(MKDIR) $(incdir)
-	$(MKDIR) $(docdir)
+
+install-mkdir-dict:
 	$(MKDIR) $(dictdir)
 	$(MKDIR) $(dictdir)/cp932
 	$(MKDIR) $(dictdir)/euc-jp
 	$(MKDIR) $(dictdir)/utf-8
 
-install-dict:
+install-mkdir-doc:
+	$(MKDIR) $(docdir)
+
+install-dict: install-mkdir-dict
 	$(INSTALL_DATA) dict/migemo-dict $(dictdir)/cp932
+	if [ -d dict/euc-jp.d ]; then \
+	  $(INSTALL_DATA) dict/euc-jp.d/migemo-dict $(dictdir)/euc-jp; \
+	fi
+	if [ -d dict/utf-8.d ]; then \
+	  $(INSTALL_DATA) dict/utf-8.d/migemo-dict $(dictdir)/utf-8; \
+	fi
+
+install-dat: install-mkdir-dict
 	$(INSTALL_DATA) dict/han2zen.dat $(dictdir)/cp932
 	$(INSTALL_DATA) dict/hira2kata.dat $(dictdir)/cp932
 	$(INSTALL_DATA) dict/roma2hira.dat $(dictdir)/cp932
 	$(INSTALL_DATA) dict/zen2han.dat $(dictdir)/cp932
 	if [ -d dict/euc-jp.d ]; then \
-	  $(INSTALL_DATA) dict/euc-jp.d/migemo-dict $(dictdir)/euc-jp; \
 	  $(INSTALL_DATA) dict/euc-jp.d/han2zen.dat $(dictdir)/euc-jp; \
 	  $(INSTALL_DATA) dict/euc-jp.d/hira2kata.dat $(dictdir)/euc-jp; \
 	  $(INSTALL_DATA) dict/euc-jp.d/roma2hira.dat $(dictdir)/euc-jp; \
 	  $(INSTALL_DATA) dict/euc-jp.d/zen2han.dat $(dictdir)/euc-jp; \
 	fi
 	if [ -d dict/utf-8.d ]; then \
-	  $(INSTALL_DATA) dict/utf-8.d/migemo-dict $(dictdir)/utf-8; \
 	  $(INSTALL_DATA) dict/utf-8.d/han2zen.dat $(dictdir)/utf-8; \
 	  $(INSTALL_DATA) dict/utf-8.d/hira2kata.dat $(dictdir)/utf-8; \
 	  $(INSTALL_DATA) dict/utf-8.d/roma2hira.dat $(dictdir)/utf-8; \
 	  $(INSTALL_DATA) dict/utf-8.d/zen2han.dat $(dictdir)/utf-8; \
 	fi
 
-install: $(outdir)cmigemo$(EXEEXT) $(libmigemo_DSO) install-mkdir install-dict install-lib
-	$(INSTALL_DATA) $(srcdir)migemo.h $(incdir)
+install-doc: install-mkdir-doc
 	$(INSTALL_DATA) doc/README_j.txt $(docdir)
+
+install: $(outdir)cmigemo$(EXEEXT) $(libmigemo_DSO) install-mkdir install-dat install-lib
+	$(INSTALL_DATA) $(srcdir)migemo.h $(incdir)
 	$(INSTALL_PROGRAM) $(outdir)cmigemo$(EXEEXT) $(bindir)
 
 ##############################################################################
