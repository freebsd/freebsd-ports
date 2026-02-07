--- src/vram.h.orig	2003-05-09 05:26:20 UTC
+++ src/vram.h
@@ -62,7 +62,7 @@ struct mask_shift {
 
 extern struct mask_shift tab_ms[8];
 extern Uint32 video_flag;
-int scxoff,scyoff;		/* shift of the screen */
+extern int scxoff,scyoff;		/* shift of the screen */
 
 extern Uint16 grey[4];
 extern Uint8 pal_bck[4];
@@ -89,10 +89,10 @@ typedef struct {
   Uint8 priority;
 }GB_SPRITE;
 
-GB_SPRITE gb_spr[40];
+extern GB_SPRITE gb_spr[40];
 extern Uint8 nb_spr;
 
-Uint8 rb_on;
+extern Uint8 rb_on;
 
 extern void (*draw_screen)(void);
 
