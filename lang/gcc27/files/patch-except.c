--- cp/except.c.orig	Wed Oct 11 19:29:08 1995
+++ cp/except.c	Mon Mar 20 13:29:12 2000
@@ -148,6 +148,9 @@
 void
 exception_section ()
 {
+#ifdef EXCEPTION_SECTION_FUNCTION
+  EXCEPTION_SECTION_FUNCTION;
+#else
 #ifdef ASM_OUTPUT_SECTION_NAME
   named_section (NULL_TREE, ".gcc_except_table");
 #else
@@ -160,6 +163,7 @@
     readonly_data_section ();
 #endif
 #endif
+#endif
 }
 
 
@@ -1614,9 +1618,15 @@
 void
 register_exception_table ()
 {
+  rtx addr = gen_rtx (SYMBOL_REF, Pmode, "__EXCEPTION_TABLE__");
+
+#ifdef MARK_LOCAL_ADDRESS
+  MARK_LOCAL_ADDRESS(addr);
+#endif
+
   emit_library_call (gen_rtx (SYMBOL_REF, Pmode, "__register_exceptions"), 0,
 		     VOIDmode, 1,
-		     gen_rtx (SYMBOL_REF, Pmode, "__EXCEPTION_TABLE__"),
+		     addr,
 		     Pmode);
 }
 
