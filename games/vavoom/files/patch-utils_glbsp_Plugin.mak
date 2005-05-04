--- utils/glbsp/Plugin.mak.orig
+++ utils/glbsp/Plugin.mak
@@ -6,9 +6,9 @@
 
 OUTNAME=libglbsp.a
 
-CC=gcc
-CFLAGS=-O3 -Wall -DGLBSP_PLUGIN -DUNIX -DINLINE_G=inline
-AR=ar rc
+#CC=gcc
+CFLAGS+=-O3 -Wall -DGLBSP_PLUGIN -DUNIX -DINLINE_G=inline
+#AR=ar rc
 RANLIB=ranlib
 
 OBJS=$(MAIN)/analyze.o  \
@@ -31,7 +31,7 @@
 	rm -f $(OUTNAME) $(MAIN)/*.o
 
 $(OUTNAME): $(OBJS)
-	$(AR) $(OUTNAME) $(OBJS)
+	$(AR) rc $(OUTNAME) $(OBJS)
 	$(RANLIB) $(OUTNAME)
 
 .PHONY: all clean
