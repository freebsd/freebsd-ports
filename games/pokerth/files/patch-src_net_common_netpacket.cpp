--- src/net/common/netpacket.cpp.orig	2014-01-10 21:18:20 UTC
+++ src/net/common/netpacket.cpp
@@ -249,7 +249,7 @@ NetPacket::GameErrorToNetError(int gameErrorReason)
 		retVal = ErrorMessage::sessionTimeout;
 		break;
 	default :
-		retVal = ErrorMessage::reserved;
+		retVal = ErrorMessage::pthreserved;
 		break;
 	}
 	return retVal;
