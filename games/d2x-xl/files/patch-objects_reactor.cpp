--- objects/reactor.cpp.orig	2017-02-01 15:11:32 UTC
+++ objects/reactor.cpp
@@ -184,7 +184,7 @@ else {
 
 void InitCountdown (CTrigger *trigP, int bReactorDestroyed, int nTimer)
 {
-if (trigP && (trigP->m_info.time > 0))
+if (trigP && trigP->m_info.time)
 	gameData.reactor.countdown.nTotalTime = trigP->m_info.time [0];
 else if (gameStates.app.nBaseCtrlCenExplTime != DEFAULT_CONTROL_CENTER_EXPLOSION_TIME)
 	gameData.reactor.countdown.nTotalTime = 
