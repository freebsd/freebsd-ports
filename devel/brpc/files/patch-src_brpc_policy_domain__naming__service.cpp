--- src/brpc/policy/domain_naming_service.cpp.orig	2026-02-23 02:11:29 UTC
+++ src/brpc/policy/domain_naming_service.cpp
@@ -106,7 +106,7 @@ int DomainNamingService::GetServers(const char* dns_na
         
     }
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
     _aux_buf_len = 0; // suppress unused warning
     // gethostbyname on MAC is thread-safe (with current usage) since the
     // returned hostent is TLS. Check following link for the ref:
