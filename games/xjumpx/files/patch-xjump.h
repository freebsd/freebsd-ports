--- xjump.h.orig	2001-08-14 20:10:46.000000000 +0800
+++ xjump.h	2011-09-05 15:22:10.000000000 +0800
@@ -103,6 +103,14 @@ void FLOOR_move_all( int scroll,int leve
 floor_t *FLOOR_check(int hx, int hy);
 void FLOOR_init( void );
 
+void HERO_init( hero_t *hp );
+int HERO_move( hero_t *hp, int scroll, int key );
+void HERO_draw( hero_t *hp );
+void HERO_delete( hero_t *hp );
+
+int rnd( int range );
+void srnd( int seed );
+void get_name( char *buf, int bufsiz, int uid );
 
 void GAME_init( void );
 int GAME_main( int move );
