--- SDS/sds_cpu.c.orig	2016-12-01 22:43:43 UTC
+++ SDS/sds_cpu.c
@@ -385,14 +385,14 @@ while (reason == 0) {                   
         }
 
     if (sim_interval <= 0) {                            /* event queue? */
-        if (reason = sim_process_event ())              /* process */
+        if ((reason = sim_process_event ()))            /* process */
             break;
         int_reqhi = api_findreq ();                     /* recalc int req */
         chan_req = chan_testact ();                     /* recalc chan act */
         }
 
     if (chan_req) {                                     /* channel request? */
-        if (reason = chan_process ())                   /* process */
+        if ((reason = chan_process ()))                 /* process */
             break;
         int_reqhi = api_findreq ();                     /* recalc int req */
         chan_req = chan_testact ();                     /* recalc chan act */
@@ -506,7 +506,7 @@ if (inst & I_POP) {                     
             }
         else {                                          /* normal POP */
             dat = (OV << 23) | dat;                     /* ov in <0> */
-            if (r = Write (0, dat))
+            if ((r = Write (0, dat)))
                 return r;
             }
         }               
@@ -525,49 +525,49 @@ switch (op) {                           
 /* Loads and stores */
 
     case LDA:
-        if (r = Ea (inst, &va))                         /* decode eff addr */
+        if ((r = Ea (inst, &va)))                       /* decode eff addr */
             return r;
-        if (r = Read (va, &A))                          /* get operand */
+        if ((r = Read (va, &A)))                        /* get operand */
             return r;
         break;
 
     case LDB:
-        if (r = Ea (inst, &va))                         /* decode eff addr */
+        if ((r = Ea (inst, &va)))                       /* decode eff addr */
             return r;
-        if (r = Read (va, &B))                          /* get operand */
+        if ((r = Read (va, &B)))                        /* get operand */
             return r;
         break;
 
     case LDX:
-        if (r = Ea (inst, &va))                         /* decode eff addr */
+        if ((r = Ea (inst, &va)))                       /* decode eff addr */
             return r;
-        if (r = Read (va, &X))                          /* get operand */
+        if ((r = Read (va, &X)))                        /* get operand */
             return r;
         break;
 
     case STA:
-        if (r = Ea (inst, &va))                         /* decode eff addr */
+        if ((r = Ea (inst, &va)))                       /* decode eff addr */
             return r;
-        if (r = Write (va, A))                          /* write operand */
+        if ((r = Write (va, A)))                        /* write operand */
             return r;
         break;
 
     case STB:
-        if (r = Ea (inst, &va))                         /* decode eff addr */
+        if ((r = Ea (inst, &va)))                       /* decode eff addr */
             return r;
-        if (r = Write (va, B))                          /* write operand */
+        if ((r = Write (va, B)))                        /* write operand */
             return r;
         break;
 
     case STX:
-        if (r = Ea (inst, &va))                         /* decode eff addr */
+        if ((r = Ea (inst, &va)))                       /* decode eff addr */
             return r;
-        if (r = Write (va, X))                          /* write operand */
+        if ((r = Write (va, X)))                        /* write operand */
             return r;
         break;
 
     case EAX:
-        if (r = Ea (inst, &va))                         /* decode eff addr */
+        if ((r = Ea (inst, &va)))                       /* decode eff addr */
             return r;
         if (nml_mode || usr_mode)                       /* normal or user? */
             X = (X & ~VA_MASK) | (va & VA_MASK);        /* only 14b */
@@ -575,11 +575,11 @@ switch (op) {                           
         break;
 
     case XMA:
-        if (r = Ea (inst, &va))                         /* decode eff addr */
+        if ((r = Ea (inst, &va)))                       /* decode eff addr */
             return r;
-        if (r = Read (va, &dat))                        /* get operand */
+        if ((r = Read (va, &dat)))                      /* get operand */
             return r;
-        if (r = Write (va, A))                          /* write A */
+        if ((r = Write (va, A)))                        /* write A */
             return r;
         A = dat;                                        /* load A */
         break;
@@ -587,95 +587,95 @@ switch (op) {                           
 /* Arithmetic and logical */
 
     case ADD:
-        if (r = Ea (inst, &va))                         /* decode eff addr */
+        if ((r = Ea (inst, &va)))                       /* decode eff addr */
             return r;
-        if (r = Read (va, &dat))                        /* get operand */
+        if ((r = Read (va, &dat)))                      /* get operand */
             return r;
         A = Add24 (A, dat, 0);                          /* add */
         break;
 
     case ADC:
-        if (r = Ea (inst, &va))                         /* decode eff addr */
+        if ((r = Ea (inst, &va)))                       /* decode eff addr */
             return r;
-        if (r = Read (va, &dat))                        /* get operand */
+        if ((r = Read (va, &dat)))                      /* get operand */
             return r;
         OV = 0;                                         /* clear overflow */
         A = Add24 (A, dat, X >> 23);                    /* add with carry */
         break;
 
     case SUB:
-        if (r = Ea (inst, &va))                         /* decode eff addr */
+        if ((r = Ea (inst, &va)))                       /* decode eff addr */
             return r;
-        if (r = Read (va, &dat))                        /* get operand */
+        if ((r = Read (va, &dat)))                      /* get operand */
             return r;
         A = Add24 (A, dat ^ DMASK, 1);                  /* subtract */
         break;
 
     case SUC:
-        if (r = Ea (inst, &va))                         /* decode eff addr */
+        if ((r = Ea (inst, &va)))                       /* decode eff addr */
             return r;
-        if (r = Read (va, &dat))                        /* get operand */
+        if ((r = Read (va, &dat)))                      /* get operand */
             return r;
         OV = 0;                                         /* clear overflow */
         A = Add24 (A, dat ^ DMASK, X >> 23);            /* sub with carry */
         break;
 
     case ADM:
-        if (r = Ea (inst, &va))                         /* decode eff addr */
+        if ((r = Ea (inst, &va)))                       /* decode eff addr */
             return r;
-        if (r = Read (va, &dat))                        /* get operand */
+        if ((r = Read (va, &dat)))                      /* get operand */
             return r;
         dat = AddM24 (dat, A);                          /* mem + A */
-        if (r = Write (va, dat))                        /* rewrite */
+        if ((r = Write (va, dat)))                      /* rewrite */
             return r;
         break;
 
     case MIN:
-        if (r = Ea (inst, &va))                         /* decode eff addr */
+        if ((r = Ea (inst, &va)))                       /* decode eff addr */
             return r;
-        if (r = Read (va, &dat))                        /* get operand */
+        if ((r = Read (va, &dat)))                      /* get operand */
             return r;
         dat = AddM24 (dat, 1);                          /* mem + 1 */
-        if (r = Write (va, dat))                        /* rewrite */
+        if ((r = Write (va, dat)))                      /* rewrite */
             return r;
         break;
 
     case MUL:
-        if (r = Ea (inst, &va))                         /* decode eff addr */
+        if ((r = Ea (inst, &va)))                       /* decode eff addr */
             return r;
-        if (r = Read (va, &dat))                        /* get operand */
+        if ((r = Read (va, &dat)))                      /* get operand */
             return r;
         Mul48 (A, dat);                                 /* multiply */
         break;
 
     case DIV:
-        if (r = Ea (inst, &va))                         /* decode eff addr */
+        if ((r = Ea (inst, &va)))                       /* decode eff addr */
             return r;
-        if (r = Read (va, &dat))                        /* get operand */
+        if ((r = Read (va, &dat)))                      /* get operand */
             return r;
         Div48 (A, B, dat);                              /* divide */
         break;
 
     case ETR:
-        if (r = Ea (inst, &va))                         /* decode eff addr */
+        if ((r = Ea (inst, &va)))                       /* decode eff addr */
             return r;
-        if (r = Read (va, &dat))                        /* get operand */
+        if ((r = Read (va, &dat)))                      /* get operand */
             return r;
         A = A & dat;                                    /* and */
         break;
 
     case MRG:
-        if (r = Ea (inst, &va))                         /* decode eff addr */
+        if ((r = Ea (inst, &va)))                       /* decode eff addr */
             return r;
-        if (r = Read (va, &dat))                        /* get operand */
+        if ((r = Read (va, &dat)))                      /* get operand */
             return r;
         A = A | dat;                                    /* or */
         break;
 
     case EOR:
-        if (r = Ea (inst, &va))                         /* decode eff addr */
+        if ((r = Ea (inst, &va)))                       /* decode eff addr */
             return r;
-        if (r = Read (va, &dat))                        /* get operand */
+        if ((r = Read (va, &dat)))                      /* get operand */
             return r;
         A = A ^ dat;                                    /* xor */
         break;
@@ -683,75 +683,75 @@ switch (op) {                           
 /* Skips */
 
     case SKE:
-        if (r = Ea (inst, &va))                         /* decode eff addr */
+        if ((r = Ea (inst, &va)))                       /* decode eff addr */
             return r;
-        if (r = Read (va, &dat))                        /* get operand */
+        if ((r = Read (va, &dat)))                      /* get operand */
             return r;
         if (A == dat)                                   /* if A = op, skip */
             P = (P + 1) & VA_MASK;
         break;
 
     case SKG:
-        if (r = Ea (inst, &va))                         /* decode eff addr */
+        if ((r = Ea (inst, &va)))                       /* decode eff addr */
             return r;
-        if (r = Read (va, &dat))                        /* get operand */
+        if ((r = Read (va, &dat)))                      /* get operand */
             return r;
         if (SXT (A) > SXT (dat))                        /* if A > op, skip */
             P = (P + 1) & VA_MASK;
         break;
 
     case SKM:
-        if (r = Ea (inst, &va))                         /* decode eff addr */
+        if ((r = Ea (inst, &va)))                       /* decode eff addr */
             return r;
-        if (r = Read (va, &dat))                        /* get operand */
+        if ((r = Read (va, &dat)))                      /* get operand */
             return r;
         if (((A ^ dat) & B) == 0)                       /* if A = op masked */
             P = (P + 1) & VA_MASK;
         break;
 
     case SKA:
-        if (r = Ea (inst, &va))                         /* decode eff addr */
+        if ((r = Ea (inst, &va)))                       /* decode eff addr */
             return r;
-        if (r = Read (va, &dat))                        /* get operand */
+        if ((r = Read (va, &dat)))                      /* get operand */
             return r;
         if ((A & dat) == 0)                             /* if !(A & op), skip */
             P = (P + 1) & VA_MASK;
         break;
 
     case SKB:
-        if (r = Ea (inst, &va))                         /* decode eff addr */
+        if ((r = Ea (inst, &va)))                       /* decode eff addr */
             return r;
-        if (r = Read (va, &dat))                        /* get operand */
+        if ((r = Read (va, &dat)))                      /* get operand */
             return r;
         if ((B & dat) == 0)                             /* if !(B & op), skip */
             P = (P + 1) & VA_MASK;
         break;
 
     case SKN:
-        if (r = Ea (inst, &va))                         /* decode eff addr */
+        if ((r = Ea (inst, &va)))                       /* decode eff addr */
             return r;
-        if (r = Read (va, &dat))                        /* get operand */
+        if ((r = Read (va, &dat)))                      /* get operand */
             return r;
         if (dat & SIGN)                                 /* if op < 0, skip */
             P = (P + 1) & VA_MASK;
         break;
 
     case SKR:
-        if (r = Ea (inst, &va))                         /* decode eff addr */
+        if ((r = Ea (inst, &va)))                       /* decode eff addr */
             return r;
-        if (r = Read (va, &dat))                        /* get operand */
+        if ((r = Read (va, &dat)))                      /* get operand */
             return r;
         dat = AddM24 (dat, DMASK);                      /* decr operand */
-        if (r = Write (va, dat))                        /* rewrite */
+        if ((r = Write (va, dat)))                      /* rewrite */
             return r;
         if (dat & SIGN)                                 /* if op < 0, skip */
             P = (P + 1) & VA_MASK;
         break;
 
     case SKD:
-        if (r = Ea (inst, &va))                         /* decode eff addr */
+        if ((r = Ea (inst, &va)))                       /* decode eff addr */
             return r;
-        if (r = Read (va, &dat))                        /* get operand */
+        if ((r = Read (va, &dat)))                      /* get operand */
             return r;
         if (SXT_EXP (B) < SXT_EXP (dat)) {              /* B < dat? */
             X = (dat - B) & DMASK;                      /* X = dat - B */
@@ -774,29 +774,29 @@ switch (op) {                           
         exu_cnt = exu_cnt + 1;                          /* count chained EXU */
         if (exu_cnt > exu_lim)                          /* too many? */
             return STOP_EXULIM;
-        if (r = Ea (inst, &va))                         /* decode eff addr */
+        if ((r = Ea (inst, &va)))                       /* decode eff addr */
             return r;
-        if (r = Read (va, &dat))                        /* get operand */
+        if ((r = Read (va, &dat)))                      /* get operand */
             return r;
         inst = dat;
         goto EXU_LOOP;
  
    case BRU:
         if (nml_mode && (inst & I_IND)) api_dismiss (); /* normal BRU*, dism */
-        if (r = Ea (inst, &va))                         /* decode eff addr */
+        if ((r = Ea (inst, &va)))                       /* decode eff addr */
             return r;
-        if (r = Read (va, &dat))                        /* get operand */
+        if ((r = Read (va, &dat)))                      /* get operand */
             return r;
         PCQ_ENTRY;
         P = va & VA_MASK;                               /* branch */
         break;
 
     case BRX:
-        if (r = Ea (inst, &va))                         /* decode eff addr */
+        if ((r = Ea (inst, &va)))                       /* decode eff addr */
             return r;
         X = (X + 1) & DMASK;                            /* incr X */
         if (X & I_IND) {                                /* bit 9 set? */
-            if (r = Read (va, &dat))                    /* test dest access */
+            if ((r = Read (va, &dat)))                  /* test dest access */
                 return r;
             PCQ_ENTRY;
             P = va & VA_MASK;                           /* branch */
@@ -804,22 +804,22 @@ switch (op) {                           
         break;
 
     case BRM:
-        if (r = Ea (inst, &va))                         /* decode eff addr */
+        if ((r = Ea (inst, &va)))                       /* decode eff addr */
             return r;
         dat = (EM3 << 18) | (EM2 << 15) | pc;           /* form return word */
         if (!nml_mode && !usr_mode)                     /* monitor mode? */
             dat = dat | (mode << 23) | (OV << 21);
         else dat = dat | (OV << 23);                    /* normal or user */
-        if (r = Write (va, dat))                        /* write ret word */
+        if ((r = Write (va, dat)))                      /* write ret word */
             return r;
         PCQ_ENTRY;
         P = (va + 1) & VA_MASK;                         /* branch */
         break;
 
     case BRR:
-        if (r = Ea (inst, &va))                         /* decode eff addr */
+        if ((r = Ea (inst, &va)))                       /* decode eff addr */
             return r;
-        if (r = Read (va, &dat))                        /* get operand */
+        if ((r = Read (va, &dat)))                      /* get operand */
             return r;
         PCQ_ENTRY;
         P = (dat + 1) & VA_MASK;                        /* branch */
@@ -837,9 +837,9 @@ switch (op) {                           
     case BRI:
         if (!nml_mode && usr_mode)                      /* priv inst */
             return MM_PRVINS;
-        if (r = Ea (inst, &va))                         /* decode eff addr */
+        if ((r = Ea (inst, &va)))                       /* decode eff addr */
             return r;
-        if (r = Read (va, &dat))                        /* get operand */
+        if ((r = Read (va, &dat)))                      /* get operand */
             return r;
         api_dismiss ();                                 /* dismiss hi api */
         PCQ_ENTRY;
@@ -909,7 +909,7 @@ switch (op) {                           
 /* Shifts */
 
     case RSH:
-        if (r = EaSh (inst, &va))                       /* decode eff addr */
+        if ((r = EaSh (inst, &va)))                     /* decode eff addr */
             return r;
         shf_op = I_GETSHFOP (va);                       /* get eff op */
         sc = va & I_SHFMSK;                             /* get eff count */
@@ -934,7 +934,7 @@ switch (op) {                           
         break;
 
     case LSH:
-        if (r = EaSh (inst, &va))                       /* decode eff addr */
+        if ((r = EaSh (inst, &va)))                     /* decode eff addr */
             return r;
         shf_op = I_GETSHFOP (va);                       /* get eff op */
         sc = va & I_SHFMSK;                             /* get eff count */
@@ -989,11 +989,11 @@ switch (op) {                           
     case MIW: case MIY:
         if (!nml_mode && usr_mode)                      /* priv inst */
             return MM_PRVINS;
-        if (r = Ea (inst, &va))                         /* decode eff addr */
+        if ((r = Ea (inst, &va)))                       /* decode eff addr */
             return r;
-        if (r = Read (va, &dat))                        /* get operand */
+        if ((r = Read (va, &dat)))                      /* get operand */
             return r;
-        if (r = op_miwy (inst, dat))                    /* process inst */
+        if ((r = op_miwy (inst, dat)))                  /* process inst */
             return r;
         int_reqhi = api_findreq ();                     /* recalc int req */
         chan_req = chan_testact ();                     /* recalc chan act */
@@ -1002,11 +1002,11 @@ switch (op) {                           
     case WIM: case YIM:
         if (!nml_mode && usr_mode)                      /* priv inst */
             return MM_PRVINS;
-        if (r = Ea (inst, &va))                         /* decode eff addr */
+        if ((r = Ea (inst, &va)))                       /* decode eff addr */
             return r;
-        if (r = op_wyim (inst, &dat))                   /* process inst */
+        if ((r = op_wyim (inst, &dat)))                 /* process inst */
             return r;
-        if (r = Write (va, dat))
+        if ((r = Write (va, dat)))
             return r;                                   /* write result */
         int_reqhi = api_findreq ();                     /* recalc int req */
         chan_req = chan_testact ();                     /* recalc chan act */
@@ -1015,7 +1015,7 @@ switch (op) {                           
     case EOM: case EOD:
         if (!nml_mode && usr_mode)                      /* priv inst */
             return MM_PRVINS;
-        if (r = op_eomd (inst))                         /* process inst */
+        if ((r = op_eomd (inst)))                       /* process inst */
             return r;
         int_reqhi = api_findreq ();                     /* recalc int req */
         chan_req = chan_testact ();                     /* recalc chan act */
@@ -1025,11 +1025,11 @@ switch (op) {                           
     case POT:
         if (!nml_mode && usr_mode)                      /* priv inst */
             return MM_PRVINS;
-        if (r = Ea (inst, &va))                         /* decode eff addr */
+        if ((r = Ea (inst, &va)))                       /* decode eff addr */
             return r;
-        if (r = Read (va, &dat))                        /* get operand */
+        if ((r = Read (va, &dat)))                      /* get operand */
             return r;
-        if (r = op_pot (dat))                           /* process inst */
+        if ((r = op_pot (dat)))                         /* process inst */
             return r;
         int_reqhi = api_findreq ();                     /* recalc int req */
         chan_req = chan_testact ();                     /* recalc chan act */
@@ -1038,11 +1038,11 @@ switch (op) {                           
     case PIN:
         if (!nml_mode && usr_mode)                      /* priv inst */
             return MM_PRVINS;
-        if (r = Ea (inst, &va))                         /* decode eff addr */
+        if ((r = Ea (inst, &va)))                       /* decode eff addr */
             return r;
-        if (r = op_pin (&dat))                          /* process inst */
+        if ((r = op_pin (&dat)))                        /* process inst */
             return r;
-        if (r = Write (va, dat))                        /* write result */
+        if ((r = Write (va, dat)))                      /* write result */
             return r;
         int_reqhi = api_findreq ();                     /* recalc int req */
         chan_req = chan_testact ();                     /* recalc chan act */
@@ -1051,7 +1051,7 @@ switch (op) {                           
     case SKS:
         if (!nml_mode && usr_mode)                      /* priv inst */
             return MM_PRVINS;
-        if (r = op_sks (inst, &dat))                    /* process inst */
+        if ((r = op_sks (inst, &dat)))                  /* process inst */
             return r;
         if (dat)
             P = (P + 1) & VA_MASK;
@@ -1085,7 +1085,7 @@ for (i = 0; i < ind_lim; i++) {         
             hst[hst_p].ea = *addr;
         return SCPE_OK;
         }
-    if (r = Read (va, &wd))                             /* read ind; fails? */
+    if ((r = Read (va, &wd)))                           /* read ind; fails? */
         return r;
     va = (va & VA_USR) | (wd & XVA_MASK);
     }
@@ -1112,7 +1112,7 @@ for (i = 0; i < ind_lim; i++) {         
         }
     if (wd & I_IDX)
         va = (va & VA_USR) | ((va + X) & VA_MASK);
-    if (r = Read (va, &wd))                             /* read ind; fails? */
+    if ((r = Read (va, &wd)))                           /* read ind; fails? */
         return r;
     va = (va & VA_USR) | (wd & XVA_MASK);
     }
@@ -1341,7 +1341,7 @@ if (sc >= 24) {
     A = sgn;
     }
 else {
-    B = ((B >> sc) | (A << (24 - sc)) & DMASK);
+    B = ((B >> sc) | (A << (24 - sc))) & DMASK;
     A = ((A >> sc) | (sgn << (24 - sc))) & DMASK;
     }
 return;
@@ -1569,12 +1569,12 @@ if (op == MIN)                          
 else if (op == SKR)                                     /* decr */
     val = DMASK;
 else return STOP_RTCINS;                                /* can't do it */
-if (r = Ea (inst, &va))                                 /* decode eff addr */
+if ((r = Ea (inst, &va)))                               /* decode eff addr */
     return r;
-if (r = Read (va, &dat))                                /* get operand */
+if ((r = Read (va, &dat)))                              /* get operand */
     return r;
 dat = AddM24 (dat, val);                                /* mem +/- 1 */
-if (r = Write (va, dat))                                /* rewrite */
+if ((r = Write (va, dat)))                              /* rewrite */
     return r;
 if (dat == 0)                                           /* set clk sync int */
     int_req = int_req | INT_RTCS;
