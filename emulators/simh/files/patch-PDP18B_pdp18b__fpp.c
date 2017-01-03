--- PDP18B/pdp18b_fpp.c.orig	2016-12-01 22:43:42 UTC
+++ PDP18B/pdp18b_fpp.c
@@ -253,7 +253,7 @@ switch (fop) {                          
         break;
 
     case FOP_SUB:                                       /* subtract */
-        if (sta = fp15_opnd (fir, ar, &fmb))            /* fetch op to FMB */
+        if ((sta = fp15_opnd (fir, ar, &fmb)))          /* fetch op to FMB */
             break;
         if (fir & FI_FP)                                /* fp? */
             sta = fp15_fadd (fir, &fma, &fmb, 1);       /* yes, fp sub */
@@ -262,7 +262,7 @@ switch (fop) {                          
 
     case FOP_RSUB:                                      /* reverse sub */
         fmb = fma;                                      /* FMB <- FMA */
-        if (sta = fp15_opnd (fir, ar, &fma))            /* fetch op to FMA */
+        if ((sta = fp15_opnd (fir, ar, &fma)))          /* fetch op to FMA */
             break;
         if (fir & FI_FP)                                /* fp? */
             sta = fp15_fadd (fir, &fma, &fmb, 1);       /* yes, fp sub */
@@ -270,7 +270,7 @@ switch (fop) {                          
         break;
 
     case FOP_MUL:                                       /* multiply */
-        if (sta = fp15_opnd (fir, ar, &fmb))            /* fetch op to FMB */
+        if ((sta = fp15_opnd (fir, ar, &fmb)))          /* fetch op to FMB */
             break;
         if (fir & FI_FP)                                /* fp? */
             sta = fp15_fmul (fir, &fma, &fmb);          /* yes, fp mul */
@@ -278,9 +278,9 @@ switch (fop) {                          
         break;
 
     case FOP_DIV:                                       /* divide */
-        if (sta = fp15_opnd (fir, ar, &fmb))            /* fetch op to FMB */
+        if ((sta = fp15_opnd (fir, ar, &fmb)))          /* fetch op to FMB */
             break;
-        if (sta = fp15_opnd (fir, ar, &fmb)) break;     /* fetch op to FMB */
+        if ((sta = fp15_opnd (fir, ar, &fmb))) break;   /* fetch op to FMB */
         if (fir & FI_FP)                                /* fp? */
             sta = fp15_fdiv (fir, &fma, &fmb);          /* yes, fp div */
         else sta = fp15_idiv (fir, &fma, &fmb);         /* no, int div */
@@ -288,7 +288,7 @@ switch (fop) {                          
 
     case FOP_RDIV:                                      /* reverse divide */
         fmb = fma;                                      /* FMB <- FMA */
-        if (sta = fp15_opnd (fir, ar, &fma))            /* fetch op to FMA */
+        if ((sta = fp15_opnd (fir, ar, &fma)))          /* fetch op to FMA */
             break;
         if (fir & FI_FP)                                /* fp? */
             sta = fp15_fdiv (fir, &fma, &fmb);          /* yes, fp div */
@@ -296,7 +296,7 @@ switch (fop) {                          
         break;
 
     case FOP_LD:                                        /* load */
-        if (sta = fp15_opnd (fir, ar, &fma))            /* fetch op to FMA */
+        if ((sta = fp15_opnd (fir, ar, &fma)))          /* fetch op to FMA */
             break;
         fp15_asign (fir, &fma);                         /* modify A sign */
         if (fir & FI_FP)                                /* fp? */
@@ -309,7 +309,7 @@ switch (fop) {                          
         break;
 
     case FOP_FLT:                                       /* float */
-        if (sta = fp15_opnd (fir, ar, &fma))            /* fetch op to FMA */
+        if ((sta = fp15_opnd (fir, ar, &fma)))          /* fetch op to FMA */
             break;
         fma.exp = 35;
         fp15_asign (fir, &fma);                         /* adjust A sign */
@@ -317,13 +317,13 @@ switch (fop) {                          
         break;
 
     case FOP_FIX:                                       /* fix */
-        if (sta = fp15_opnd (fir, ar, &fma))            /* fetch op to FMA */
+        if ((sta = fp15_opnd (fir, ar, &fma)))          /* fetch op to FMA */
             break;
         sta = fp15_fix (fir, &fma);                     /* fix */
         break;
 
     case FOP_LFMQ:                                      /* load FMQ */
-        if (sta = fp15_opnd (fir, ar, &fma))            /* fetch op to FMA */
+        if ((sta = fp15_opnd (fir, ar, &fma)))            /* fetch op to FMA */
             break;
         dp_swap (&fma, &fmq);                           /* swap FMA, FMQ */
         fp15_asign (fir, &fma);                         /* adjust A sign */
@@ -337,7 +337,7 @@ switch (fop) {                          
             sta = Write (ar, dat, WR);
             }
         else {                                          /* no, load */
-            if (sta = Read (ar, &dat, RD))
+            if ((sta = Read (ar, &dat, RD)))
                 break;
             fguard = (dat >> JEA_V_GUARD) & 1;
             jea = dat & JEA_EAMASK;
@@ -345,7 +345,7 @@ switch (fop) {                          
         break;
 
     case FOP_ADD:                                       /* add */
-        if (sta = fp15_opnd (fir, ar, &fmb))            /* fetch op to FMB */
+        if ((sta = fp15_opnd (fir, ar, &fmb)))          /* fetch op to FMB */
             break;
         if (fir & FI_FP)                                /* fp? */
             sta = fp15_fadd (fir, &fma, &fmb, 0);       /* yes, fp add */
@@ -429,7 +429,7 @@ t_stat sta;
 
 fguard = 0;                                             /* clear guard */
 if (ir & FI_FP) {                                       /* fp? */
-    if (sta = fp15_norm (ir, a, NULL, 0))               /* normalize */
+    if ((sta = fp15_norm (ir, a, NULL, 0)))             /* normalize */
         return sta;
     if (ir & FI_DP) {                                   /* dp? */
         wd[0] = a->exp & DMASK;                         /* exponent */
