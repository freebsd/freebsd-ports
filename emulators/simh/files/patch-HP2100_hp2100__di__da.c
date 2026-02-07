--- HP2100/hp2100_di_da.c.orig	2016-12-01 22:43:42 UTC
+++ HP2100/hp2100_di_da.c
@@ -1215,7 +1215,7 @@ if (GET_BUSADR (da_unit [unitno].flags) 
 if (ibl_copy (da_rom, da_dib.select_code))                  /* copy the boot ROM to memory and configure */
     return SCPE_IERR;                                       /* return an internal error if the copy failed */
 
-SR = SR & (IBL_OPT | IBL_DS_HEAD)                           /* set S to a reasonable value */
+SR = (SR & (IBL_OPT | IBL_DS_HEAD))                         /* set S to a reasonable value */
   | IBL_DS | IBL_MAN | (da_dib.select_code << IBL_V_DEV);   /*   before boot execution */
 
 return SCPE_OK;
@@ -1594,10 +1594,10 @@ if (di [da].bus_cntl & BUS_ATN) {       
                 da_unit [unit].wait = icd_cntlr [unit].cmd_time;    /* these are always scheduled and */
                 initiated = TRUE;                                   /*   logged as initiated */
 
-                if (if_state [unit] == read_wait                    /* if we're waiting for a send data secondary */
-                  && message_address != 0x00                        /*   but it's not there */
-                  || if_state [unit] == status_wait                 /* or a send status secondary, */
-                  && message_address != 0x08)                       /*   but it's not there */
+                if ((if_state [unit] == read_wait                   /* if we're waiting for a send data secondary */
+                  && message_address != 0x00)                       /*   but it's not there */
+                  || (if_state [unit] == status_wait                /* or a send status secondary, */
+                  && message_address != 0x08))                      /*   but it's not there */
                     abort_command (unit, io_program_error,          /*   then abort the pending command */
                                    idle);                           /*   and process the new command */
 
@@ -1738,7 +1738,7 @@ else {                                  
 
             put_buffer_byte (&icd_cntlr [unit], data);      /* add the byte to the buffer */
 
-            if (icd_cntlr [unit].length == 0)               /* is this the last parameter? */
+            if (icd_cntlr [unit].length == 0) {             /* is this the last parameter? */
                 if (di [da].bus_cntl & BUS_EOI)             /* does the host agree? */
                     initiated = start_command (unit);       /* start the command and log the initiation */
 
@@ -1747,6 +1747,7 @@ else {                                  
                                    error_sink);             /*   any additional parameter bytes */
                     initiated = TRUE;                       /* log the abort initiation */
                     }
+            }
             break;
 
 
@@ -1787,14 +1788,14 @@ if (accepted && DEBUG_PRI (da_dev, DEB_X
 if (da_unit [unit].wait > 0)                            /* was service requested? */
     activate_unit (&da_unit [unit]);                    /* schedule the unit */
 
-if (initiated && DEBUG_PRI (da_dev, DEB_RWSC))
+if (initiated && DEBUG_PRI (da_dev, DEB_RWSC)) {
     if (if_command [unit] == disc_command)
         fprintf (sim_deb, ">>DA rwsc: Unit %d position %d %s disc command initiated\n",
                  unit, da_unit [unit].pos, dl_opcode_name (ICD, icd_cntlr [unit].opcode));
     else
         fprintf (sim_deb, ">>DA rwsc: Unit %d %s command initiated\n",
                  unit, if_command_name [if_command [unit]]);
-
+}
 return accepted;                                        /* indicate the acceptance condition */
 }
 
