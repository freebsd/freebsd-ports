--- src/st-info/info.c.orig	2025-04-02 12:38:55 UTC
+++ src/st-info/info.c
@@ -55,7 +55,7 @@ static void stlink_probe(enum connect_type connect, in
     stlink_t **stdevs;
     uint32_t size;
 
-    size = stlink_probe_usb(&stdevs, connect, freq);
+    size = (uint32_t) stlink_probe_usb(&stdevs, connect, freq);
 
     printf("Found %u stlink programmers\n", size);
 
