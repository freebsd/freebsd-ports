--- src/network.c.orig	2024-12-20 21:57:21 UTC
+++ src/network.c
@@ -647,7 +647,7 @@ static int iface_allowed_v4(struct in_addr local, int 
 /*
  * Clean old interfaces no longer found.
  */
-static void clean_interfaces()
+static void clean_interfaces(void)
 {
   struct irec *iface;
   struct irec **up = &daemon->interfaces;
