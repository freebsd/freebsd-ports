--- src/main.c.orig	2015-01-19 20:19:08 UTC
+++ src/main.c
@@ -55,7 +55,7 @@ struct enemystruct enemy [NO_ENEMIES];
 struct ebulletstruct ebullet [NO_EBULLETS];
 struct pbulletstruct pbullet [NO_PBULLETS];
 struct arenastruct arena;
-struct eclassstruct eclass [NO_ENEMY_TYPES];
+extern struct eclassstruct eclass [NO_ENEMY_TYPES];
 struct cloudstruct cloud [NO_CLOUDS];
 struct bossstruct boss;
 
