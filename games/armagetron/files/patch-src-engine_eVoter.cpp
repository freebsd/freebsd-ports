--- src/engine/eVoter.cpp.orig	2007-10-02 18:10:33.000000000 +0200
+++ src/engine/eVoter.cpp	2007-10-02 18:10:58.000000000 +0200
@@ -39,6 +39,8 @@
 #include "ePlayer.h"
 #include "eGrid.h"
 
+class eMenuItemVote;
+
 static unsigned short se_votingItemID = 0;
 static float se_votingTimeout = 300.0f;
 static nSettingItem< float > se_vt( "VOTING_TIMEOUT", se_votingTimeout );
