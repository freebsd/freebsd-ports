--- scumm/actor.cpp.orig	Tue Aug  3 15:55:01 2004
+++ scumm/actor.cpp	Tue Aug  3 15:55:35 2004
@@ -789,14 +789,14 @@
 		return _V1_talkingActor;
 	else
 		return VAR(VAR_TALK_ACTOR);
-};
+}
 
 void ScummEngine::talkingActor(int value) {
 	if (_gameId == GID_MANIAC && _version == 1)
 		_V1_talkingActor = value;
 	else
 		VAR(VAR_TALK_ACTOR) = value;
-};
+}
 
 void ScummEngine::showActors() {
 	int i;
