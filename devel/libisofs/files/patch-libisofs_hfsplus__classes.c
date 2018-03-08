patch from https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=226318
It will be included in the next release.

--- libisofs/hfsplus_classes.c.orig	2018-03-08 18:48:59 UTC
+++ libisofs/hfsplus_classes.c
@@ -422,6 +422,10 @@ static uint16_t class_page_data[] = {
   0x21, 0x230,
   0x22, 0x230,
   0x23, 0x230,
+  0x00,
+
+  /* End of list */
+  0x00
 };
 
 uint16_t *hfsplus_class_pages[256];
