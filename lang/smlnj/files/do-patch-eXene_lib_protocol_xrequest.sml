--- eXene/lib/protocol/xrequest.sml.orig	2005-11-07 23:03:18 UTC
+++ eXene/lib/protocol/xrequest.sml
@@ -84,7 +84,7 @@ structure XRequest =
 	    putSigned16(buf, i+8, border))
 
       fun putTS (buf, i, XTy.CurrentTime) = put32(buf, i, 0w0)
-	| putTS (buf, i, XTy.TimeStamp(XTime.XT t)) = put32(buf, i, t)
+	| putTS (buf, i, XTy.TimeStamp(XTime.XT t)) = put32(buf, i, Word32.toLarge t)
 
       fun putRGB (buf, i, XTy.RGB{red, green, blue}) = (
 	    putWord16(buf, i, red);
