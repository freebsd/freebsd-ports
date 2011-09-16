--- qemu/hw/ide/ahci.c.prev	2011-09-11 16:39:53.000000000 +0300
+++ qemu/hw/ide/ahci.c	2011-09-11 16:39:48.000000000 +0300
@@ -505,10 +505,7 @@ static void ahci_reset_port(AHCIState *s
     ide_bus_reset(&d->port);
     ide_state->ncq_queues = AHCI_MAX_CMDS;
 
-    pr->irq_stat = 0;
-    pr->irq_mask = 0;
     pr->scr_stat = 0;
-    pr->scr_ctl = 0;
     pr->scr_err = 0;
     pr->scr_act = 0;
     d->busy_slot = -1;
@@ -1157,12 +1154,17 @@ void ahci_uninit(AHCIState *s)
 void ahci_reset(void *opaque)
 {
     struct AHCIPCIState *d = opaque;
+    AHCIPortRegs *pr;
     int i;
 
     d->ahci.control_regs.irqstatus = 0;
     d->ahci.control_regs.ghc = 0;
 
     for (i = 0; i < d->ahci.ports; i++) {
+        pr = &d->ahci.dev[i].port_regs;
+        pr->irq_stat = 0;
+        pr->irq_mask = 0;
+        pr->scr_ctl = 0;
         ahci_reset_port(&d->ahci, i);
     }
 }
