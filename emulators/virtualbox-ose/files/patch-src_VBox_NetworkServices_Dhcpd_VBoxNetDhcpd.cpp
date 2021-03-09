--- src/VBox/NetworkServices/Dhcpd/VBoxNetDhcpd.cpp.orig	2021-01-07 15:41:46 UTC
+++ src/VBox/NetworkServices/Dhcpd/VBoxNetDhcpd.cpp
@@ -394,7 +394,7 @@ void VBoxNetDhcpd::ifPump()
         WaitReq.Hdr.cbReq = sizeof(WaitReq);
         WaitReq.pSession = m_pSession;
         WaitReq.hIf = m_hIf;
-        WaitReq.cMillies = RT_INDEFINITE_WAIT;
+        WaitReq.cMillies = 2000;
         int rc = CALL_VMMR0(VMMR0_DO_INTNET_IF_WAIT, WaitReq);
 
         /*
