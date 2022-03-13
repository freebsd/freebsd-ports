--- src/output/dnscli.c.orig	2022-01-04 14:44:42 UTC
+++ src/output/dnscli.c
@@ -331,7 +331,7 @@ static void _receive_udp(output_dnscli_t* self, const 
     self->errs++;
 }
 
-inline ssize_t _send_tcp(output_dnscli_t* self, const uint8_t* payload, size_t len, size_t sent)
+ssize_t _send_tcp(output_dnscli_t* self, const uint8_t* payload, size_t len, size_t sent)
 {
     ssize_t n;
 
@@ -432,7 +432,7 @@ static void _receive_tcp(output_dnscli_t* self, const 
     self->errs++;
 }
 
-inline ssize_t _send_tls(output_dnscli_t* self, const uint8_t* payload, size_t len, size_t sent)
+ssize_t _send_tls(output_dnscli_t* self, const uint8_t* payload, size_t len, size_t sent)
 {
     ssize_t n;
 
