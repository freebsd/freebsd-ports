--- mk/cmake/Modules/FindMiniupnpc.cmake.orig	2013-05-15 21:42:23.000000000 -0500
+++ mk/cmake/Modules/FindMiniupnpc.cmake	2013-05-15 21:42:02.000000000 -0500
@@ -58,20 +58,40 @@
     #include <stdio.h>
     int main()
     {
-        struct UPNPDev *devlist = NULL;
-	int upnp_delay = 5000;
-	const char *upnp_multicastif = NULL;
-	const char *upnp_minissdpdsock = NULL;
-	int upnp_sameport = 0;
-	int upnp_ipv6 = 0;
-	int upnp_error = 0;
-	devlist = upnpDiscover(upnp_delay, upnp_multicastif, upnp_minissdpdsock, upnp_sameport, upnp_ipv6, &upnp_error);
+        static struct UPNPUrls urls;
+        static struct IGDdatas data;
+
+        GetUPNPUrls (&urls, &data, \"myurl\",0);
 
         return 0;
     }"
-   MINIUPNPC_VERSION_1_6_OR_HIGHER)
-    
-   IF (NOT MINIUPNPC_VERSION_1_6_OR_HIGHER)
+   MINIUPNPC_VERSION_1_7_OR_HIGHER)
+
+  IF (NOT MINIUPNPC_VERSION_1_7_OR_HIGHER)
+          set(CMAKE_REQUIRED_INCLUDES ${MINIUPNP_INCLUDE_DIR})
+          set(CMAKE_REQUIRED_LIBRARIES ${MINIUPNP_LIBRARY})
+          check_cxx_source_runs("
+            #include <miniwget.h>
+            #include <miniupnpc.h>
+            #include <upnpcommands.h>
+            #include <stdio.h>
+            int main()
+            {
+                struct UPNPDev *devlist = NULL;
+	        int upnp_delay = 5000;
+	        const char *upnp_multicastif = NULL;
+	        const char *upnp_minissdpdsock = NULL;
+	        int upnp_sameport = 0;
+	        int upnp_ipv6 = 0;
+	        int upnp_error = 0;
+	        devlist = upnpDiscover(upnp_delay, upnp_multicastif, upnp_minissdpdsock, upnp_sameport, upnp_ipv6, &upnp_error);
+
+                return 0;
+            }"
+           MINIUPNPC_VERSION_PRE1_7)
+   ENDIF()
+ 
+   IF (NOT MINIUPNPC_VERSION_PRE1_7 AND NOT MINIUPNPC_VERSION_1_7_OR_HIGHER)
           set(CMAKE_REQUIRED_INCLUDES ${MINIUPNP_INCLUDE_DIR})
           set(CMAKE_REQUIRED_LIBRARIES ${MINIUPNP_LIBRARY})
           check_cxx_source_runs("
@@ -96,25 +116,27 @@
 
    ENDIF()
 
-   set(CMAKE_REQUIRED_INCLUDES ${MINIUPNP_INCLUDE_DIR})
-   set(CMAKE_REQUIRED_LIBRARIES ${MINIUPNP_LIBRARY})
-   check_cxx_source_runs("
-    #include <miniwget.h>
-    #include <miniupnpc.h>
-    #include <upnpcommands.h>
-    #include <stdio.h>
-    static struct UPNPUrls urls;
-    static struct IGDdatas data;
-    int main()
-    {
-        char externalIP[16]     = "";
-	UPNP_GetExternalIPAddress(urls.controlURL, data.first.servicetype, externalIP);
+   IF (NOT MINIUPNPC_VERSION_PRE1_6 AND NOT MINIUPNPC_VERSION_PRE1_7 AND NOT MINIUPNPC_VERSION_1_7_OR_HIGHER)
+           set(CMAKE_REQUIRED_INCLUDES ${MINIUPNP_INCLUDE_DIR})
+           set(CMAKE_REQUIRED_LIBRARIES ${MINIUPNP_LIBRARY})
+           check_cxx_source_runs("
+            #include <miniwget.h>
+            #include <miniupnpc.h>
+            #include <upnpcommands.h>
+            #include <stdio.h>
+            static struct UPNPUrls urls;
+            static struct IGDdatas data;
+            int main()
+            {
+                char externalIP[16]     = "";
+	        UPNP_GetExternalIPAddress(urls.controlURL, data.first.servicetype, externalIP);
 
-        return 0;
-    }"
-    MINIUPNPC_VERSION_1_5_OR_HIGHER)
+                return 0;
+            }"
+            MINIUPNPC_VERSION_1_5_OR_HIGHER)
+    ENDIF()
 
-    IF (NOT MINIUPNPC_VERSION_1_5_OR_HIGHER)
+    IF (NOT MINIUPNPC_VERSION_1_5_OR_HIGHER AND NOT MINIUPNPC_VERSION_PRE1_6 AND NOT MINIUPNPC_VERSION_PRE1_7 AND NOT MINIUPNPC_VERSION_1_7_OR_HIGHER)
          set(CMAKE_REQUIRED_INCLUDES ${MINIUPNP_INCLUDE_DIR})
          set(CMAKE_REQUIRED_LIBRARIES ${MINIUPNP_LIBRARY})
          check_cxx_source_runs("
@@ -141,8 +163,12 @@
     IF(MINIUPNPC_VERSION_PRE1_6)
 	message(STATUS "Found miniupnpc version is pre v1.6")
     ENDIF()
-    IF(NOT MINIUPNPC_VERSION_PRE1_5 AND NOT MINIUPNPC_VERSION_PRE1_6)
-	message(STATUS "Found miniupnpc version is v1.6 or higher")
+    IF(MINIUPNPC_VERSION_PRE1_7)
+	message(STATUS "Found miniupnpc version is pre v1.7")
+    ENDIF()
+
+    IF(NOT MINIUPNPC_VERSION_PRE1_5 AND NOT MINIUPNPC_VERSION_PRE1_6 AND NOT MINIUPNPC_VERSION_PRE1_7)
+	message(STATUS "Found miniupnpc version is v1.7 or higher")
     ENDIF()
 
 else ()
