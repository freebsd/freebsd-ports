--- bfd.orig/archures.c	Sun May 12 10:57:05 2002
+++ bfd/archures.c	Sun May 12 10:58:13 2002
@@ -288,7 +288,9 @@
 .  const char *arch_name;
 .  const char *printable_name;
 .  unsigned int section_align_power;
-.  {* True if this is the default machine for the architecture.  *}
+.  {* True if this is the default machine for the architecture.
+.     The default arch should be the first entry for an arch so that
+.     all the entries for that arch can be accessed via <<next>>.  *}
 .  boolean the_default;
 .  const struct bfd_arch_info * (*compatible)
 .	PARAMS ((const struct bfd_arch_info *a,
@@ -604,21 +606,9 @@
      enum bfd_architecture arch;
      unsigned long mach;
 {
-  const bfd_arch_info_type * const *app, *ap;
-
-  for (app = bfd_archures_list; *app != NULL; app++)
-    {
-      for (ap = *app; ap != NULL; ap = ap->next)
-	{
-	  if (ap->arch == arch
-	      && (ap->mach == mach
-		  || (mach == 0 && ap->the_default)))
-	    {
-	      abfd->arch_info = ap;
-	      return true;
-	    }
-	}
-    }
+  abfd->arch_info = bfd_lookup_arch (arch, mach);
+  if (abfd->arch_info != NULL)
+    return true;
 
   abfd->arch_info = &bfd_default_arch_struct;
   bfd_set_error (bfd_error_bad_value);
