--- src/sndhrdw/nes_apu.c.orig 2007-10-30 22:51:03.000000000 +0100
+++ src/sndhrdw/nes_apu.c      2007-10-30 22:52:28.000000000 +0100
@@ -980,6 +980,9 @@
    uint32 elapsed_cycles;
    static int32 prev_sample = 0;
    int32 next_sample, accum;
+   uint8 *buff_u8 = (uint8 *)buffer;
+   int16 *buff_16 = (int16 *)buffer;
+
 
    ASSERT(apu);
 
@@ -1035,9 +1038,9 @@
 
       /* signed 16-bit output, unsigned 8-bit */
       if (16 == apu->sample_bits)
-         *((int16 *) buffer)++ = (int16) accum;
-      else
-         *((uint8 *) buffer)++ = (accum >> 8) ^ 0x80;
+         *buff_16++ = (int16) accum;
+      else 
+         *buff_u8++ = (accum >> 8) ^0x80;
    }
 
    /* resync cycle counter */
