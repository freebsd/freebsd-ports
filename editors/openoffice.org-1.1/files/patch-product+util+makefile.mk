--- ../product/util/makefile.mk.orig	Sat Mar  2 22:13:11 2002
+++ ../product/util/makefile.mk	Sat Mar  2 22:14:13 2002
@@ -111,6 +111,15 @@
 ADDITIONAL_DLLS= \
 	$(DESTDIRDLL)$/stlport_vc6.dll \
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
 
 .IF "$(STLPORTLIBNAME)" != ""
@@ -360,8 +369,8 @@
 	$(GNUCOPY) -p $(DLLOUT)$/$(@:f) $@
 
 $(DESTDIRDLL)$/%$(MY_VERSION_LINKPOSTFIX) : $(DESTDIRDLL)$/%$(MY_VERSION_DLLPOSTFIX) $(DIRLIST)
-	+ln -s $(@:f)$(MY_VERSION_LINKTARGETPOSTFIX) $@
-	+ln -s $(@:f)$(MY_VERSION_LINKTARGETPOSTFIX) $(@:db)
+	+ln -fs $(@:f)$(MY_VERSION_LINKTARGETPOSTFIX) $@
+	+ln -fs $(@:f)$(MY_VERSION_LINKTARGETPOSTFIX) $(@:db)
 
 $(DESTDIRJAR)$/%.jar : $(BINOUT)$/%.jar $(DIRLIST)
 	$(GNUCOPY) -p $(BINOUT)$/$(@:f) $@
