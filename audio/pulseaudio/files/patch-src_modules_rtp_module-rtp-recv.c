--- src/modules/rtp/module-rtp-recv.c.orig	2024-01-12 17:22:09 UTC
+++ src/modules/rtp/module-rtp-recv.c
@@ -710,7 +710,7 @@ int pa__init(pa_module*m) {
 
         pa_zero(hints);
 
-        service = pa_sprintf_malloc("%d", htons(SAP_PORT));
+        service = pa_sprintf_malloc("%d", SAP_PORT);
 
         hints.ai_flags = AI_NUMERICHOST;
         if (getaddrinfo(sap_address, service, &hints, &sap_addrinfo) != 0) {
