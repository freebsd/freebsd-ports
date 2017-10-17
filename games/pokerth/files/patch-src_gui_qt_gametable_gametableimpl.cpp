--- src/gui/qt/gametable/gametableimpl.cpp.orig	2014-01-10 21:18:20 UTC
+++ src/gui/qt/gametable/gametableimpl.cpp
@@ -3859,7 +3859,7 @@ void gameTableImpl::triggerVoteOnKick(int id)
 	int playerCount = static_cast<int>(seatList->size());
 	if (id < playerCount) {
 		PlayerListIterator pos = seatList->begin();
-		advance(pos, id);
+		std::advance(pos, id);
 		myStartWindow->getSession()->startVoteKickPlayer((*pos)->getMyUniqueID());
 	}
 }
