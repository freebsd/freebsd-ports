--- fdbserver/storageserver.actor.cpp.orig	2024-01-09 21:06:41 UTC
+++ fdbserver/storageserver.actor.cpp
@@ -3615,7 +3615,7 @@ ACTOR Future<std::pair<ChangeFeedStreamReply, bool>> g
 			           req.rangeID.printable().substr(0, 6),
 			           req.id.toString().substr(0, 8),
 			           foundVersion ? "key" : "version",
-			           DEBUG_CF_MISSING_VERSION,
+			           static_cast<int64_t>(DEBUG_CF_MISSING_VERSION),
 			           req.range.begin.printable(),
 			           req.range.end.printable(),
 			           req.begin,
@@ -3635,7 +3635,7 @@ ACTOR Future<std::pair<ChangeFeedStreamReply, bool>> g
 			           data->thisServerID.toString().substr(0, 4),
 			           req.rangeID.printable().substr(0, 6),
 			           req.id.toString().substr(0, 8),
-			           DEBUG_CF_MISSING_VERSION,
+			           static_cast<int64_t>(DEBUG_CF_MISSING_VERSION),
 			           req.range.begin.printable(),
 			           req.range.end.printable(),
 			           req.begin,
