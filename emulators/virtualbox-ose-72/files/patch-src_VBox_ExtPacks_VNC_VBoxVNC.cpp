--- src/VBox/ExtPacks/VNC/VBoxVNC.cpp.orig	2025-08-13 19:50:02 UTC
+++ src/VBox/ExtPacks/VNC/VBoxVNC.cpp
@@ -55,7 +55,7 @@
 
 #ifdef LIBVNCSERVER_IPv6
 // enable manually!
-// #define VBOX_USE_IPV6
+#define VBOX_USE_IPV6
 #endif
 
 
@@ -431,7 +431,7 @@ DECLCALLBACK(int) VNCServerImpl::VRDEEnableConnections
 
     // get address
     char *pszTCPAddress = (char *)RTMemTmpAllocZ(VNC_ADDRESS_OPTION_MAX);
-    rc = instance->mCallbacks->VRDECallbackProperty(instance->mCallback,
+    int rc = instance->mCallbacks->VRDECallbackProperty(instance->mCallback,
                                                     VRDE_QP_NETWORK_ADDRESS,
                                                     pszTCPAddress,
                                                     VNC_ADDRESS_OPTION_MAX,
@@ -592,19 +592,35 @@ DECLCALLBACK(int) VNCServerImpl::VRDEEnableConnections
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
