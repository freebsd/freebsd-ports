--- gcc/genmodes.c.orig	2013-01-10 20:38:27 UTC
+++ gcc/genmodes.c
@@ -1094,7 +1094,7 @@ emit_mode_mask (void)
   int c;
   struct mode_data *m;
 
-  print_decl ("unsigned HOST_WIDE_INT", "mode_mask_array",
+  print_decl ("unsigned HOST_WIDE_INT ", "mode_mask_array",
 	      "NUM_MACHINE_MODES");
   puts ("\
 #define MODE_MASK(m)                          \\\n\
