--- sim_console.c.orig	2016-12-01 22:43:43 UTC
+++ sim_console.c
@@ -162,10 +162,10 @@ if ((cptr == NULL) || (*cptr == 0))
     return SCPE_2FARG;
 while (*cptr != 0) {                                    /* do all mods */
     cptr = get_glyph_nc (cptr, gbuf, ',');              /* get modifier */
-    if (cvptr = strchr (gbuf, '='))                     /* = value? */
+    if ((cvptr = strchr (gbuf, '=')))                     /* = value? */
         *cvptr++ = 0;
     get_glyph (gbuf, gbuf, 0);                          /* modifier to UC */
-    if (ctptr = find_ctab (set_con_tab, gbuf)) {        /* match? */
+    if ((ctptr = find_ctab (set_con_tab, gbuf))) {      /* match? */
         r = ctptr->action (ctptr->arg, cvptr);          /* do the rest */
         if (r != SCPE_OK)
             return r;
@@ -190,7 +190,7 @@ if (*cptr == 0) {                       
     }
 while (*cptr != 0) {
     cptr = get_glyph (cptr, gbuf, ',');                 /* get modifier */
-    if (shptr = find_shtab (show_con_tab, gbuf))
+    if ((shptr = find_shtab (show_con_tab, gbuf)))
         shptr->action (st, dptr, uptr, shptr->arg, cptr);
     else return SCPE_NOPARAM;
     }
@@ -459,7 +459,7 @@ if ((c == SCPE_STOP) || (sim_con_tmxr.ma
 if (sim_con_ldsc.conn == 0)                              /* no Telnet conn? */
     return SCPE_LOST;
 tmxr_poll_rx (&sim_con_tmxr);                           /* poll for input */
-if (c = tmxr_getc_ln (&sim_con_ldsc))                   /* any char? */ 
+if ((c = tmxr_getc_ln (&sim_con_ldsc)))                 /* any char? */ 
     return (c & (SCPE_BREAK | 0377)) | SCPE_KFLAG;
 return SCPE_OK;
 }
