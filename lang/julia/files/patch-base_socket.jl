--- base/socket.jl.orig	2017-02-24 09:57:14 UTC
+++ base/socket.jl
@@ -762,7 +762,7 @@ function getsockname(sock::Union{TCPServ
             addrv4 = raddress[1:4]
             naddr = ntoh(unsafe_load(Ptr{Cuint}(pointer(addrv4)), 1))
             addr = IPv4(naddr)
-        elseif rfamily[] == @static is_windows() ? 23 : (@static is_apple() ? 30 : 10) # AF_INET6
+        elseif rfamily[] == 28 # AF_INET6
             naddr = ntoh(unsafe_load(Ptr{UInt128}(pointer(raddress)), 1))
             addr = IPv6(naddr)
         else
