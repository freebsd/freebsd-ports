--- ./cstdlib/stdio.c.orig	2011-02-21 06:22:13.000000000 +0100
+++ ./cstdlib/stdio.c	2011-03-11 08:08:19.710970864 +0100
@@ -414,7 +414,7 @@
 
 void StdioFileno(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) 
 {
-    ReturnValue->Val->Integer = fileno(Param[0]->Val->Pointer);
+    ReturnValue->Val->Integer = fileno((FILE *)Param[0]->Val->Pointer);
 }
 
 void StdioFflush(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) 
