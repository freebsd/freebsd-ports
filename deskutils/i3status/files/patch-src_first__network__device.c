--- src/first_network_device.c.orig	2022-07-01 12:29:14 UTC
+++ src/first_network_device.c
@@ -4,13 +4,13 @@
 #include <sys/stat.h>
 #include <stdlib.h>
 #include <ifaddrs.h>
-#if defined(__OpenBSD__) || defined(__DragonFly__)
+#if defined(__OpenBSD__) || defined(__DragonFly__) || defined(__FreeBSD__)
 #include <sys/types.h>
 #include <sys/sockio.h>
 #include <sys/ioctl.h>
 #include <net/if.h>
 #endif
-#if defined(__OpenBSD__)
+#if defined(__OpenBSD__) || defined(__FreeBSD__)
 #include <net80211/ieee80211.h>
 #include <net80211/ieee80211_ioctl.h>
 #elif defined(__DragonFly__)
@@ -83,17 +83,17 @@ static net_type_t iface_type(const char *ifname) {
     struct ifreq ifr;
     struct ieee80211_bssid bssid;
     struct ieee80211_nwid nwid;
-#elif defined(__DragonFly__)
+#elif defined(__DragonFly__) || defined(__FreeBSD__)
     struct ieee80211req ifr;
 #endif
-#if defined(__OpenBSD__) || defined(__DragonFly__)
+#if defined(__OpenBSD__) || defined(__DragonFly__) || defined(__FreeBSD__)
     struct ifmediareq ifmr;
     int s;
 #endif
 #if defined(__OpenBSD__)
     int ibssid, inwid;
 #endif
-#if defined(__OpenBSD__) || defined(__DragonFly__)
+#if defined(__OpenBSD__) || defined(__DragonFly__) || defined(__FreeBSD__)
     if ((s = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
         return NET_TYPE_OTHER;
 
@@ -112,7 +112,7 @@ static net_type_t iface_type(const char *ifname) {
         close(s);
         return NET_TYPE_WIRELESS;
     }
-#elif defined(__DragonFly__)
+#elif defined(__DragonFly__) || defined(__FreeBSD__)
     (void)strlcpy(ifr.i_name, ifname, sizeof(ifr.i_name));
     ifr.i_type = IEEE80211_IOC_NUMSSIDS;
     if (ioctl(s, SIOCG80211, &ifr) == 0) {
@@ -120,7 +120,7 @@ static net_type_t iface_type(const char *ifname) {
         return NET_TYPE_WIRELESS;
     }
 #endif
-#if defined(__OpenBSD__) || defined(__DragonFly__)
+#if defined(__OpenBSD__) || defined(__DragonFly__) || defined(__FreeBSD__)
     (void)memset(&ifmr, 0, sizeof(ifmr));
     (void)strlcpy(ifmr.ifm_name, ifname, sizeof(ifmr.ifm_name));
 
