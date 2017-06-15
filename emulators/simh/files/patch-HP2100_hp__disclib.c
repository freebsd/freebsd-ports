--- HP2100/hp_disclib.c.orig	2016-12-01 22:43:42 UTC
+++ HP2100/hp_disclib.c
@@ -761,8 +761,8 @@ else {                                  
     uptr = units + unit_limit;                          /*     and we use the indicated unit */
     }
 
-if (props->unit_check && !uptr                                  /* if the unit number is checked and is invalid */
-  || props->seek_wait && (drive_status (uptr) & DL_S2STOPS)) {  /*   or if we're waiting for an offline drive */
+if ((props->unit_check && !uptr)                                /* if the unit number is checked and is invalid */
+  || (props->seek_wait && (drive_status (uptr) & DL_S2STOPS))) {/*   or if we're waiting for an offline drive */
     dl_end_command (cvptr, status_2_error);                     /*     then the command ends with a Status-2 error */
     uptr = NULL;                                                /* prevent the command from starting */
     }
@@ -1563,7 +1563,7 @@ t_stat dl_load_unload (CVPTR cvptr, UNIT
 if ((uptr->flags & UNIT_ATT) == 0)                      /* the unit must be attached to [un]load */
     return SCPE_UNATT;                                  /* return "Unit not attached" if not */
 
-else if (!(sim_switches & SIM_SW_REST))                 /* modify the flags only if not restoring */
+else if (!(sim_switches & SIM_SW_REST)) {               /* modify the flags only if not restoring */
     if (load) {                                         /* are we loading the heads? */
         uptr->flags = uptr->flags & ~UNIT_UNLOAD;       /* clear the unload flag */
         uptr->STAT = DL_S2FS;                           /*   and set First Status */
@@ -1576,7 +1576,7 @@ else if (!(sim_switches & SIM_SW_REST)) 
         uptr->flags = uptr->flags | UNIT_UNLOAD;        /* set the unload flag */
         uptr->STAT = DL_S2ATN;                          /*   and Attention status */
         }
-
+    }
 return SCPE_OK;
 }
 
@@ -1897,7 +1897,7 @@ static void start_write (CVPTR cvptr, UN
 const t_bool verify = (CNTLR_OPCODE) uptr->OP == write; /* only Write verifies the sector address */
 
 if ((uptr->flags & UNIT_WPROT)                          /* is the unit write protected, */
-  || !verify && !(uptr->flags & UNIT_FMT))              /*   or is formatting required but not enabled? */
+  || (!verify && !(uptr->flags & UNIT_FMT)))            /*   or is formatting required but not enabled? */
     dl_end_command (cvptr, status_2_error);             /* terminate the write with an error */
 
 else if (position_sector (cvptr, uptr, verify)) {       /* writing is permitted; position the sector */
@@ -2041,11 +2041,12 @@ if (cvptr->eoc == SET)                  
                    (CNTLR_OPCODE) uptr->OP,                     /*   with the current operation */
                    (CNTLR_PHASE) uptr->PHASE);                  /*     and phase unchanged */
 
-        if (uptr->STAT & DL_S2SC)                               /* did a seek check occur? */
+        if (uptr->STAT & DL_S2SC) {                             /* did a seek check occur? */
             if (cvptr->type == ICD)                             /* is this ICD controller? */
                 dl_end_command (cvptr, end_of_cylinder);        /* report it as an End of Cylinder error */
             else                                                /* it is a MAC controller */
                 dl_end_command (cvptr, status_2_error);         /* report it as a Status-2 error */
+            }
         }
 
     else                                                        /* the file mask does not permit an auto-seek */
@@ -2291,12 +2292,13 @@ return;
 
 static void set_timer (CVPTR cvptr, FLIP_FLOP action)
 {
-if (cvptr->type == MAC)                                 /* is this a MAC controller? */
+if (cvptr->type == MAC) {                               /* is this a MAC controller? */
     if (action == SET)                                  /* should we start the timer? */
         sim_activate_abs (cvptr->aux + timer,           /* activate the auxiliary unit */
                           cvptr->wait_time);
     else                                                /* we stop the timer */
         sim_cancel (cvptr->aux + timer);                /*   by canceling the unit */
+}
 return;
 }
 
