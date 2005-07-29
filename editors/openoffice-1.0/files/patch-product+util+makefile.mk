--- product/util/makefile.mk.orig	Sat Jan 18 13:31:50 2003
+++ product/util/makefile.mk	Sat Jan 18 13:30:54 2003
@@ -131,13 +131,6 @@
 DESTDIRDLL=$(DESTDIRLIB)
 STLPORTLIBNAME=libstlport_gcc.so
 BINDINGDLL=$(COMNAME)_uno
-.IF "$(COMID)"=="gcc3"
-ADDITIONAL_DLLS= \
-       $(DESTDIRDLL)$/libgcc_s.so.1            \
-       $(DESTDIRDLL)$/libgcc_s.so              \
-       $(DESTDIRDLL)$/libstdc++.so.$(SHORTSTDCPP3)           \
-       $(DESTDIRDLL)$/libstdc++.so.$(LIBSTDCPP3)
-.ENDIF
 
 .ELIF "$(OS)"=="NETBSD"
 ###########
@@ -491,6 +484,7 @@
 # special targets for linux gcc3 
 .IF "$(COMID)"=="gcc3"
 
+.IF "$(OS)"!="FREEBSD"
 $(DLLOUT)$/libstdc++.so.$(LIBSTDCPP3) :
        $(GCCINSTLIB) libstdc++.so.$(LIBSTDCPP3) $(DLLOUT)
 
@@ -514,6 +508,7 @@
 $(DESTDIRDLL)$/libgcc_s.so : $(DESTDIRDLL)$/libgcc_s.so.1 $(DIRLIST)
 	-rm -f $@
 	+ln -s libgcc_s.so.1 $@
+.ENDIF
 #-------------------------------------------------------------
 
 $(DESTDIRJAR)$/%.jar : $(BINOUT)$/%.jar $(DIRLIST)
