--- game/team.h.orig	2008-04-16 11:31:25.000000000 +0400
+++ game/team.h	2013-05-30 21:54:04.534113336 +0400
@@ -14,7 +14,7 @@
 		Team();
 		~Team();
 
-		void init(Game::team_t t,const Theme *t);
+		void init(Game::team_t t,const Theme *theme);
 		void update();
 		void shutdown();
 
