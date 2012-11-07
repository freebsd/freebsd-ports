--- ic/sparc/sparc-execute.c	2010-02-21 06:58:15.000000000 +0900
+++ ic/sparc/sparc-execute.c	2010-04-14 22:55:50.000000000 +0900
@@ -612,7 +612,7 @@
 			    != pc_previous)) {
       if (__tme_predict_true(((tme_sparc_ireg_t) (pc + sizeof(tme_uint32_t)))
 			     == ic->tme_sparc_ireg(TME_SPARC_IREG_PC_NEXT))) {
-	tme_recode_thunk_off_t insns_thunk;
+	tme_recode_thunk_off_t insns_thunk = 0; /* XXX gcc -Wuninitialized */
 
 	/* if the current instruction TLB entry is not the invalid TLB
 	   entry, and there is an instructions thunk for this PC: */
