--- HP2100/hp2100_di.c.orig	2016-12-01 22:43:42 UTC
+++ HP2100/hp2100_di.c
@@ -607,13 +607,13 @@ while (working_set) {
                 else if (di_card->cntl_register & CNTL_NRFD)    /* NRFD was set but is not now? */
                     deny |= BUS_NRFD;                           /* deny NRFD on the bus */
 
-                if (FIFO_FULL)                                  /* is the FIFO full? */
+                if (FIFO_FULL) {                                /* is the FIFO full? */
                     if (data & CNTL_LSTN)                       /* is card now listening? */
                         assert |= BUS_NRFD;                     /* listener and a full FIFO asserts NRFD */
 
                     else if (di_card->cntl_register & CNTL_LSTN)    /* was card a listener but is not now? */
                         deny |= BUS_NRFD;                           /* deny NRFD on the bus */
-
+                }
 
                 if (SW8_SYSCTL) {                           /* system controller drives REN and IFC */
                     if (data & CNTL_REN)                    /* REN control */
@@ -1452,14 +1452,14 @@ if (di_card->bus_cntl & BUS_IFC         
     }
 
 
-if (di_card->cntl_register & CNTL_LSTN)                 /* is the card a listener? */
+if (di_card->cntl_register & CNTL_LSTN) {               /* is the card a listener? */
     if (di_card->cntl_register & CNTL_NRFD              /* if explicitly requested */
       || di_card->status_register & STAT_LBI            /*   or the last byte is in */
       || FIFO_FULL)                                     /*   or the FIFO is full */
         assert = BUS_NRFD;                              /*   then assert NRFD */
     else                                                /* otherwise the card is ready for data */
         deny |= BUS_NRFD;                               /*   so deny NRFD */
-
+  }
 if (assert != deny)                                     /* was there any change in bus state? */
     di_bus_control (card, CONTROLLER, assert, deny);    /* update the bus control */
 
@@ -1813,7 +1813,7 @@ if (tag & TAG_EDT                       
 
 if (access == cpu_access) {                             /* is this a cpu access? */
     if (!(di_card->cntl_register & CNTL_PACK))          /*   in unpacked mode? */
-        data = data & ~(DATA_ATN | DATA_EOI)            /* substitute the ATN/EOI tag values */
+        data = (data & ~(DATA_ATN | DATA_EOI))          /* substitute the ATN/EOI tag values */
           | (tag & (TAG_ATN | TAG_EOI)) >> DATA_SHIFT;  /*   into the data word */
 
     if (tag & TAG_LBR)                                  /* is this the last byte? */
@@ -1856,25 +1856,25 @@ if (DEBUG_PRJ (dptrs [card], DEB_BUF)) {
     }
 
 
-if (di_card->cntl_register & CNTL_TALK)                 /* is the card talking? */
-    if (di_card->cntl_register & CNTL_PACK)             /* is it in the packed mode? */
+if (di_card->cntl_register & CNTL_TALK) {                 /* is the card talking? */
+    if (di_card->cntl_register & CNTL_PACK) {           /* is it in the packed mode? */
         if (di_card->status_register & STAT_LBO         /* yes, is the last byte out? */
           && di_card->cntl_register & CNTL_EOI)         /*   and is EOI control enabled? */
             di_card->bus_cntl |= BUS_EOI;               /* assert EOI on the bus */
         else
             di_card->bus_cntl &= ~BUS_EOI;              /* deny EOI on the bus */
-
+         }
     else {                                              /* the card is in the unpacked mode */
         if (di_card->cntl_register & CNTL_CIC)          /* is the card the controller in charge? */
             di_card->bus_cntl =                         /* assert or deny the ATN bus line */
-              di_card->bus_cntl & ~BUS_ATN              /*   from the ATN tag value */
+              (di_card->bus_cntl & ~BUS_ATN)             /*   from the ATN tag value */
               | (tag & TAG_ATN) >> BUS_SHIFT;
 
         di_card->bus_cntl =                             /* assert or deny the EOI bus line */
-          di_card->bus_cntl & ~BUS_EOI                  /*   from the EOI tag value */
+          (di_card->bus_cntl & ~BUS_EOI)                /*   from the EOI tag value */
           | (tag & TAG_EOI) >> BUS_SHIFT;
         }
-
+   }
 return (uint16) data;                                   /* return the data value */
 }
 
