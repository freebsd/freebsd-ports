--- src/sndhrdw/nes_apu.c.orig	2003-05-04 18:39:04 UTC
+++ src/sndhrdw/nes_apu.c
@@ -980,6 +980,9 @@ void apu_process(void *buffer, int num_s
    uint32 elapsed_cycles;
    static int32 prev_sample = 0;
    int32 next_sample, accum;
+   uint8 *buff_u8 = (uint8 *)buffer;
+   int16 *buff_16 = (int16 *)buffer;
+
 
    ASSERT(apu);
 
@@ -1035,9 +1038,9 @@ void apu_process(void *buffer, int num_s
 
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
