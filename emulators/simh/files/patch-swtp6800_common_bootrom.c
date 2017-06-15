--- swtp6800/common/bootrom.c.orig	2016-12-01 22:43:43 UTC
+++ swtp6800/common/bootrom.c
@@ -144,7 +144,7 @@ t_stat BOOTROM_config (UNIT *uptr, int32
     if (val == UNIT_NONE)
         BOOTROM_unit.capac = 0;         /* set EPROM size */
     else
-        BOOTROM_unit.capac = 0x200 << (val >> UNIT_V_MSIZE) - 1; /* set EPROM size */
+        BOOTROM_unit.capac = 0x200 << ((val >> UNIT_V_MSIZE) - 1); /* set EPROM size */
     if (BOOTROM_unit.filebuf) {         /* free buffer */
         free (BOOTROM_unit.filebuf);
         BOOTROM_unit.filebuf = NULL;
