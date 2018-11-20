--- src/NetUtils.cc.orig	2018-11-19 19:50:00 UTC
+++ src/NetUtils.cc
@@ -23,6 +23,7 @@
 #else
   #include <arpa/inet.h>
   #include <net/if.h>
+  #include <netinet/in.h>
   #include <netdb.h>
   #include <pwd.h>
   #include <unistd.h>
@@ -208,10 +209,17 @@ inline namespace IGNITION_TRANSPORT_VERS
       }
 
       // If we already have the same SIOCGIFINDEX, ignore it (subinterface).
+#  if defined(__FreeBSD__) || defined(__DragonFly__)
+      if (realIdx.find(ifIdx.ifr_index) != realIdx.end())
+        continue;
+
+      realIdx.insert(ifIdx.ifr_index);
+#  else
       if (realIdx.find(ifIdx.ifr_ifindex) != realIdx.end())
         continue;
 
       realIdx.insert(ifIdx.ifr_ifindex);
+#  endif
 #endif
 
       if (getnameinfo(ifa->ifa_addr, salen, ip_, sizeof(ip_), nullptr, 0,
