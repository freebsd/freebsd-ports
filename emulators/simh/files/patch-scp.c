--- scp.c.orig	2016-12-01 22:43:43 UTC
+++ scp.c
@@ -678,14 +678,14 @@ else if (*argv[0]) {                    
     char nbuf[PATH_MAX + 7], *np;                       /* "path.ini" */
     nbuf[0] = '"';                                      /* starting " */
     strncpy (nbuf + 1, argv[0], PATH_MAX + 1);          /* copy sim name */
-    if (np = match_ext (nbuf, "EXE"))                   /* remove .exe */
+    if ((np = match_ext (nbuf, "EXE")))                 /* remove .exe */
         *np = 0;
     strcat (nbuf, ".ini\"");                            /* add .ini" */
     stat = do_cmd (-1, nbuf);                           /* proc cmd file */
     }
 
 while (stat != SCPE_EXIT) {                             /* in case exit */
-    if (cptr = sim_brk_getact (cbuf, CBUFSIZE))         /* pending action? */
+    if ((cptr = sim_brk_getact (cbuf, CBUFSIZE)))       /* pending action? */
         printf ("sim> %s\n", cptr);                     /* echo */
     else if (sim_vm_read != NULL) {                     /* sim routine? */
         printf ("sim> ");                               /* prompt */
@@ -700,7 +700,7 @@ while (stat != SCPE_EXIT) {             
         fprintf (sim_log, "sim> %s\n", cptr);
     cptr = get_glyph (cptr, gbuf, 0);                   /* get command glyph */
     sim_switches = 0;                                   /* init switches */
-    if (cmdp = find_cmd (gbuf))                         /* lookup command */
+    if ((cmdp = find_cmd (gbuf)))                       /* lookup command */
         stat = cmdp->action (cmdp->arg, cptr);          /* if found, exec */
     else stat = SCPE_UNK;
     if (stat >= SCPE_BASE) {                            /* error? */
@@ -767,7 +767,7 @@ if (*cptr) {
     cptr = get_glyph (cptr, gbuf, 0);
     if (*cptr)
         return SCPE_2MARG;
-    if (cmdp = find_cmd (gbuf)) {
+    if ((cmdp = find_cmd (gbuf))) {
         fputs (cmdp->help, stdout);
         if (sim_log)
             fputs (cmdp->help, sim_log);
@@ -911,7 +911,7 @@ do {
     cptr = get_glyph (cptr, gbuf, 0);                   /* get command glyph */
     sim_switches = 0;                                   /* init switches */
     isdo = FALSE;
-    if (cmdp = find_cmd (gbuf)) {                       /* lookup command */
+    if ((cmdp = find_cmd (gbuf))) {                     /* lookup command */
         isdo = (cmdp->action == &do_cmd);
         if (isdo) {                                     /* DO command? */
             if (flag >= DO_NEST_LVL)                    /* nest too deep? */
@@ -1091,18 +1091,18 @@ if (*cptr == 0)                         
     return SCPE_2FARG;
 cptr = get_glyph (cptr, gbuf, 0);                       /* get glob/dev/unit */
 
-if (dptr = find_dev (gbuf)) {                           /* device match? */
+if ((dptr = find_dev (gbuf))) {                         /* device match? */
     uptr = dptr->units;                                 /* first unit */
     ctbr = set_dev_tab;                                 /* global table */
     lvl = MTAB_VDV;                                     /* device match */
     }
-else if (dptr = find_unit (gbuf, &uptr)) {              /* unit match? */
+else if ((dptr = find_unit (gbuf, &uptr))) {            /* unit match? */
     if (uptr == NULL)                                   /* invalid unit */
         return SCPE_NXUN;
     ctbr = set_unit_tab;                                /* global table */
     lvl = MTAB_VUN;                                     /* unit match */
     }
-else if (gcmdp = find_ctab (set_glob_tab, gbuf))        /* global? */
+else if ((gcmdp = find_ctab (set_glob_tab, gbuf)))      /* global? */
     return gcmdp->action (gcmdp->arg, cptr);            /* do the rest */
 else return SCPE_NXDEV;                                 /* no match */
 if (*cptr == 0)                                         /* must be more */
@@ -1110,7 +1110,7 @@ if (*cptr == 0)                         
 
 while (*cptr != 0) {                                    /* do all mods */
     cptr = get_glyph (svptr = cptr, gbuf, ',');         /* get modifier */
-    if (cvptr = strchr (gbuf, '='))                     /* = value? */
+    if ((cvptr = strchr (gbuf, '=')))                   /* = value? */
         *cvptr++ = 0;
     for (mptr = dptr->modifiers; mptr && (mptr->mask != 0); mptr++) {
         if ((mptr->mstring) &&                          /* match string */
@@ -1123,7 +1123,7 @@ while (*cptr != 0) {                    
                 if (mptr->valid) {                      /* validation rtn? */
                     if (cvptr && (mptr->mask & MTAB_NC)) {
                         get_glyph_nc (svptr, gbuf, ',');
-                        if (cvptr = strchr (gbuf, '='))
+                        if ((cvptr = strchr (gbuf, '=')))
                             *cvptr++ = 0;
                         }
                     r = mptr->valid (uptr, mptr->match, cvptr, mptr->desc);
@@ -1156,7 +1156,7 @@ while (*cptr != 0) {                    
             }                                           /* end if match */
         }                                               /* end for */
     if (!mptr || (mptr->mask == 0)) {                   /* no match? */
-        if (glbr = find_c1tab (ctbr, gbuf)) {           /* global match? */
+        if ((glbr = find_c1tab (ctbr, gbuf))) {         /* global match? */
             r = glbr->action (dptr, uptr, glbr->arg, cvptr);    /* do global */
             if (r != SCPE_OK)
                 return r;
@@ -1349,15 +1349,15 @@ GET_SWITCHES (cptr);                    
 if (*cptr == 0)                                         /* must be more */
     return SCPE_2FARG;
 cptr = get_glyph (cptr, gbuf, 0);                       /* get next glyph */
-if (shptr = find_shtab (show_glob_tab, gbuf))           /* global? */
+if ((shptr = find_shtab (show_glob_tab, gbuf)))         /* global? */
     return shptr->action (ofile, NULL, NULL, shptr->arg, cptr);
 
-if (dptr = find_dev (gbuf)) {                           /* device match? */
+if ((dptr = find_dev (gbuf))) {                         /* device match? */
     uptr = dptr->units;                                 /* first unit */
     shtb = show_dev_tab;                                /* global table */
     lvl = MTAB_VDV;                                     /* device match */
     }
-else if (dptr = find_unit (gbuf, &uptr)) {              /* unit match? */
+else if ((dptr = find_unit (gbuf, &uptr))) {            /* unit match? */
     if (uptr == NULL)                                   /* invalid unit */
         return SCPE_NXUN;
     if (uptr->flags & UNIT_DIS)                         /* disabled? */
@@ -1377,7 +1377,7 @@ if (dptr->modifiers == NULL)            
 
 while (*cptr != 0) {                                    /* do all mods */
     cptr = get_glyph (cptr, gbuf, ',');                 /* get modifier */
-    if (cvptr = strchr (gbuf, '='))                     /* = value? */
+    if ((cvptr = strchr (gbuf, '=')))                   /* = value? */
         *cvptr++ = 0;
     for (mptr = dptr->modifiers; mptr->mask != 0; mptr++) {
         if (((mptr->mask & MTAB_XTD)?                   /* right level? */
@@ -1396,7 +1396,7 @@ while (*cptr != 0) {                    
             }                                           /* end if */
         }                                               /* end for */
     if (mptr->mask == 0) {                              /* no match? */
-        if (shptr = find_shtab (shtb, gbuf))            /* global match? */
+        if ((shptr = find_shtab (shtb, gbuf)))          /* global match? */
             shptr->action (ofile, dptr, uptr, shptr->arg, cptr);
         else return SCPE_ARG;
         }                                               /* end if */
@@ -1800,7 +1800,7 @@ if (sim_brk_types == 0) 
     return SCPE_NOFNC;
 if ((dptr == NULL) || (uptr == NULL))
     return SCPE_IERR;
-if (aptr = strchr (cptr, ';')) {                        /* ;action? */
+if ((aptr = strchr (cptr, ';'))) {                      /* ;action? */
     if (flg != SSH_ST)                                  /* only on SET */
         return SCPE_ARG;
     *aptr++ = 0;                                        /* separate strings */
@@ -3699,7 +3699,7 @@ if ((cptr == NULL) || (*cptr == 0))
     return SCPE_ARG;
 strncpy (gbuf, cptr, CBUFSIZE);
 addrp = gbuf;                                           /* default addr */
-if (portp = strchr (gbuf, ':'))                         /* x:y? split */
+if ((portp = strchr (gbuf, ':')))                       /* x:y? split */
     *portp++ = 0;
 else if (strchr (gbuf, '.'))                            /* x.y...? */
     portp = NULL;
@@ -3782,7 +3782,7 @@ DEVICE *dptr;
 
 if (uptr == NULL)                                       /* arg error? */
     return NULL;
-if (dptr = find_dev (cptr)) {                           /* exact match? */
+if ((dptr = find_dev (cptr))) {                         /* exact match? */
     if (qdisable (dptr))                                /* disabled? */
         return NULL;
     *uptr = dptr->units;                                /* unit 0 */
@@ -3862,7 +3862,7 @@ REG *rptr, *srptr = NULL;
 for (i = 0; (dptr = sim_devices[i]) != 0; i++) {        /* all dev */
     if (dptr->flags & DEV_DIS)                          /* skip disabled */
         continue;
-    if (rptr = find_reg (cptr, optr, dptr)) {           /* found? */
+    if ((rptr = find_reg (cptr, optr, dptr))) {         /* found? */
         if (srptr)                                      /* ambig? err */
             return NULL;
         srptr = rptr;                                   /* save reg */
@@ -4080,15 +4080,15 @@ const char logstr[] = "|&^", cmpstr[] = 
 logval = cmpval = 0;
 if (*cptr == 0)                                         /* check for clause */
     return NULL;
-for (logop = cmpop = -1; c = *cptr++; ) {               /* loop thru clauses */
-    if (sptr = strchr (logstr, c)) {                    /* check for mask */
+for (logop = cmpop = -1; (c = *cptr++); ) {             /* loop thru clauses */
+    if ((sptr = strchr (logstr, c))) {                  /* check for mask */
         logop = (int32)(sptr - logstr);
         logval = strtotv (cptr, &tptr, radix);
         if (cptr == tptr)
             return NULL;
         cptr = tptr;
         }
-    else if (sptr = strchr (cmpstr, c)) {               /* check for boolop */
+    else if ((sptr = strchr (cmpstr, c))) {             /* check for boolop */
         cmpop = (int32)(sptr - cmpstr);
         if (*cptr == '=') {
             cmpop = cmpop + strlen (cmpstr);
@@ -4753,7 +4753,7 @@ while (isspace (*sim_brk_act))          
     sim_brk_act++;
 if (*sim_brk_act == 0)                              /* now empty? */
     return (sim_brk_act = NULL);
-if (ep = strchr (sim_brk_act, ';')) {                   /* cmd delimiter? */
+if ((ep = strchr (sim_brk_act, ';'))) {                 /* cmd delimiter? */
     lnt = ep - sim_brk_act;                             /* cmd length */
     memcpy (buf, sim_brk_act, lnt + 1);                 /* copy with ; */
     buf[lnt] = 0;                                       /* erase ; */
