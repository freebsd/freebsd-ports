--- VAX/vax_sys.c.orig	2016-12-01 22:43:43 UTC
+++ VAX/vax_sys.c
@@ -1173,7 +1173,7 @@ const char *force[] = { "S^", "I^", "B^"
 
 *r = SCPE_OK;                                           /* assume ok */
 M1C ('@', SP_IND);                                      /* look for @ */
-if (tptr = parse_rnum (cptr, &rn)) {                    /* look for Rn */
+if ((tptr = parse_rnum (cptr, &rn))) {                  /* look for Rn */
     if (*cptr == '[') {                                 /* look for [Rx] */
         cptr = parse_rnum (++cptr, &index);
         if ((cptr == NULL) || (*cptr++ != ']'))
