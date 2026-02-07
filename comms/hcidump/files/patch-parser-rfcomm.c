--- parser/rfcomm.c.orig	2015-02-03 11:27:57.000000000 +1100
+++ parser/rfcomm.c	2015-02-03 11:28:26.000000000 +1100
@@ -49,11 +49,11 @@
 	address_field  addr  = head->addr;
 	uint8_t           ctr   = head->control;
 	uint16_t          ilen  = head->length.bits.len;
-	uint8_t           ctr_type,pf,dlci,fcs;
+	uint8_t           pf,dlci,fcs;
 
 	dlci     = GET_DLCI(addr);
 	pf       = GET_PF(ctr);
-	ctr_type = CLR_PF(ctr);
+/*	ctr_type = CLR_PF(ctr); */
 	fcs      = *(ptr + len - 1);
 
 	printf("cr %d dlci %d pf %d ilen %d fcs 0x%x ", addr.cr, dlci, pf, ilen, fcs); 
