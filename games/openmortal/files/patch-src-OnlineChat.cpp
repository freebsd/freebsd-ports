--- src/OnlineChat.cpp.orig	2004-04-29 16:32:35.000000000 +0000
+++ src/OnlineChat.cpp	2007-10-31 02:54:07.000000000 +0000
@@ -56,7 +56,7 @@
 class CChallengeMenu: public Menu
 {
 public:
-	CChallengeMenu::CChallengeMenu( std::string a_sChallenger )
+	CChallengeMenu( std::string a_sChallenger )
 	: Menu( "You have been challenged!" ),
 	m_sChallenger( a_sChallenger )
 	{
