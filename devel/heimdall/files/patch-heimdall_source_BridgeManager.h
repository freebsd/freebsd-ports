--- heimdall/source/BridgeManager.h.orig	2026-11-06 00:00:00 UTC
+++ heimdall/source/BridgeManager.h
@@ -82,7 +82,7 @@ namespace Heimdall
 			{
 				kDefaultTimeoutSend = 3000,
 				kDefaultTimeoutReceive = 3000,
-				kDefaultTimeoutEmptyTransfer = 100
+				kDefaultTimeoutEmptyTransfer = 3000
 			};
 
 			enum class UsbLogLevel
