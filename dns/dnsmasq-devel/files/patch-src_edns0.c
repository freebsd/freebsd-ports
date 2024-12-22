--- src/edns0.c.orig	2024-12-20 21:57:21 UTC
+++ src/edns0.c
@@ -491,7 +491,7 @@ static size_t add_umbrella_opt(struct dns_header *head
 {
   *cacheable = 0;
 
-  struct umbrella_opt opt = {{"ODNS"}, UMBRELLA_VERSION, 0, {}};
+  struct umbrella_opt opt = {{"ODNS"}, UMBRELLA_VERSION, 0, {0}};
   u8 *u = &opt.fields[0];
   int family = source->sa.sa_family;
   int size = family == AF_INET ? INADDRSZ : IN6ADDRSZ;
