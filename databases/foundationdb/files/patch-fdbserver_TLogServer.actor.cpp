--- fdbserver/TLogServer.actor.cpp.orig	2018-04-28 15:41:40 UTC
+++ fdbserver/TLogServer.actor.cpp
@@ -425,7 +425,7 @@ struct LogData : NonCopyable, public Ref
 		tLogData->bytesDurable += bytesInput.getValue() - bytesDurable.getValue();
 		TraceEvent("TLogBytesWhenRemoved", tli.id()).detail("sharedBytesInput", tLogData->bytesInput).detail("sharedBytesDurable", tLogData->bytesDurable).detail("localBytesInput", bytesInput.getValue()).detail("localBytesDurable", bytesDurable.getValue());
 
-		ASSERT(tLogData->bytesDurable <= tLogData->bytesInput);
+		ASSERT_ABORT(tLogData->bytesDurable <= tLogData->bytesInput);
 		endRole(tli.id(), "TLog", "Error", true);
 
 		if(!tLogData->terminated) {
