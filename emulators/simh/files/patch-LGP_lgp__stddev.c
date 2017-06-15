--- LGP/lgp_stddev.c.orig	2016-12-01 22:43:42 UTC
+++ LGP/lgp_stddev.c
@@ -394,7 +394,7 @@ t_stat ttr_svc (UNIT *uptr)
 {
 t_stat r;
 
-if (r = read_reader (uptr, ttr_stopioe, (int32 *) &tti_buf))
+if ((r = read_reader (uptr, ttr_stopioe, (int32 *) &tti_buf)))
     return r;
 if (!(uptr->flags & UNIT_NOCS) &&                       /* cstop enable? */
     (tti_buf == FLEX_CSTOP))                            /* cond stop? */
@@ -415,7 +415,7 @@ t_stat ptr_svc (UNIT *uptr)
 {
 t_stat r;
 
-if (r = read_reader (uptr, ptr_stopioe, &uptr->buf))
+if ((r = read_reader (uptr, ptr_stopioe, &uptr->buf)))
     return r;
 if (uptr->buf == FLEX_CSTOP)                            /* cond stop? */
     inp_done = 1;
@@ -548,7 +548,7 @@ else {
         ch = '\b';
     else ch = flex_to_ascii[flex | (tto_uc << 6)];      /* cvt flex to ascii */
     if (ch > 0) {                                       /* legit? */
-        if (r = sim_putchar_s (ch))                     /* write char */
+        if ((r = sim_putchar_s (ch)))                   /* write char */
             return r;
         tto_unit[0].pos = tto_unit[0].pos + 1;
         if (flex == FLEX_CR) {                          /* cr? */
