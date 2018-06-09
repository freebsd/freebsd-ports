--- game/team.h.orig	2008-04-16 07:31:25 UTC
+++ game/team.h
@@ -14,7 +14,7 @@ class Team
 		Team();
 		~Team();
 
-		void init(Game::team_t t,const Theme *t);
+		void init(Game::team_t t,const Theme *theme);
 		void update();
 		void shutdown();
 
