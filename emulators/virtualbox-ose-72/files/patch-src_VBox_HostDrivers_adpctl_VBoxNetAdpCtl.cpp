--- src/VBox/HostDrivers/adpctl/VBoxNetAdpCtl.cpp.orig	2025-08-13 19:51:12 UTC
+++ src/VBox/HostDrivers/adpctl/VBoxNetAdpCtl.cpp
@@ -759,7 +759,7 @@ int Adapter::doIOCtl(unsigned long iCmd, VBOXNETADPREQ
 *   Global config file implementation                                                                                            *
 *********************************************************************************************************************************/
 
-#define VBOX_GLOBAL_NETWORK_CONFIG_PATH "/etc/vbox/networks.conf"
+#define VBOX_GLOBAL_NETWORK_CONFIG_PATH "%%VBOX_ETC%%/networks.conf"
 #define VBOXNET_DEFAULT_IPV4MASK "255.255.255.0"
 
 class NetworkAddress
