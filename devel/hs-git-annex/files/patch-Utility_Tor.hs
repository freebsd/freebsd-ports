--- Utility/Tor.hs.orig	2019-06-26 16:31:40 UTC
+++ Utility/Tor.hs
@@ -37,7 +37,7 @@ connectHiddenService (OnionAddress address) port = do
 	return s
   where
 	torsocksport = 9050
-	torsockconf = defaultSocksConf "127.0.0.1" torsocksport
+	torsockconf = defaultSocksConf $ SockAddrInet torsocksport $ tupleToHostAddress (127,0,0,1)
 	socksdomain = SocksAddrDomainName (BU8.fromString address)
 	socksaddr = SocksAddress socksdomain (fromIntegral port)
 
