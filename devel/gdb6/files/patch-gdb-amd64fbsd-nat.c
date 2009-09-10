--- gdb/amd64fbsd-nat.c.orig	2005-12-17 17:33:59.000000000 -0500
+++ gdb/amd64fbsd-nat.c	2009-09-10 02:29:33.000000000 -0400
@@ -125,10 +125,12 @@
   regcache_raw_supply (regcache, 13, &pcb->pcb_r13);
   regcache_raw_supply (regcache, 14, &pcb->pcb_r14);
   regcache_raw_supply (regcache, 15, &pcb->pcb_r15);
+#if defined(__FreeBSD_version) && __FreeBSD_version < 800000
   regcache_raw_supply (regcache, AMD64_DS_REGNUM, &pcb->pcb_ds);
   regcache_raw_supply (regcache, AMD64_ES_REGNUM, &pcb->pcb_es);
   regcache_raw_supply (regcache, AMD64_FS_REGNUM, &pcb->pcb_fs);
   regcache_raw_supply (regcache, AMD64_GS_REGNUM, &pcb->pcb_gs);
+#endif
 
   return 1;
 }
