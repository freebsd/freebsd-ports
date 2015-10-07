--- gameServer/CoreTypes.hs.orig	2015-01-06 20:55:59 UTC
+++ gameServer/CoreTypes.hs
@@ -38,7 +38,7 @@ import RoomsAndClients
 instance NFData B.ByteString
 #endif
 
-instance NFData (Chan a)
+instance NFData (Chan a) where rnf a = a `seq` ()
 
 instance NFData Action where
     rnf (AnswerClients chans msg) = chans `deepseq` msg `deepseq` ()
