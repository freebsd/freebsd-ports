--- fdbserver/BlobWorker.actor.cpp.orig	2023-11-07 15:13:56 UTC
+++ fdbserver/BlobWorker.actor.cpp
@@ -585,8 +585,8 @@ ACTOR Future<Void> updateGranuleSplitState(Transaction
 			fmt::print("Updating granule {0} split state from {1} {2} -> {3}\n",
 			           currentGranuleID.toString(),
 			           parentGranuleID.toString(),
-			           currentState,
-			           newState);
+			           static_cast<int>(currentState),
+			           static_cast<int>(newState));
 		}
 
 		Key myStateKey = blobGranuleSplitKeyFor(parentGranuleID, currentGranuleID);
@@ -631,8 +631,8 @@ ACTOR Future<Void> updateGranuleSplitState(Transaction
 		fmt::print("Ignoring granule {0} split state from {1} {2} -> {3}\n",
 		           currentGranuleID.toString(),
 		           parentGranuleID.toString(),
-		           currentState,
-		           newState);
+		           static_cast<int>(currentState),
+		           static_cast<int>(newState));
 	}
 
 	return Void();
@@ -5422,7 +5422,7 @@ ACTOR Future<Void> blobWorkerCore(BlobWorkerInterface 
 					           assignReq.keyRange.end.printable(),
 					           assignReq.managerEpoch,
 					           assignReq.managerSeqno,
-					           assignReq.type);
+					           static_cast<int>(assignReq.type));
 				}
 
 				if (self->managerEpochOk(assignReq.managerEpoch)) {
