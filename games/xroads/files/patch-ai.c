--- ai.c.orig	Sat Nov 20 09:50:36 2004
+++ ai.c	Sat Nov 20 09:50:56 2004
@@ -59,12 +59,12 @@
    int tries=0;
 
       /* If in a halfstep, finish it */
-   if(ntrunc(amonst->x)!=round(amonst->x)) switch(amonst->dir) {
+   if(ntrunc(amonst->x)!=xrround(amonst->x)) switch(amonst->dir) {
       case LEFT: amonst->x-=0.5; return;
       case RIGHT: amonst->x+=0.5; return;
       default: amonst->dir = directions[(int)rnd(2) + 2]; break;
       }
-   if(ntrunc(amonst->y)!=round(amonst->y)) switch(amonst->dir) {
+   if(ntrunc(amonst->y)!=xrround(amonst->y)) switch(amonst->dir) {
       case UP: amonst->y-=0.5; return;
       case DOWN: amonst->y+=0.5; return;
       default: amonst->dir = directions[(int)rnd(2)]; break;
@@ -84,9 +84,9 @@
       /* Find coordinates for new position */
    switch(dir) {
       case UP: y-=0.5; eqy=ntrunc(y); eqx=ntrunc(x); break;
-      case DOWN: y+=0.5; eqy=round(y); eqx=ntrunc(x); break;
+      case DOWN: y+=0.5; eqy=xrround(y); eqx=ntrunc(x); break;
       case LEFT: x-=0.5; eqy=ntrunc(y); eqx=ntrunc(x); break;
-      case RIGHT: x+=0.5; eqy=ntrunc(y); eqx=round(x); break;
+      case RIGHT: x+=0.5; eqy=ntrunc(y); eqx=xrround(x); break;
       default: printf("Error: Not a direction\n"); return;
       }
 
@@ -95,7 +95,7 @@
       goto tryagain;
 
       /* Check for double half-step */
-   if(ntrunc(x)!=round(x) && ntrunc(y)!=round(y)) goto tryagain;
+   if(ntrunc(x)!=xrround(x) && ntrunc(y)!=xrround(y)) goto tryagain;
 
       /* Did we hit a powerup? */
    if(data[xytotype(eqx, eqy)].etype == POWERUP) {
@@ -121,12 +121,12 @@
    float dx, dy, dz;
 
       /* If in a halfstep, finish it */
-   if(ntrunc(amonst->x)!=round(amonst->x)) switch(amonst->dir) {
+   if(ntrunc(amonst->x)!=xrround(amonst->x)) switch(amonst->dir) {
       case LEFT: amonst->x-=0.5; return;
       case RIGHT: amonst->x+=0.5; return;
       default: amonst->dir = directions[(int)rnd(2) + 2]; break;
       }
-   if(ntrunc(amonst->y)!=round(amonst->y)) switch(amonst->dir) {
+   if(ntrunc(amonst->y)!=xrround(amonst->y)) switch(amonst->dir) {
       case UP: amonst->y-=0.5; return;
       case DOWN: amonst->y+=0.5; return;
       default: amonst->dir = directions[(int)rnd(2)]; break;
@@ -146,8 +146,8 @@
    tryagain: /* Come back here to try again */
    tries++;
    if(tries>100) {
-      if(ntrunc(amonst->x)==round(amonst->x) &&
-         ntrunc(amonst->y)==round(amonst->y))
+      if(ntrunc(amonst->x)==xrround(amonst->x) &&
+         ntrunc(amonst->y)==xrround(amonst->y))
          watchentity(amonst, target);
       return;
       }
@@ -186,7 +186,7 @@
       goto tryagain;
 
       /* Be careful of half-steps */
-   if(ntrunc(x)!=round(x) && ntrunc(y)!=round(y)) goto tryagain;
+   if(ntrunc(x)!=xrround(x) && ntrunc(y)!=xrround(y)) goto tryagain;
 
       /* Did we hit a powerup? */
    if(data[xytotype(eqx, eqy)].etype == POWERUP) {
@@ -318,7 +318,7 @@
       printf("I was asked to kill a monster that shouldn't be killed!\n");
       if(amonst->health <= 0) {
          if(data[amonst->type].etype != EFFECT) {
-            maze[round(amonst->y)][round(amonst->x)] = -2; /* Blank */
+            maze[xrround(amonst->y)][xrround(amonst->x)] = -2; /* Blank */
             maze[ntrunc(amonst->y)][ntrunc(amonst->x)] = -2; /* Blank */
             }
          draw_tilex2(mainwindow, data[amonst->type].tile[amonst->frame],
@@ -332,8 +332,8 @@
                      bmonst->x*GRIDSIZE, bmonst->y*GRIDSIZE,
                      bmonst->color, bmonst->dir);
          }
-      if(maze[round(amonst->y)][round(amonst->x)]!=-2) {
-         bmonst=&monst[maze[round(amonst->y)][round(amonst->x)]];
+      if(maze[xrround(amonst->y)][xrround(amonst->x)]!=-2) {
+         bmonst=&monst[maze[xrround(amonst->y)][xrround(amonst->x)]];
          draw_tilex2(mainwindow, data[bmonst->type].tile[bmonst->frame],
                      bmonst->x*GRIDSIZE, bmonst->y*GRIDSIZE,
                      bmonst->color, bmonst->dir);
@@ -392,9 +392,9 @@
       amonst->atspeed = data[amonst->type].atspeed;
       switch(amonst->dir) {
          case LEFT: fx-=1; x=ntrunc(fx); y=ntrunc(fy); break;
-         case RIGHT: fx+=1; x=round(fx); y=ntrunc(fy); break;
+         case RIGHT: fx+=1; x=xrround(fx); y=ntrunc(fy); break;
          case UP: fy-=1; y=ntrunc(fy); x=ntrunc(fx); break;
-         case DOWN: fy+=1; y=round(fy); x=ntrunc(fx); break;
+         case DOWN: fy+=1; y=xrround(fy); x=ntrunc(fx); break;
          }
       icorrectpos(&x, &y);
       if(!checkdest(x, y)) {
@@ -460,8 +460,8 @@
    if(!(amonst->x == target->x || amonst->y == target->y)) return 0;
 
       /* Halfsteps are banned */
-   if(round(amonst->x) != ntrunc(amonst->x)) return 0;
-   if(round(amonst->y) != ntrunc(amonst->y)) return 0;
+   if(xrround(amonst->x) != ntrunc(amonst->x)) return 0;
+   if(xrround(amonst->y) != ntrunc(amonst->y)) return 0;
 
       /* Force x1, y1 to be smaller pair */
    if(x1 > x2) {
