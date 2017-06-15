--- I1401/i1401_cpu.c.orig	2016-12-01 22:43:42 UTC
+++ I1401/i1401_cpu.c
@@ -547,7 +547,7 @@ while (reason == 0) {                   
 
     saved_IS = IS;                                      /* commit prev instr */
     if (sim_interval <= 0) {                            /* check clock queue */
-        if (reason = sim_process_event ())
+        if ((reason = sim_process_event ()))
             break;
         }
 
@@ -1039,7 +1039,7 @@ CHECK_LENGTH:
 */
 
     case OP_R:                                          /* read */
-        if (reason = iomod (ilnt, D, r_mod))            /* valid modifier? */
+        if ((reason = iomod (ilnt, D, r_mod)))          /* valid modifier? */
             break;
         reason = read_card (ilnt, D);                   /* read card */
         BS = CDR_BUF + CDR_WIDTH;
@@ -1049,7 +1049,7 @@ CHECK_LENGTH:
         break;
 
     case OP_W:                                          /* write */
-        if (reason = iomod (ilnt, D, w_mod))            /* valid modifier? */
+        if ((reason = iomod (ilnt, D, w_mod)))          /* valid modifier? */
             break;
         reason = write_line (ilnt, D);                  /* print line */
         BS = LPT_BUF + LPT_WIDTH;
@@ -1059,7 +1059,7 @@ CHECK_LENGTH:
         break;
 
     case OP_P:                                          /* punch */
-        if (reason = iomod (ilnt, D, p_mod))            /* valid modifier? */
+        if ((reason = iomod (ilnt, D, p_mod)))          /* valid modifier? */
             break;
         reason = punch_card (ilnt, D);                  /* punch card */
         BS = CDP_BUF + CDP_WIDTH;
@@ -1069,7 +1069,7 @@ CHECK_LENGTH:
         break;
 
     case OP_WR:                                         /* write and read */
-        if (reason = iomod (ilnt, D, w_mod))            /* valid modifier? */
+        if ((reason = iomod (ilnt, D, w_mod)))          /* valid modifier? */
             break;
         reason = write_line (ilnt, D);                  /* print line */
         r1 = read_card (ilnt, D);                       /* read card */
@@ -1082,7 +1082,7 @@ CHECK_LENGTH:
         break;
 
     case OP_WP:                                         /* write and punch */
-        if (reason = iomod (ilnt, D, w_mod))            /* valid modifier? */
+        if ((reason = iomod (ilnt, D, w_mod)))          /* valid modifier? */
             break;
         reason = write_line (ilnt, D);                  /* print line */
         r1 = punch_card (ilnt, D);                      /* punch card */
@@ -1095,7 +1095,7 @@ CHECK_LENGTH:
         break;
 
     case OP_RP:                                         /* read and punch */
-        if (reason = iomod (ilnt, D, NULL))             /* valid modifier? */
+        if ((reason = iomod (ilnt, D, NULL)))           /* valid modifier? */
             break;
         reason = read_card (ilnt, D);                   /* read card */
         r1 = punch_card (ilnt, D);                      /* punch card */
@@ -1108,7 +1108,7 @@ CHECK_LENGTH:
         break;
 
     case OP_WRP:                                        /* write, read, punch */
-        if (reason = iomod (ilnt, D, w_mod))            /* valid modifier? */
+        if ((reason = iomod (ilnt, D, w_mod)))          /* valid modifier? */
             break;
         reason = write_line (ilnt, D);                  /* print line */
         r1 = read_card (ilnt, D);                       /* read card */
@@ -1122,9 +1122,9 @@ CHECK_LENGTH:
         break;
 
     case OP_SS:                                         /* select stacker */
-        if (reason = iomod (ilnt, D, ss_mod))           /* valid modifier? */
+        if ((reason = iomod (ilnt, D, ss_mod)))         /* valid modifier? */
             break;
-        if (reason = select_stack (D))                  /* sel stack, error? */
+        if ((reason = select_stack (D)))                /* sel stack, error? */
             break;
         if ((ilnt == 4) || (ilnt == 5)) {               /* check for branch */
             BRANCH;
@@ -1132,7 +1132,7 @@ CHECK_LENGTH:
         break;
 
     case OP_CC:                                         /* carriage control */
-        if (reason = carriage_control (D))              /* car ctrl, error? */
+        if ((reason = carriage_control (D)))            /* car ctrl, error? */
             break;
         if ((ilnt == 4) || (ilnt == 5)) {               /* check for branch */
             BRANCH;
@@ -1154,7 +1154,7 @@ CHECK_LENGTH:
             reason = STOP_INVL;
         else if (ioind != BCD_PERCNT)                   /* valid dev addr? */
             reason = STOP_INVA;
-        else if (reason = iomod (ilnt, D, mtf_mod))     /* valid modifier? */
+        else if ((reason = iomod (ilnt, D, mtf_mod)))   /* valid modifier? */
             break;
         if (dev == IO_MT)                               /* BCD? */
             reason = mt_func (unit, 0, D);
