--- ../idlc/source/makefile.mk.orig	Sat Mar  2 21:14:55 2002
+++ ../idlc/source/makefile.mk	Sat Mar  2 21:15:43 2002
@@ -148,6 +148,10 @@
 
 $(MISC)$/parser.cxx: parser.yy
 	+bison -v -d -o$(MISC)$/parser.cxx parser.yy
+.IF "$(OS)"=="FREEBSD"
+	+$(COPY) $(MISC)$/parser.hxx $(OUT)$/inc$/parser.h
+.ELSE
 	+$(COPY) $(MISC)$/parser.cxx.h $(OUT)$/inc$/parser.h
+.ENDIF
 # with line statements (for debugging)
 #	+bison -v -d -o$(MISC)$/parser.cxx parser.yy
