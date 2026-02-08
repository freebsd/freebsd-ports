commit 84415a87be571a6da82c910c1b87b194e5f54727
Author: Clayton O'Neill <clayton@oneill.net>
Date:   Thu Feb 5 15:38:27 2026 +0000

    Fix PXE boot server (PXEBS) responses broken in 2.92
    
    I think I've found a regression in dnsmasq 2.92 that breaks PXE boot server
    (PXEBS) responses when running in proxy DHCP mode. Fair warning: I'm not
    familiar with the dnsmasq codebase and used AI tooling to help trace through
    the source and identify the issue, so please take the analysis below with
    appropriate skepticism. PXE boot works fine on 2.91
    but fails on 2.92 — the client gets the initial proxy DHCPOFFER, but the PXEBS
    ACK on port 4011 never reaches it.
    
    My setup is dnsmasq in proxy DHCP mode serving iPXE to Proxmox VMs via their
    virtio-net ROM. Here's a stripped-down version of my config:
    
      port=0
      enable-tftp
      tftp-root=/tftpboot
      dhcp-range=172.19.74.0,proxy,255.255.255.0
      interface=eno1
      bind-interfaces
      dhcp-match=set:ipxe,175
      pxe-service=tag:ipxe,x86PC,"Network Boot",http://server:8081/boot.ipxe
      pxe-service=tag:!ipxe,x86PC,"Network Boot",undionly.kpxe
      log-dhcp
    
    The issue seems to be in src/dhcp.c in the response routing logic after
    dhcp_reply() returns. In 2.91, the destination selection was an if/else-if
    chain:
    
      if (pxe_fd)
          { ... }
      else if (mess->giaddr.s_addr && !is_relay_reply)
          { ... }
      else if (mess->ciaddr.s_addr)
          { ... }
      else
          { ... broadcast to 255.255.255.255:68 ... }
    
    In 2.92, the else between the pxe_fd block and the giaddr/relay check was
    removed in commit 4fbe1ad ("Implement RFC-4388 DHCPv4 leasequery") to
    accommodate the new is_relay_use_source logic:
    
      if (pxe_fd)
          { ... }
      if ((is_relay_use_source || mess->giaddr.s_addr) && !is_relay_reply)
          { ... }
      else if (mess->ciaddr.s_addr)
          { ... }
      else
          { ... broadcast to 255.255.255.255:68 ... }
    
    For PXEBS responses, dhcp_reply() in rfc2131.c (around line 924-925) does:
    
      mess->yiaddr = mess->ciaddr;
      mess->ciaddr.s_addr = 0;
    
    So after dhcp_reply() returns for a PXEBS request, ciaddr is 0, giaddr is 0
    (no relay), and is_relay_use_source is 0. In 2.91, the pxe_fd block runs and
    the rest of the chain is skipped — dest stays as received from recvmsg, and the
    response goes back to the client correctly. In 2.92, the pxe_fd block runs but
    then falls through to the standalone if, which is false, so the else block runs
    and sets dest to 255.255.255.255 port 68. The client is listening on port 4011
    and ignores it.
    
    Here are the relevant dnsmasq logs. With 2.91 (working), I see normal proxy
    DHCP and PXE boot server exchanges:
    
      dnsmasq-dhcp: DHCPDISCOVER(eno1) bc:24:11:59:85:90
      dnsmasq-dhcp: DHCPOFFER(eno1) 172.19.74.60 bc:24:11:59:85:90
      dnsmasq-dhcp: DHCPREQUEST(eno1) 172.19.74.60 bc:24:11:59:85:90
      dnsmasq-dhcp: DHCPACK(eno1) 172.19.74.60 bc:24:11:59:85:90
      dnsmasq-dhcp: PXE(eno1) bc:24:11:59:85:90 proxy
      dnsmasq-dhcp: PXE(eno1) bc:24:11:59:85:90 proxy
      dnsmasq-dhcp: PXEBS(eno1) bc:24:11:59:85:90 undionly.kpxe
      dnsmasq-dhcp: PXE(eno1) bc:24:11:59:85:90 proxy
      dnsmasq-dhcp: PXEBS(eno1) bc:24:11:59:85:90 http://infra1.oneill.net:8081/boot.ipxe
    
    With 2.92 (broken), the DHCPDISCOVER/OFFER/REQUEST/ACK cycle and the proxy
    PXE response work, but the PXEBS response never reaches the client — it times
    out after repeated attempts. The dnsmasq side shows it sending the response,
    but the client keeps retrying:
    
      dnsmasq-dhcp: PXE(eno1) bc:24:11:59:85:90 proxy
      dnsmasq-dhcp: PXE(eno1) bc:24:11:59:85:90 proxy
      dnsmasq-dhcp: PXEBS(eno1) bc:24:11:59:85:90 undionly.kpxe
      dnsmasq-dhcp: PXEBS(eno1) bc:24:11:59:85:90 undionly.kpxe
      dnsmasq-dhcp: PXEBS(eno1) bc:24:11:59:85:90 undionly.kpxe
      dnsmasq-dhcp: PXEBS(eno1) bc:24:11:59:85:90 undionly.kpxe
    
    I tested by restoring the else keyword and the fix appears to work — 2.92 with
    the patch below PXE boots successfully. I believe this change preserves the
    leasequery behavior since that path only applies when pxe_fd is false (normal
    DHCP handling, not port 4011).

diff --git a/src/dhcp.c b/src/dhcp.c
index 6775fb6..efda023 100644
--- src/dhcp.c~
+++ src/dhcp.c
@@ -399,7 +399,7 @@ void dhcp_packet(time_t now, int pxe_fd)
       if (mess->ciaddr.s_addr != 0)
 	dest.sin_addr = mess->ciaddr;
     }
-  if ((is_relay_use_source || mess->giaddr.s_addr) && !is_relay_reply)
+  else if ((is_relay_use_source || mess->giaddr.s_addr) && !is_relay_reply)
     {
       /* Send to BOOTP relay. */
       if (is_relay_use_source)
