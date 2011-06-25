--- ../../src/druntime/posix.mak.orig	2011-05-07 13:02:24.000000000 -0700
+++ ../../src/druntime/posix.mak	2011-06-24 17:11:12.557237355 -0700
@@ -25,12 +25,10 @@
 DOCDIR=doc
 IMPDIR=import
 
-MODEL=32
+DFLAGS=-O -release -inline -nofloat -w -d -Isrc -Iimport
+UDFLAGS=-O -release -nofloat -w -d -Isrc -Iimport
 
-DFLAGS=-m$(MODEL) -O -release -inline -nofloat -w -d -Isrc -Iimport
-UDFLAGS=-m$(MODEL) -O -release -nofloat -w -d -Isrc -Iimport
-
-CFLAGS=-m$(MODEL) -O
+CFLAGS=-O
 
 OBJDIR=obj
 DRUNTIME_BASE=druntime
@@ -487,23 +485,23 @@
 doc: $(DOCS)
 
 $(DOCDIR)/object.html : src/object_.d
-	$(DMD) -m$(MODEL) -c -d -o- -Isrc -Iimport -Df$@ $(DOCFMT) $<
+	$(DMD) -c -d -o- -Isrc -Iimport -Df$@ $(DOCFMT) $<
 
 $(DOCDIR)/core_%.html : src/core/%.d
-	$(DMD) -m$(MODEL) -c -d -o- -Isrc -Iimport -Df$@ $(DOCFMT) $<
+	$(DMD) -c -d -o- -Isrc -Iimport -Df$@ $(DOCFMT) $<
 
 $(DOCDIR)/core_sync_%.html : src/core/sync/%.d
-	$(DMD) -m$(MODEL) -c -d -o- -Isrc -Iimport -Df$@ $(DOCFMT) $<
+	$(DMD) -c -d -o- -Isrc -Iimport -Df$@ $(DOCFMT) $<
 
 ######################## Header .di file generation ##############################
 
 import: $(IMPORTS)
 
 $(IMPDIR)/core/sys/windows/%.di : src/core/sys/windows/%.d
-	$(DMD) -m32 -c -d -o- -Isrc -Iimport -Hf$@ $<
+	$(DMD) -c -d -o- -Isrc -Iimport -Hf$@ $<
 
 $(IMPDIR)/core/%.di : src/core/%.d
-	$(DMD) -m$(MODEL) -c -d -o- -Isrc -Iimport -Hf$@ $<
+	$(DMD) -c -d -o- -Isrc -Iimport -Hf$@ $<
 
 ################### C/ASM Targets ############################
 
