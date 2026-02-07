--- HP2100/hp2100_cpu.c.orig	2016-12-01 22:43:42 UTC
+++ HP2100/hp2100_cpu.c
@@ -1054,7 +1054,7 @@ for (i = OPTDEV; i <= MAXDEV; i++)      
 
 dtab [PWR] = &pwrf_dib;                                 /* for now, powerfail is always present */
 
-for (i = 0; dptr = sim_devices [i]; i++) {              /* loop thru dev */
+for (i = 0; (dptr = sim_devices [i]); i++) {              /* loop thru dev */
     dibptr = (DIB *) dptr->ctxt;                        /* get DIB */
 
     if (dibptr && !(dptr->flags & DEV_DIS)) {           /* handler exists and device is enabled? */
@@ -2153,13 +2153,13 @@ if (req_grant [0])                      
         else                                            /* not this one */
             req_grant [0] = req_grant [0] >> 1;         /* position next request */
 
-else if (req_grant [1])                                 /* device in upper half */
+else if (req_grant [1]) {                                /* device in upper half */
     for (sc = 32; sc <= 63; sc++)                       /* determine interrupting select code */
         if (req_grant [1] & 1)                          /* grant this request? */
             return sc;                                  /* return this select code */
         else                                            /* not this one */
             req_grant [1] = req_grant [1] >> 1;         /* position next request */
-
+  }
 return 0;                                               /* no interrupt granted */
 }
 
@@ -3611,7 +3611,7 @@ uint32 i, j, k;
 t_bool is_conflict = FALSE;
 uint32 conflicts[MAXDEV + 1] = { 0 };
 
-for (i = 0; dptr = sim_devices[i]; i++) {
+for (i = 0; (dptr = sim_devices[i]); i++) {
     dibptr = (DIB *) dptr->ctxt;
     if (dibptr && !(dptr->flags & DEV_DIS))
         if (++conflicts[dibptr->select_code] > 1)
@@ -3629,7 +3629,7 @@ if (is_conflict) {
             if (sim_log)
                 fprintf (sim_log, "Select code %o conflict:", i);
 
-            for (j = 0; dptr = sim_devices[j]; j++) {
+            for (j = 0; (dptr = sim_devices[j]); j++) {
                 dibptr = (DIB *) dptr->ctxt;
                 if (dibptr && !(dptr->flags & DEV_DIS) && (i == dibptr->select_code)) {
                     if (k < conflicts[i]) {
@@ -3791,12 +3791,12 @@ else
 
 result = cpu_set_size (uptr, new_memsize, NULL, NULL);  /* set memory size */
 
-if (result == SCPE_OK)                                  /* memory change OK? */
+if (result == SCPE_OK) {                                /* memory change OK? */
     if (new_family == UNIT_FAMILY_21XX)                 /* 21xx CPU? */
         fwanxm = MEMSIZE - IBL_LNT;                     /* reserve memory for loader */
     else
         fwanxm = MEMSIZE;                               /* loader reserved only for 21xx */
-
+  }
 return result;
 }
 
@@ -3810,11 +3810,12 @@ t_stat cpu_show_model (FILE *st, UNIT *u
 {
 fputs ((char *) desc, st);                              /* write model name */
 
-if (UNIT_CPU_FAMILY == UNIT_FAMILY_21XX)                /* valid only for 21xx */
+if (UNIT_CPU_FAMILY == UNIT_FAMILY_21XX) {              /* valid only for 21xx */
     if (fwanxm < MEMSIZE)                               /* loader area non-existent? */
         fputs (", loader disabled", st);                /* yes, so access disabled */
     else
         fputs (", loader enabled", st);                 /* no, so access enabled */
+  }
 return SCPE_OK;
 }
 
@@ -3846,12 +3847,12 @@ if (UNIT_CPU_TYPE == UNIT_TYPE_2100) {
         uptr->flags = uptr->flags | UNIT_FP;
     }
 
-else if (UNIT_CPU_MODEL == UNIT_1000_F)
+else if (UNIT_CPU_MODEL == UNIT_1000_F) {
     if (option == UNIT_VIS)                             /* 1000-F IOP and VIS options */
         uptr->flags = uptr->flags & ~UNIT_IOP;          /* are mutually exclusive */
     else if (option == UNIT_IOP)
         uptr->flags = uptr->flags & ~UNIT_VIS;
-
+  }
 return SCPE_OK;
 }
 
