--- src/dnsmasq.c.orig	2025-05-24 14:09:53 UTC
+++ src/dnsmasq.c
@@ -81,7 +81,9 @@ int main (int argc, char **argv)
   int tftp_prefix_missing = 0;
 #endif
 
+#ifdef HAVE_LINUX_NETWORK
   (void)netlink_warn;
+#endif
   
 #if defined(HAVE_IDN) || defined(HAVE_LIBIDN2) || defined(LOCALEDIR)
   setlocale(LC_ALL, "");
