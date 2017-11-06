--- cstdlib/stdio.c.orig	2017-03-22 14:37:13.263703000 -0700
+++ cstdlib/stdio.c	2017-03-22 14:41:07.228360000 -0700
@@ -428,7 +428,7 @@
 void StdioFileno(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) 
 {
 #ifndef WIN32
-    ReturnValue->Val->Integer = fileno(Param[0]->Val->Pointer);
+    ReturnValue->Val->Integer = fileno((FILE *)Param[0]->Val->Pointer);
 #else
     ReturnValue->Val->Integer = _fileno(Param[0]->Val->Pointer);
 #endif
