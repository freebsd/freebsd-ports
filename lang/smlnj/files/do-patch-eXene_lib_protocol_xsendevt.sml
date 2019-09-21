--- eXene/lib/protocol/xsendevt.sml.orig	2005-11-02 22:24:39 UTC
+++ eXene/lib/protocol/xsendevt.sml
@@ -46,7 +46,7 @@ structure XSendEvent =
 	| putAtomOption (buf, i, SOME(XTy.XAtom n)) = putWord32 (buf, i, n)
 
       fun putTS (buf, i, XTy.CurrentTime) = put32(buf, i, 0w0)
-	| putTS (buf, i, XTy.TimeStamp(XTime.XT t)) = put32(buf, i, t)
+	| putTS (buf, i, XTy.TimeStamp(XTime.XT t)) = put32(buf, i, Word32.toLarge t)
 
     (* event codes *)
       val evtKeyPressXEvt	= 0w2 : Word8.word
