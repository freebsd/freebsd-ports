--- avr.c.orig	2017-03-30 13:30:41 UTC
+++ avr.c
@@ -1058,7 +1058,40 @@ int avr_signature(PROGRAMMER * pgm, AVRPART * p)
   return 0;
 }
 
+uint8_t get_fuse_bitmask(AVRMEM * m) {
+  uint8_t bitmask_r = 0;
+  uint8_t bitmask_w = 0;
+  int i, j;
 
+  if (m->size > 1) {
+    // not a fuse, compare bytes directly
+    return 0xFF;
+  }
+
+  for (i=0; i<AVR_OP_MAX; i++) {
+    if (m->op[i] && i == AVR_OP_READ) {
+      for (j=7; j>=0; j--) {
+        bitmask_r |= (m->op[i]->bit[j].type != AVR_CMDBIT_IGNORE) << j;
+      }
+    }
+    if (m->op[i] && i == AVR_OP_WRITE) {
+      for (j=7; j>=0; j--) {
+        bitmask_w |= (m->op[i]->bit[j].type != AVR_CMDBIT_VALUE  &&
+          m->op[i]->bit[j].type != AVR_CMDBIT_IGNORE) << j;
+      }
+    }
+  }
+  return bitmask_r & bitmask_w;
+}
+
+int compare_memory_masked(AVRMEM * m, unsigned char buf1, unsigned char buf2) {
+  uint8_t bitmask = 0xFF;
+  if(m) {
+    bitmask = get_fuse_bitmask(m);
+  }
+  return ((buf1 & bitmask) != (buf2 & bitmask));
+}
+
 /*
  * Verify the memory buffer of p with that of v.  The byte range of v,
  * may be a subset of p.  The byte range of p should cover the whole
@@ -1104,11 +1137,18 @@ int avr_verify(AVRPART * p, AVRPART * v, char * memtyp
   for (i=0; i<size; i++) {
     if ((b->tags[i] & TAG_ALLOCATED) != 0 &&
         buf1[i] != buf2[i]) {
-      avrdude_message(MSG_INFO, "%s: verification error, first mismatch at byte 0x%04x\n"
-                      "%s0x%02x != 0x%02x\n",
-                      progname, i,
-                      progbuf, buf1[i], buf2[i]);
-      return -1;
+      if(compare_memory_masked(a , buf1[i], buf2[i])) {
+        avrdude_message(MSG_INFO, "%s: verification error, first mismatch at byte 0x%04x\n"
+                        "%s0x%02x != 0x%02x\n",
+                        progname, i,
+                        progbuf, buf1[i], buf2[i]);
+        return -1;
+      } else {
+        avrdude_message(MSG_INFO, "%s: WARNING: invalid value for unused bits in fuse \"%s\", should be set to 1 according to datasheet\n"
+                        "This behaviour is deprecated and will result in an error in future version\n"
+                        "You probably want to use 0x%02x instead of 0x%02x (double check with your datasheet first).\n",
+                        progname, memtype, buf1[i], buf2[i]);
+      }
     }
   }
 
