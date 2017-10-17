--- HP2100/hp2100_pif.c.orig	2017-10-12 22:55:55 UTC
+++ HP2100/hp2100_pif.c
@@ -306,7 +306,7 @@ while (working_set) {
 
             else {                                          /* DOS PIF */
                 setPRL (dibptr->select_code, !(pif.control | pif.flag));
-                setIRQ (dibptr->select_code, !pif.control & pif.flag & pif.flagbuf);
+                setIRQ (dibptr->select_code, (!pif.control) & pif.flag & pif.flagbuf);
                 }
 
             if (DEBUG_PRS (pif_dev))
