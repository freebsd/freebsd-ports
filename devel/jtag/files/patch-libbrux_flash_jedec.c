--- libbrux/flash/jedec.c.orig	Sun Aug  6 00:17:33 2006
+++ libbrux/flash/jedec.c	Sun Aug  6 00:17:50 2006
@@ -37,6 +37,7 @@
 {
 	int mid;
 	int did;
+	cfi_query_structure_t *cfi;
 
 	/* Query flash. */
 	bus_write( bus, 0x0, 0xf0 );
@@ -55,7 +56,7 @@
 	if (!(*cfi_array)->cfi_chips[0])
 		return -2;	/* out of memory */
 
-	cfi_query_structure_t *cfi = &(*cfi_array)->cfi_chips[0]->cfi;
+	cfi = &(*cfi_array)->cfi_chips[0]->cfi;
 
 	cfi->identification_string.pri_id_code = CFI_VENDOR_AMD_SCS;
 	cfi->identification_string.pri_vendor_tbl = NULL;
