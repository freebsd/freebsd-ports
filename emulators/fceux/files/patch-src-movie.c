--- src/movie.c.orig	Sat Aug 14 07:13:51 2004
+++ src/movie.c	Sat Aug 14 07:15:58 2004
@@ -154,7 +154,7 @@
 
 void FCEUMOV_AddJoy(uint8 *js)
 {
- int x,y;
+ int x,y,tmpfix;
 
  if(!current) return;	/* Not playback nor recording. */
 
@@ -190,7 +190,7 @@
    tmp >>= 5;
    tmp &= 0x3;
    ti=0;
-   int tmpfix = tmp;
+   tmpfix = tmp;
    while(tmp--) { nextts |= fgetc(slots[-1 - current]) << (ti * 8); ti++; }
 
    // This fixes a bug in movies recorded before version 0.98.11
