--- ./gameServer/Actions.hs.orig	2014-01-08 17:25:17.000000000 +0100
+++ ./gameServer/Actions.hs	2014-08-10 23:44:17.631500480 +0200
@@ -562,7 +562,7 @@
     si <- gets serverInfo
     newClId <- io $ do
         ci <- addClient rnc cl
-        _ <- Exception.mask (forkIO . clientRecvLoop (clientSocket cl) (coreChan si) (sendChan cl) ci)
+        _ <- Exception.mask (\x -> forkIO $ clientRecvLoop (clientSocket cl) (coreChan si) (sendChan cl) ci x)
 
         infoM "Clients" (show ci ++ ": New client. Time: " ++ show (connectTime cl))
 
