--- JuceLibraryCode/modules/juce_core/native/juce_linux_Network.cpp.orig	2020-09-11 12:10:25 UTC
+++ JuceLibraryCode/modules/juce_core/native/juce_linux_Network.cpp
@@ -35,6 +35,14 @@ void MACAddress::findAllAddresses (Array<MACAddress>& 
         {
             for (auto* i = addrs; i != nullptr; i = i->ifa_next)
             {
+#if JUCE_BSD
+                if (i->ifa_addr->sa_family != AF_LINK) {
+                    continue;
+                }
+                struct sockaddr_dl *dl = (struct sockaddr_dl *)i->ifa_addr;
+                {
+                    MACAddress ma ((const uint8*) LLADDR(dl));
+#else
                 struct ifreq ifr;
                 strcpy (ifr.ifr_name, i->ifa_name);
                 ifr.ifr_addr.sa_family = AF_INET;
@@ -42,6 +50,7 @@ void MACAddress::findAllAddresses (Array<MACAddress>& 
                 if (ioctl (s, SIOCGIFHWADDR, &ifr) == 0)
                 {
                     MACAddress ma ((const uint8*) ifr.ifr_hwaddr.sa_data);
+#endif
 
                     if (! ma.isNull())
                         result.addIfNotAlreadyThere (ma);
