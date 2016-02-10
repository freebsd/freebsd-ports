# Origin: https://github.com/jedisct1/dnscrypt-proxy/commit/a193c6ff1ca2b24bb283f0d64bf8f5faefc0def1
# Subject: Repair edns0 support

--- src/proxy/edns.c.orig	2016-02-02 15:42:19 UTC
+++ src/proxy/edns.c
@@ -10,7 +10,7 @@
 #include "dnscrypt_proxy.h"
 #include "edns.h"
 
-#define DNS_MAX_HOSTNAME_LEN 255U
+#define DNS_MAX_HOSTNAME_LEN 256U
 
 static int
 _skip_name(const uint8_t * const dns_packet, const size_t dns_packet_len,
@@ -26,9 +26,6 @@ _skip_name(const uint8_t * const dns_pac
     }
     for (;;) {
         name_component_len = dns_packet[offset];
-        if (name_component_len == 0U) {
-            break;
-        }
         if ((name_component_len & 0xC0) == 0xC0) {
             name_component_len = 1U;
         }
@@ -40,6 +37,9 @@ _skip_name(const uint8_t * const dns_pac
             return -1;
         }
         offset += name_component_len + 1U;
+        if (name_component_len == 0U) {
+            break;
+        }
     }
     if (offset >= dns_packet_len) {
         return -1;
