--- src/engine/eVoter.cpp.orig	2006-05-13 22:17:31.000000000 +0800
+++ src/engine/eVoter.cpp	2008-06-08 14:34:16.000000000 +0800
@@ -41,6 +41,8 @@
 #include "ePlayer.h"
 #include "eGrid.h"
 
+class eMenuItemVote;
+
 // use server controlled votes
 static bool se_useServerControlledKick = false;
 static nSettingItemWatched< bool > se_usc( "VOTE_USE_SERVER_CONTROLLED_KICK", se_useServerControlledKick, nConfItemVersionWatcher::Group_Annoying, 10 );
