--- ../external/gcc3_specific/makefile.mk.orig	Wed Mar  5 23:01:32 2003
+++ ../external/gcc3_specific/makefile.mk	Wed Mar  5 23:01:59 2003
@@ -10,6 +10,7 @@
 .IF "$(COMID)"=="gcc3"
 
 .IF "$(OS)"!="MACOSX"
+.IF "$(OS)"!="FREEBSD"
 
 
 all : $(SOLARLIBDIR)$/libstdc++.so.$(LIBSTDCPP3) $(SOLARLIBDIR)$/libgcc_s.so.1 $(SOLARLIBDIR)$/libstdc++.so.$(SHORTSTDCPP3) $(SOLARLIBDIR)$/libgcc_s.so 
@@ -29,6 +30,7 @@
         -rm -f $@
         +ln -s libgcc_s.so.1 $@
 
+.ENDIF 
 .ENDIF 
 
 .ENDIF
