--- ../product/util/makefile.mk.orig	Sat Apr  6 12:01:11 2002
+++ ../product/util/makefile.mk	Mon Jun  3 00:00:57 2002
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
@@ -438,13 +439,27 @@
 
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
 
 $(DESTDIRDLL)$/libstdc++.so.3 : $(DESTDIRDLL)$/libstdc++.so.3.0.1 $(DIRLIST)
 	-rm -f $@
-	+ln -s libstdc++.so.3.0.1 $@
+	+ln -fs libstdc++.so.3.0.1 $@
 
 $(DESTDIRDLL)$/libgcc_s.so.1 : $(DLLOUT)$/libgcc_s.so.1 $(DIRLIST)
 	-rm -f $@
@@ -452,7 +467,11 @@
 
 $(DESTDIRDLL)$/libgcc_s.so : $(DESTDIRDLL)$/libgcc_s.so.1 $(DIRLIST)
 	-rm -f $@
-	+ln -s libgcc_s.so.1 $@
+	+ln -fs libgcc_s.so.1 $@
+
+.ENDIF
+.ENDIF
+
 #-------------------------------------------------------------
 
 $(DESTDIRJAR)$/%.jar : $(BINOUT)$/%.jar $(DIRLIST)
