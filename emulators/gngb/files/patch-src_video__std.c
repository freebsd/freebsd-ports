--- src/video_std.c.orig	2005-12-11 09:53:02 UTC
+++ src/video_std.c
@@ -30,14 +30,21 @@
 
 static Uint32 std_flag;
 SDL_Surface *back=NULL;
+Uint8 rb_on;
+Uint8 rb_shift;
 
-
 Sint8 rb_tab[2][RB_SIZE]={{0,-2,2,-2,2},
 			 {0,-1,-1,1,1}};
 
 VIDEO_MODE video_std;
 
+SDL_Rect scrR;
+SDL_Rect dstR;
 SDL_Rect clip_rct;
+SDL_Rect ov_rect;
+
+int scxoff,scyoff;
+
 Uint8 win_line=0;
 
 /*
