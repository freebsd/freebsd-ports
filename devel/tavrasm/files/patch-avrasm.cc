--- src/avrasm.cc.orig	Fri Dec 12 13:50:49 2003
+++ src/avrasm.cc	Fri Dec 12 13:56:40 2003
@@ -861,6 +861,11 @@
       strcpy(type_start,".");
   }
 
+  /// Append default search path /////////////////////////////////////////////
+
+  if (yyIncPathCount < MAX_INCPATH_QTY)
+    yyIncludePaths[yyIncPathCount++] = "/usr/local/include/avr";
+
   return ok;
 }
 
