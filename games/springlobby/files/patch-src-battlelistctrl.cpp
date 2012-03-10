--- src/battlelistctrl.cpp.orig	2012-03-09 20:01:28.000000000 +0400
+++ src/battlelistctrl.cpp	2012-03-10 07:08:45.273705553 +0400
@@ -103,7 +103,7 @@
 		case 7: return wxFormat(_T("%d") ) % int(battle.GetSpectators());
 		case 8: return wxFormat(_T("%d") ) % (int(battle.GetNumUsers()) - int(battle.GetSpectators()));
 		case 9: return wxFormat(_T("%d") ) % int(battle.GetMaxPlayers());
-        case 10: return ( wxDateTime(battle.GetBattleRunningTime()).FormatISOTime() );
+        case 10: return ( wxDateTime((time_t)battle.GetBattleRunningTime()).FormatISOTime() );
     }
 }
 
