--- ../product/util/makefile.mk.orig	Wed Oct  2 21:24:25 2002
+++ ../product/util/makefile.mk	Wed Oct 16 00:02:13 2002
@@ -521,7 +521,7 @@
 
 $(DESTDIRDLL)$/libgcc_s.so : $(DESTDIRDLL)$/libgcc_s.so.1 $(DIRLIST)
 	-rm -f $@
-	+ln -s libgcc_s.so.1 $@
+	+ln -fs libgcc_s.so.1 $@
 #-------------------------------------------------------------
 
 $(DESTDIRJAR)$/%.jar : $(BINOUT)$/%.jar $(DIRLIST)
