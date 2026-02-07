--- src/VBox/ExtPacks/VNC/VBoxVNC.cpp.orig	2020-07-09 16:56:32 UTC
+++ src/VBox/ExtPacks/VNC/VBoxVNC.cpp
@@ -45,7 +45,7 @@
 
 #ifdef LIBVNCSERVER_IPv6
 // enable manually!
-// #define VBOX_USE_IPV6
+#define VBOX_USE_IPV6
 #endif
 
 
@@ -312,7 +312,7 @@ DECLCALLBACK(int) VNCServerImpl::VRDEEnableConnections
     else
     {
         const char szFeatName[] = "Property/TCP/Ports";
-        const uint32_t featLen = sizeof(VRDEFEATURE) + RT_MAX(sizeof(VNC_PORTSSIZE), sizeof(szFeatName)) - 1;
+        const uint32_t featLen = sizeof(VRDEFEATURE) + RT_MAX(VNC_PORTSSIZE, sizeof(szFeatName)) - 1;
         VRDEFEATURE *feature = (VRDEFEATURE *)RTMemTmpAlloc(featLen);
         feature->u32ClientId = 0;
         RTStrCopy(feature->achInfo, featLen - sizeof(VRDEFEATURE) + 1, szFeatName);
@@ -421,7 +421,7 @@ DECLCALLBACK(int) VNCServerImpl::VRDEEnableConnections
 
     // get address
     char *pszTCPAddress = (char *)RTMemTmpAllocZ(VNC_ADDRESS_OPTION_MAX);
-    rc = instance->mCallbacks->VRDECallbackProperty(instance->mCallback,
+    int rc = instance->mCallbacks->VRDECallbackProperty(instance->mCallback,
                                                     VRDE_QP_NETWORK_ADDRESS,
                                                     pszTCPAddress,
                                                     VNC_ADDRESS_OPTION_MAX,
@@ -582,19 +582,35 @@ DECLCALLBACK(int) VNCServerImpl::VRDEEnableConnections
             pszServerAddress6 = szIPv6ListenAll;
     }
 
-    if (pszVNCPort4 && uServerPort4 == 0)
+    if (strlen(pszVNCPort4) > 0 && uServerPort4 == 0)
     {
         rc = RTStrToUInt32Ex(pszVNCPort4, NULL, 10, &uServerPort4);
         if (!RT_SUCCESS(rc) || uServerPort4 > 65535)
             uServerPort4 = 0;
     }
 
-    if (pszVNCPort6 && uServerPort6 == 0)
+    if (strlen(pszVNCPort6) > 0 && uServerPort6 == 0)
     {
         rc = RTStrToUInt32Ex(pszVNCPort6, NULL, 10, &uServerPort6);
         if (!RT_SUCCESS(rc) || uServerPort6 > 65535)
             uServerPort6 = 0;
     }
+
+/* Backward compatibility with set port in "TCP/Ports" only { */
+    if (uServerPort4 == 0 && strlen(pszTCPPort) > 0)
+    {
+        rc = RTStrToUInt32Ex(pszTCPPort, NULL, 10, &uServerPort4);
+        if (!RT_SUCCESS(rc) || uServerPort4 > 65535)
+            uServerPort4 = 0;
+    }
+
+    if (uServerPort6 == 0 && strlen(pszTCPPort) > 0)
+    {
+        rc = RTStrToUInt32Ex(pszTCPPort, NULL, 10, &uServerPort6);
+        if (!RT_SUCCESS(rc) || uServerPort6 > 65535)
+            uServerPort6 = 0;
+    }
+/* } */
 
     if (uServerPort4 == 0 || uServerPort6 == 0)
         vncServer->autoPort = 1;
