--- src/movie.c.orig	Tue Aug 31 07:35:21 2004
+++ src/movie.c	Tue Aug 31 07:35:57 2004
@@ -154,7 +154,7 @@
 
 void FCEUMOV_AddJoy(uint8 *js)
 {
- int x,y;
+ int x,y,tmpfix;
 
  if(!current) return;	/* Not playback nor recording. */
 
@@ -191,7 +191,7 @@
    tmp &= 0x3;
    ti=0;
 
-   int tmpfix = tmp;
+   tmpfix = tmp;
    while(tmp--) { nextts |= fgetc(slots[-1 - current]) << (ti * 8); ti++; }
 
    // This fixes a bug in movies recorded before version 0.98.11
