--- ../product/util/makefile.mk.orig	Wed Oct  2 21:24:25 2002
+++ ../product/util/makefile.mk	Mon Oct 21 14:26:10 2002
@@ -131,13 +131,6 @@
 DESTDIRDLL=$(DESTDIRLIB)
 STLPORTLIBNAME=libstlport_gcc.so
 BINDINGDLL=$(COMNAME)_uno
-.IF "$(COMID)"=="gcc3"
-ADDITIONAL_DLLS= \
-	$(DESTDIRDLL)$/libgcc_s.so.1 		\
-	$(DESTDIRDLL)$/libgcc_s.so 		\
-    $(DESTDIRDLL)$/libstdc++.so.$(SHORTSTDCPP3)           \
-    $(DESTDIRDLL)$/libstdc++.so.$(LIBSTDCPP3)
-.ENDIF
 
 .ELIF "$(OS)"=="NETBSD"
 ###########
@@ -498,6 +491,7 @@
 #---------------------------------------------------------
 # special targets for linux gcc3 
 .IF "$(COMID)"=="gcc3"
+.IF "$(OS)"!="FREEBSD"
 
 $(DLLOUT)$/libstdc++.so.$(LIBSTDCPP3) :
        $(GCCINSTLIB) libstdc++.so.$(LIBSTDCPP3) $(DLLOUT)
@@ -511,7 +505,9 @@
        -rm -f $@
        +ln -s libstdc++.so.$(LIBSTDCPP3) $@
 .ENDIF 
+.ENDIF 
 
+.IF "$(OS)"!="FREEBSD"
 $(DLLOUT)$/libgcc_s.so.1 :
        $(GCCINSTLIB) libgcc_s.so.1 $(DLLOUT)
 
@@ -521,7 +517,8 @@
 
 $(DESTDIRDLL)$/libgcc_s.so : $(DESTDIRDLL)$/libgcc_s.so.1 $(DIRLIST)
 	-rm -f $@
-	+ln -s libgcc_s.so.1 $@
+	+ln -fs libgcc_s.so.1 $@
+.ENDIF
 #-------------------------------------------------------------
 
 $(DESTDIRJAR)$/%.jar : $(BINOUT)$/%.jar $(DIRLIST)
