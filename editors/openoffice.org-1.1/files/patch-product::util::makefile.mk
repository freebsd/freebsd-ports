--- ../product/util/makefile.mk.orig	Wed Feb 27 12:32:19 2002
+++ ../product/util/makefile.mk	Tue Mar 12 14:08:34 2002
@@ -115,13 +115,26 @@
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
+BINDINGDLL=$(COMNAME)_uno
 .ENDIF
 
 STLPORTDEST=$(DESTDIRDLL)$/$(STLPORTLIBNAME)
 .IF "$(STLPORT4)" != ""
 # in OOo build environment
 .IF "($STLPORT4)" != "NO_STLPORT4"
+.IF "$(OS)" != "FREEBSD"
 STLPORTOUT=$(SOLARVER)$/$(UPD)$/$(INPATH)$/bin$/$(STLPORTLIBNAME)
+.ELSE
+STLPORTOUT=$(STLPORT4)$/lib$/$(STLPORTLIBNAME)
+.ENDIF
 .ELSE	
 STLPORTOUT=$(STLPORT4)$/lib$/$(STLPORTLIBNAME)
 .ENDIF
@@ -367,8 +380,8 @@
 	$(GNUCOPY) -p $(DLLOUT)$/$(@:f) $@
 
 $(DESTDIRDLL)$/%$(MY_VERSION_LINKPOSTFIX) : $(DESTDIRDLL)$/%$(MY_VERSION_DLLPOSTFIX) $(DIRLIST)
-	+ln -s $(@:f)$(MY_VERSION_LINKTARGETPOSTFIX) $@
-	+ln -s $(@:f)$(MY_VERSION_LINKTARGETPOSTFIX) $(@:db)
+	+ln -fs $(@:f)$(MY_VERSION_LINKTARGETPOSTFIX) $@
+	+ln -fs $(@:f)$(MY_VERSION_LINKTARGETPOSTFIX) $(@:db)
 
 
 #---------------------------------------------------------
@@ -379,7 +392,7 @@
 #
 #$(DESTDIRDLL)$/libstdc++.so.3 : $(DESTDIRDLL)$/libstdc++.so.3.0.1 $(DIRLIST)
 #	-rm -f $@
-#	+ln -s libstdc++.so.3.0.1 $@
+#	+ln -fs libstdc++.so.3.0.1 $@
 
 $(DESTDIRDLL)$/libgcc_s.so.1 : $(DLLOUT)$/libgcc_s.so.1 $(DIRLIST)
 	-rm -f $@
@@ -387,7 +400,7 @@
 
 $(DESTDIRDLL)$/libgcc_s.so : $(DESTDIRDLL)$/libgcc_s.so.1 $(DIRLIST)
 	-rm -f $@
-	+ln -s libgcc_s.so.1 $@
+	+ln -fs libgcc_s.so.1 $@
 #-------------------------------------------------------------
 
 $(DESTDIRJAR)$/%.jar : $(BINOUT)$/%.jar $(DIRLIST)
