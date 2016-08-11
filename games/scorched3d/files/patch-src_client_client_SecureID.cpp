--- src/client/client/SecureID.cpp.orig	2016-06-20 14:16:37 UTC
+++ src/client/client/SecureID.cpp
@@ -71,6 +71,47 @@ std::string SecureID::GetPrivateKey(void
 	return result;
 }
 
+#elif defined(__FreeBSD__)
+
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <net/if_dl.h>
+#include <ifaddrs.h>
+
+std::string SecureID::GetPrivateKey(void)
+{
+       std::string Key;
+       struct ifaddrs* ifaphead;
+
+       if (getifaddrs(&ifaphead) != 0)
+       {
+               return "";
+       }
+
+       for (struct ifaddrs* ifap = ifaphead; ifap; ifap = ifap->ifa_next)
+       {
+               if (ifap->ifa_addr->sa_family == AF_LINK)
+               {
+                       if (strncmp(ifap->ifa_name, "lo", 2) != 0)
+                       {
+                               struct sockaddr_dl* sdl =
+                                       (struct sockaddr_dl *)ifap->ifa_addr;
+                               unsigned char* if_mac = (unsigned char*)LLADDR(sdl);
+                               char buf[18];
+                               snprintf(buf, 18,
+                                       "%02x:%02x:%02x:%02x:%02x:%02x",
+                                       if_mac[0], if_mac[1], if_mac[2],
+                                       if_mac[3], if_mac[4], if_mac[5]);
+                               Key = buf;
+                               break;
+                       }
+               }
+       }
+
+       freeifaddrs(ifaphead);
+       return Key;
+}
+
 #else
 
 #include <sys/ioctl.h>
