--- gcc/ipa-devirt.c.orig	2014-10-05 02:50:01 UTC
+++ gcc/ipa-devirt.c
@@ -1634,7 +1634,7 @@ dump_possible_polymorphic_call_targets (
     {
       fprintf (f, "    Contained in type:");
       print_generic_expr (f, ctx.outer_type, TDF_SLIM);
-      fprintf (f, " at offset "HOST_WIDE_INT_PRINT_DEC"\n",
+      fprintf (f, " at offset " HOST_WIDE_INT_PRINT_DEC "\n",
 	       ctx.offset);
     }
 
