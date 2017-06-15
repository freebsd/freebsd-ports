--- gdb/corelow.c.orig	2017-01-16 10:40:23.118428000 +0100
+++ gdb/corelow.c	2017-01-17 22:39:10.524216000 +0100
@@ -541,7 +541,8 @@
       warning (_("Section `%s' in core file too small."), section_name);
       return;
     }
-  if (size != min_size && !(regset->flags & REGSET_VARIABLE_SIZE))
+  if (size != min_size && regset != NULL &&
+	!(regset->flags & REGSET_VARIABLE_SIZE))
     {
       warning (_("Unexpected size of section `%s' in core file."),
 	       section_name);
