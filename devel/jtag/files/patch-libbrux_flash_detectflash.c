--- libbrux/flash/detectflash.c.orig	Sat Aug  5 23:48:47 2006
+++ libbrux/flash/detectflash.c	Sat Aug  5 23:49:40 2006
@@ -43,7 +43,7 @@
 int jedec_detect( bus_t *bus, uint32_t adr, cfi_array_t **cfi_array );
 
 void
-detectflash( bus_t *bus )
+detectflash( bus_t *bus , uint32_t adr )
 {
 	cfi_array_t *cfi_array = NULL;
 	cfi_query_structure_t *cfi;
