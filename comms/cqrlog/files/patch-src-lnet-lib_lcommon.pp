--- src/lnet/lib/lcommon.pp	2016-03-17 12:36:41.744524000 -0500
+++ src/lnet/lib/lcommon.pp	2016-03-17 12:37:31.449533000 -0500
@@ -512,15 +512,15 @@
 procedure FillAddressInfo(var aAddrInfo: TLSocketAddress; const aFamily: sa_family_t;
   const Address: string; const aPort: Word);
 begin
-  aAddrInfo.IPv4.family := aFamily;
-  aAddrInfo.IPv4.Port := htons(aPort);
+  aAddrInfo.IPv4.sin_family := aFamily;
+  aAddrInfo.IPv4.sin_port := htons(aPort);
 
   case aFamily of
     LAF_INET  :
       begin
-        aAddrInfo.IPv4.Addr := StrToNetAddr(Address);
-        if (Address <> LADDR_ANY) and (aAddrInfo.IPv4.Addr = 0) then
-          aAddrInfo.IPv4.Addr := StrToNetAddr(GetHostIP(Address));
+        aAddrInfo.IPv4.sin_addr.s_addr := StrToNetAddr(Address);
+        if (Address <> LADDR_ANY) and (aAddrInfo.IPv4.sin_addr.s_addr = 0) then
+          aAddrInfo.IPv4.sin_addr.s_addr := StrToNetAddr(GetHostIP(Address));
       end;
     LAF_INET6 :
       begin
