--- ../product/util/makefile.mk.orig	Mon Dec 17 18:15:54 2001
+++ ../product/util/makefile.mk	Sun Mar 10 23:18:09 2002
@@ -117,6 +117,15 @@
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
@@ -373,8 +382,8 @@
 	$(GNUCOPY) -p $(DLLOUT)$/$(@:f) $@
 
 $(DESTDIRDLL)$/%$(MY_VERSION_LINKPOSTFIX) : $(DESTDIRDLL)$/%$(MY_VERSION_DLLPOSTFIX) $(DIRLIST)
-	+ln -s $(@:f)$(MY_VERSION_LINKTARGETPOSTFIX) $@
-	+ln -s $(@:f)$(MY_VERSION_LINKTARGETPOSTFIX) $(@:db)
+	+ln -fs $(@:f)$(MY_VERSION_LINKTARGETPOSTFIX) $@
+	+ln -fs $(@:f)$(MY_VERSION_LINKTARGETPOSTFIX) $(@:db)
 
 
 #---------------------------------------------------------
@@ -385,7 +394,7 @@
 
 $(DESTDIRDLL)$/libstdc++.so.3 : $(DESTDIRDLL)$/libstdc++.so.3.0.1 $(DIRLIST)
 	-rm -f $@
-	+ln -s libstdc++.so.3.0.1 $@
+	+ln -fs libstdc++.so.3.0.1 $@
 
 $(DESTDIRDLL)$/libgcc_s.so.1 : $(DLLOUT)$/libgcc_s.so.1 $(DIRLIST)
 	-rm -f $@
@@ -393,7 +402,7 @@
 
 $(DESTDIRDLL)$/libgcc_s.so : $(DESTDIRDLL)$/libgcc_s.so.1 $(DIRLIST)
 	-rm -f $@
-	+ln -s libgcc_s.so.1 $@
+	+ln -fs libgcc_s.so.1 $@
 #-------------------------------------------------------------
 
 $(DESTDIRJAR)$/%.jar : $(BINOUT)$/%.jar $(DIRLIST)
