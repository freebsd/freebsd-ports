--- bfd/elfxx-tilegx.c.orig	2013-03-07 10:14:34.000000000 +0100
+++ bfd/elfxx-tilegx.c	2013-03-07 10:15:31.000000000 +0100
@@ -1205,7 +1205,7 @@
 };
 
 /* Reuse an existing info 10 bundle.  */
-static const bfd_byte const *tilegx64_plt_tail_entry =
+static const bfd_byte *tilegx64_plt_tail_entry =
   &tilegx64_short_plt_entry[4 * TILEGX_BUNDLE_SIZE_IN_BYTES];
 
 static const bfd_byte
@@ -1250,7 +1250,7 @@
 };
 
 /* Reuse an existing info 10 bundle.  */
-static const bfd_byte const *tilegx32_plt_tail_entry =
+static const bfd_byte *tilegx32_plt_tail_entry =
   &tilegx64_short_plt_entry[4 * TILEGX_BUNDLE_SIZE_IN_BYTES];
 
 static int
