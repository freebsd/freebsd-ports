--- src/message.c.orig	2003-04-03 13:27:29 UTC
+++ src/message.c
@@ -34,6 +34,7 @@ static int tempo_mes;
 
 #define BUF_ALPHA 240
 
+int wl,hl,xm,ym;
 char mes_buf[50];
 char info_buf[50];
 //extern SDL_Surface *gb_screen;
