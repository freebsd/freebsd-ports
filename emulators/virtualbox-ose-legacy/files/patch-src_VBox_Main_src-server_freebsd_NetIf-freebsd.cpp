--- src/VBox/Main/src-server/freebsd/NetIf-freebsd.cpp.orig	2017-10-18 07:12:58 UTC
+++ src/VBox/Main/src-server/freebsd/NetIf-freebsd.cpp
@@ -43,6 +43,7 @@
 
 #include <net/if_dl.h>
 #include <netinet/in.h>
+#include <net80211/ieee80211_ioctl.h>
 
 #include <stdlib.h>
 #include <stdio.h>
@@ -311,7 +312,7 @@ int NetIfList(std::list <ComObjPtr<HostNetworkInterfac
             else
                 enmType = HostNetworkInterfaceType_HostOnly;
 
-            pNew->wireless = isWireless(pNew->szName);
+            pNew->fWireless = isWireless(pNew->szName);
 
             ComObjPtr<HostNetworkInterface> IfObj;
             IfObj.createObject();
