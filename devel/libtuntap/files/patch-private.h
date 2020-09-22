--- private.h.orig	2018-10-15 10:45:27 UTC
+++ private.h
@@ -105,7 +105,7 @@ struct device {
 # endif
 
 /* Internal log facilities */
-t_tuntap_log tuntap_log;
+extern t_tuntap_log tuntap_log;
 void	 tuntap_log_default(int, const char *);
 void	 tuntap_log_hexdump(void *, size_t);
 void	 tuntap_log_chksum(void *, int);
