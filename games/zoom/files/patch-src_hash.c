
$FreeBSD$

--- src/hash.c.orig	Thu Jul 25 20:10:02 2002
+++ src/hash.c	Wed Mar 10 16:00:01 2004
@@ -81,7 +81,7 @@
         for (i = 0; i < 256; ++i) {
                 for (c = i << 24, j = 8; j > 0; --j)
                         c = c & 0x80000000 ? (c << 1) ^ CRC32_POLY : (c << 1);
-                crc32_table[i] = c;
+                crc32_table[i] = c & 0xffffffff;
         }
 }
 
@@ -95,8 +95,8 @@
     init_crc32();   /* build table */
   crc = 0xffffffff;       /* preload shift register, per CRC-32 spec */
   for (p = buf; len > 0; ++p, --len)
-    crc = (crc << 8) ^ crc32_table[(crc >> 24) ^ *p];
-  return ~crc;            /* transmit complement, per CRC-32 spec */  
+    crc = ((crc << 8) ^ crc32_table[(crc >> 24) ^ *p]) & 0xffffffff;
+  return ~crc & 0xffffffff;     /* transmit complement, per CRC-32 spec */  
 }
 
 static struct bucket *hash_lookup(hash          hash,
