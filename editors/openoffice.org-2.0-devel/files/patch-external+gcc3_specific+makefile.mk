--- ../external/gcc3_specific/makefile.mk.orig	Sat May 31 22:43:57 2003
+++ ../external/gcc3_specific/makefile.mk	Sat May 31 22:43:59 2003
@@ -11,6 +11,7 @@
 
 .IF "$(OS)"!="MACOSX"
 .IF "$(OS)"!="IRIX"
+.IF "$(OS)"!="FREEBSD"
 
 
 all : $(SOLARLIBDIR)$/libstdc++.so.$(SHORTSTDCPP3) $(SOLARLIBDIR)$/libgcc_s.so.1 $(SOLARLIBDIR)$/libgcc_s.so 
@@ -26,6 +27,7 @@
         -rm -f $@
         +ln -s libgcc_s.so.1 $@
 
+.ENDIF 
 .ENDIF 
 .ENDIF 
 
