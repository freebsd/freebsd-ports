--- ../idlc/source/makefile.mk.orig	Wed Mar  6 10:25:35 2002
+++ ../idlc/source/makefile.mk	Wed Mar  6 10:25:53 2002
@@ -147,6 +147,7 @@
 	+flex -o$(MISC)$/scanner.cxx $(MISC)$/stripped_scanner.ll
 
 $(MISC)$/parser.cxx: parser.yy
+	+bison -v -d -o$(MISC)$/parser.cxx.h parser.yy
 	+bison -v -d -o$(MISC)$/parser.cxx parser.yy
 	+$(COPY) $(MISC)$/parser.cxx.h $(OUT)$/inc$/parser.h
 # with line statements (for debugging)
