--- net/dns/public/resolv_reader.cc.orig	2025-08-26 20:49:50 UTC
+++ net/dns/public/resolv_reader.cc
@@ -34,7 +34,7 @@ bool ResolvReader::IsLikelySystemdResolved() {
 }
 
 bool ResolvReader::IsLikelySystemdResolved() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   // Look for a single 127.0.0.53:53 nameserver endpoint. The only known
   // significant usage of such a configuration is the systemd-resolved local
   // resolver, so it is then a fairly safe assumption that any DNS queries to
