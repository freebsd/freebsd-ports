--- function.c.orig	Wed Aug 13 10:23:26 1997
+++ function.c	Mon Mar 20 13:29:11 2000
@@ -4887,18 +4887,23 @@
 #define HAS_INIT_SECTION
 #endif
 
+#ifndef GEN_CALL__MAIN
+#ifndef HAS_INIT_SECTION
+#define GEN_CALL__MAIN \
+  do {									\
+    emit_library_call (gen_rtx (SYMBOL_REF, Pmode, NAME__MAIN), 0,	\
+		       VOIDmode, 0);					\
+  } while (0)
+#endif
+#endif
+
 void
 expand_main_function ()
 {
+#ifdef GEN_CALL__MAIN
   if (!output_bytecode)
-    {
-      /* The zero below avoids a possible parse error */
-      0;
-#if !defined (HAS_INIT_SECTION)
-      emit_library_call (gen_rtx (SYMBOL_REF, Pmode, NAME__MAIN), 0,
-			 VOIDmode, 0);
-#endif /* not HAS_INIT_SECTION */
-    }
+    GEN_CALL__MAIN;
+#endif
 }
 
 extern struct obstack permanent_obstack;
