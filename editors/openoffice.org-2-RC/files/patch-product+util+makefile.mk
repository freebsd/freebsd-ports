--- ../product/util/makefile.mk.orig	Tue Jun 11 17:09:39 2002
+++ ../product/util/makefile.mk	Mon Jul 15 15:54:13 2002
@@ -137,13 +137,6 @@
 DESTDIRDLL=$(DESTDIRLIB)
 STLPORTLIBNAME=libstlport_gcc.so
 BINDINGDLL=$(COMNAME)_uno
-.IF "$(COMID)"=="gcc3"
-ADDITIONAL_DLLS= \
-	$(DESTDIRDLL)$/libgcc_s.so.1 		\
-	$(DESTDIRDLL)$/libgcc_s.so 		\
-	$(DESTDIRDLL)$/libstdc++.so.3 		\
-	$(DESTDIRDLL)$/libstdc++.so.3.0.1
-.ENDIF
 
 .ELIF "$(OS)"=="NETBSD"
 ###########
@@ -498,6 +491,7 @@
 #---------------------------------------------------------
 # special targets for linux gcc3
 
+.IF "$(OS)"=="LINUX"
 .IF "$(CCNUMVER)">="000300010000"
 
 $(DESTDIRDLL)$/libstdc++.so.4.0.0 : $(DLLOUT)$/libstdc++.so.4.0.0 $(DIRLIST)
@@ -526,6 +520,9 @@
 $(DESTDIRDLL)$/libgcc_s.so : $(DESTDIRDLL)$/libgcc_s.so.1 $(DIRLIST)
 	-rm -f $@
 	+ln -s libgcc_s.so.1 $@
+
+.ENDIF
+
 #-------------------------------------------------------------
 
 $(DESTDIRJAR)$/%.jar : $(BINOUT)$/%.jar $(DIRLIST)
