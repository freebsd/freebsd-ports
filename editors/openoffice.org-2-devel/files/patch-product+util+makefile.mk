--- ../product/util/makefile.mk.orig	Sun Jun  2 22:47:14 2002
+++ ../product/util/makefile.mk	Sun Jun  2 23:32:44 2002
@@ -108,12 +108,20 @@
 STLPORTLIBNAME=libstlport_gcc.so
 BINDINGDLL=$(COMNAME)_uno
 .IF "$(COMID)"=="gcc3"
+.IF "$(CCNUMVER)">="000300010000"
+ADDITIONAL_DLLS= \
+	$(DESTDIRDLL)$/libgcc_s.so.1		\
+	$(DESTDIRDLL)$/libgcc_s.so		\
+	$(DESTDIRDLL)$/libstdc++.so.4		\
+	$(DESTDIRDLL)$/libstdc++.so.4.0.0
+.ELSE
 ADDITIONAL_DLLS= \
 	$(DESTDIRDLL)$/libgcc_s.so.1 		\
 	$(DESTDIRDLL)$/libgcc_s.so 		\
 	$(DESTDIRDLL)$/libstdc++.so.3 		\
 	$(DESTDIRDLL)$/libstdc++.so.3.0.1
 .ENDIF
+.ENDIF
 .ELIF "$(OS)"=="FREEBSD"
 ###########
 # FREEBSD
@@ -123,13 +131,6 @@
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
 # NETBSD
@@ -447,6 +448,20 @@
 
 #---------------------------------------------------------
 # special targets for linux gcc3 
+
+.IF "$(OS)"=="LINUX"
+.IF "$(CCNUMVER)">="000300010000"
+
+$(DESTDIRDLL)$/libstdc++.so.4.0.0 : $(DLLOUT)$/libstdc++.so.4.0.0 $(DIRLIST)
+	-rm -f $@
+	$(GNUCOPY) -p $(DLLOUT)$/libstdc++.so.4.0.0 $@
+
+$(DESTDIRDLL)$/libstdc++.so.4 : $(DESTDIRDLL)$/libstdc++.so.4.0.0 $(DIRLIST)
+	-rm -f $@
+	+ln -fs libstdc++.so.4.0.0 $@
+
+.ELSE
+
 $(DESTDIRDLL)$/libstdc++.so.3.0.1 : $(DLLOUT)$/libstdc++.so.3.0.1 $(DIRLIST)
 	-rm -f $@
 	$(GNUCOPY) -p $(DLLOUT)$/libstdc++.so.3.0.1 $@
@@ -462,6 +477,8 @@
 $(DESTDIRDLL)$/libgcc_s.so : $(DESTDIRDLL)$/libgcc_s.so.1 $(DIRLIST)
 	-rm -f $@
 	+ln -fs libgcc_s.so.1 $@
+.ENDIF
+.ENDIF
 #-------------------------------------------------------------
 
 $(DESTDIRJAR)$/%.jar : $(BINOUT)$/%.jar $(DIRLIST)
