--- ../product/util/makefile.mk.orig	Mon Mar 11 17:09:13 2002
+++ ../product/util/makefile.mk	Wed Apr  3 00:40:40 2002
@@ -157,6 +157,15 @@
 STLPORTLIBNAME=stlport_vc6.dll
 ADDITIONAL_DLLS= \
 	$(DESTDIRDLL)$/w9xucwrp.dll
+.ELIF "$(OS)"=="FREEBSD"
+###########
+# FREEBSD
+###########
+DESTDIRBIN=$(DESTDIR)$/freebsd$/bin
+DESTDIRLIB=$(DESTDIR)$/freebsd$/lib
+DESTDIRDLL=$(DESTDIRLIB)
+STLPORTLIBNAME=libstlport_gcc.so
+BINDINGDLL=gcc2_uno
 .ENDIF
 
 STLPORTDEST=$(DESTDIRDLL)$/$(STLPORTLIBNAME)
@@ -428,7 +437,7 @@
 
 $(DESTDIRDLL)$/libstdc++.so.3 : $(DESTDIRDLL)$/libstdc++.so.3.0.1 $(DIRLIST)
 	-rm -f $@
-	+ln -s libstdc++.so.3.0.1 $@
+	+ln -fs libstdc++.so.3.0.1 $@
 
 $(DESTDIRDLL)$/libgcc_s.so.1 : $(DLLOUT)$/libgcc_s.so.1 $(DIRLIST)
 	-rm -f $@
@@ -436,7 +445,7 @@
 
 $(DESTDIRDLL)$/libgcc_s.so : $(DESTDIRDLL)$/libgcc_s.so.1 $(DIRLIST)
 	-rm -f $@
-	+ln -s libgcc_s.so.1 $@
+	+ln -fs libgcc_s.so.1 $@
 #-------------------------------------------------------------
 
 $(DESTDIRJAR)$/%.jar : $(BINOUT)$/%.jar $(DIRLIST)
