--- fdbserver/storageserver.actor.cpp.orig	2026-04-16 19:21:39 UTC
+++ fdbserver/storageserver.actor.cpp
@@ -3637,7 +3637,7 @@ ACTOR Future<std::pair<ChangeFeedStreamReply, bool>> g
 			           req.rangeID.printable().substr(0, 6),
 			           req.id.toString().substr(0, 8),
 			           foundVersion ? "key" : "version",
-			           DEBUG_CF_MISSING_VERSION,
+			           static_cast<int64_t>(DEBUG_CF_MISSING_VERSION),
 			           req.range.begin.printable(),
 			           req.range.end.printable(),
 			           req.begin,
@@ -3657,7 +3657,7 @@ ACTOR Future<std::pair<ChangeFeedStreamReply, bool>> g
 			           data->thisServerID.toString().substr(0, 4),
 			           req.rangeID.printable().substr(0, 6),
 			           req.id.toString().substr(0, 8),
-			           DEBUG_CF_MISSING_VERSION,
+			           static_cast<int64_t>(DEBUG_CF_MISSING_VERSION),
 			           req.range.begin.printable(),
 			           req.range.end.printable(),
 			           req.begin,
