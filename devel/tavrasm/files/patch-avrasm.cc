--- src/avrasm.cc.orig	Mon Jan 19 17:11:30 2004
+++ src/avrasm.cc	Thu Jan 29 05:26:31 2004
@@ -862,6 +862,11 @@
       strcpy(type_start,".");
   }
 
+  /// Append default search path /////////////////////////////////////////////
+
+  if (yyIncPathCount < MAX_INCPATH_QTY)
+    yyIncludePaths[yyIncPathCount++] = "/usr/local/include/avr";
+
   return ok;
 }
 
