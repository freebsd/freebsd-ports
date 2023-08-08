--- src/JuceLibraryCode/modules/juce_core/native/juce_linux_Network.cpp.orig	2023-02-22 04:30:10 UTC
+++ src/JuceLibraryCode/modules/juce_core/native/juce_linux_Network.cpp
@@ -41,9 +41,9 @@ void MACAddress::findAllAddresses (Array<MACAddress>& 
                 strcpy (ifr.ifr_name, i->ifa_name);
                 ifr.ifr_addr.sa_family = AF_INET;
 
-                if (ioctl (s, SIOCGIFHWADDR, &ifr) == 0)
+                if (ioctl (s, SIOCGIFCONF, &ifr) == 0)
                 {
-                    MACAddress ma ((const uint8*) ifr.ifr_hwaddr.sa_data);
+                    MACAddress ma ((const uint8*) ifr.ifr_data);
 
                     if (! ma.isNull())
                         result.addIfNotAlreadyThere (ma);
