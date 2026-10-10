Backport of upstream GameNetworkingSockets commit 1459f1029d87 ("Add cast to fix
passing wrong size to LittleWord"), half of the fix for big-endian builds (issue #412).

--- 3rdparty/GameNetworkingSockets/src/steamnetworkingsockets/clientlib/steamnetworkingsockets_udp.cpp.orig	2026-04-07 13:58:55 UTC
+++ 3rdparty/GameNetworkingSockets/src/steamnetworkingsockets/clientlib/steamnetworkingsockets_udp.cpp
@@ -581,7 +581,7 @@ int CConnectionTransportUDPBase::SendEncryptedDataChun
 			if ( usecTimeSinceSentLast <= (uint64)k_usecTimeSinceLastPacketMaxReasonable ) // Force unsigned comparison in case assert above fails
 			{
 				// Serialize it
-				out.PutUint16( LittleWord( usecTimeSinceSentLast >> k_usecTimeSinceLastPacketSerializedPrecisionShift ) );
+				out.PutUint16( LittleWord( (uint16)( usecTimeSinceSentLast >> k_usecTimeSinceLastPacketSerializedPrecisionShift ) ) );
 				out.hdr.m_unMsgFlags |= out.hdr.kFlag_TimeSincePrev;
 			}
 		}
