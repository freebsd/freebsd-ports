--- xroads.c.orig	Fri Jul 16 21:37:03 1999
+++ xroads.c	Sat Nov 20 10:01:35 2004
@@ -318,7 +318,7 @@
 }
 
 /*************************************************************************************************/
-int round( float num ) {  /* Round a float to an int */
+int xrround( float num ) {  /* Round a float to an int */
    return (int)(num+0.5);
 }
 
@@ -452,8 +452,8 @@
             }
 
          /* VacAttack */
-      if(data[amonst->type].attack1==VACCUUM && (round(amonst->x) ==
-         ntrunc(amonst->x) && round(amonst->y) == ntrunc(amonst->y)) &&
+      if(data[amonst->type].attack1==VACCUUM && (xrround(amonst->x) ==
+         ntrunc(amonst->x) && xrround(amonst->y) == ntrunc(amonst->y)) &&
          clearshot(amonst, &monst[targ]) && amonst->team!=monst[targ].team
          && data[monst[targ].type].etype != POWERUP) {
          watchentity(amonst, &monst[targ]);
@@ -479,9 +479,9 @@
       else amonst->frame++;
 
       if(data[amonst->type].etype!=EFFECT) {
-         maze[round(oldy)][round(oldx)]=-2; /* Blank out old space */
+         maze[xrround(oldy)][xrround(oldx)]=-2; /* Blank out old space */
          maze[ntrunc(oldy)][ntrunc(oldx)]=-2;
-         maze[round(amonst->y)][round(amonst->x)]=number;
+         maze[xrround(amonst->y)][xrround(amonst->x)]=number;
          maze[ntrunc(amonst->y)][ntrunc(amonst->x)]=number;
          }
 
@@ -491,8 +491,8 @@
          draw_tilex2(mainwindow, data[bmonst->type].tile[bmonst->frame], (bmonst->x)*GRIDSIZE,
                      (bmonst->y)*GRIDSIZE, bmonst->color, bmonst->dir);
          }
-      if(maze[round(amonst->y)][round(amonst->x)]!=-2) {
-         bmonst=&monst[maze[round(amonst->y)][round(amonst->x)]];
+      if(maze[xrround(amonst->y)][xrround(amonst->x)]!=-2) {
+         bmonst=&monst[maze[xrround(amonst->y)][xrround(amonst->x)]];
          draw_tilex2(mainwindow, data[bmonst->type].tile[bmonst->frame], (bmonst->x)*GRIDSIZE,
                      (bmonst->y)*GRIDSIZE, bmonst->color, bmonst->dir);
          }
@@ -615,7 +615,7 @@
    else if(player->attr & PULL_R) { newx+=1; player->attr &= ~PULL_R; }
 
       /* Only one half-step at a time */
-   if(round(newx)!=ntrunc(newx) && round(newy)!=ntrunc(newy)) {
+   if(xrround(newx)!=ntrunc(newx) && xrround(newy)!=ntrunc(newy)) {
 #ifdef DEBUG
       printf("Damn, in two half-steps at a time...\n");
 #endif
@@ -631,17 +631,17 @@
 
       /* If we're in a half-step, eqx and eqy are the space we're moving
          into */
-   if(round(newx)!=ntrunc(newx)) {
+   if(xrround(newx)!=ntrunc(newx)) {
       eqy = ntrunc(newy);
       if(newx > player->x)
-         eqx = round(newx);
+         eqx = xrround(newx);
       else if(newx < player->x)
          eqx = ntrunc(newx);
       }
-   else if(round(newy)!=ntrunc(newy)) {
+   else if(xrround(newy)!=ntrunc(newy)) {
       eqx = ntrunc(newx);
       if(newy > player->y)
-         eqy = round(newy);
+         eqy = xrround(newy);
       else if(newy < player->y)
          eqy = ntrunc(newy);
       }
@@ -652,9 +652,9 @@
 /*
    switch(player->dir) {
       case LEFT: eqx = ntrunc(newx); break;
-      case RIGHT: eqx = round(newx); break;
+      case RIGHT: eqx = xrround(newx); break;
       case UP: eqy = ntrunc(newy); break;
-      case DOWN: eqy = round(newy); break;
+      case DOWN: eqy = xrround(newy); break;
       default: break;
       }
 */
@@ -667,8 +667,8 @@
    printf("Destination (%0.2f, %0.2f)...\n", newx, newy);
    printf("Equiv (%d, %d)\n", eqx, eqy);
    printf("@ %d, %d : %d\n", eqx, eqy, maze[eqy][eqx]);
-   printf("newx: %0.2f: round %d, ntrunc %d\n", newx, round(newx), ntrunc(newx));
-   printf("newy: %0.2f: round %d, ntrunc %d\n", newy, round(newy), ntrunc(newy));
+   printf("newx: %0.2f: round %d, ntrunc %d\n", newx, xrround(newx), ntrunc(newx));
+   printf("newy: %0.2f: round %d, ntrunc %d\n", newy, xrround(newy), ntrunc(newy));
    printf("Checkdest: %d\n", checkdest(eqx, eqy));
    printf("-----\n");
    }
@@ -704,7 +704,7 @@
 #ifdef DEBUG
       printf("something in the way. (%d or %d)\n",
              maze[ntrunc(newy)][ntrunc(newx)],
-             maze[round(newy)][round(newy)]);
+             maze[xrround(newy)][xrround(newy)]);
 #endif
       newx=player->x;
       newy=player->y;
@@ -715,14 +715,14 @@
 #endif
 
      /* Destination has been set, now all we have to do is move there */
-   maze[round(player->y)][round(player->x)]=-2;
+   maze[xrround(player->y)][xrround(player->x)]=-2;
    maze[ntrunc(player->y)][ntrunc(player->x)]=-2;
    draw_tilex2(mainwindow, blank, player->x*GRIDSIZE, player->y*GRIDSIZE,
                BLACK, RIGHT);
 
       /* Draw player */
    player->x=newx; player->y=newy;
-   maze[round(player->y)][round(player->x)]=player->ind;
+   maze[xrround(player->y)][xrround(player->x)]=player->ind;
    maze[ntrunc(player->y)][ntrunc(player->x)]=player->ind;
    draw_tilex2(mainwindow, data[datapos].tile[player->frame],
                player->x*GRIDSIZE, player->y*GRIDSIZE,
@@ -1340,7 +1340,7 @@
          player[i]->health = 0;
          if(player[i]->attr & ACTIVE) {
             player[i]->attr ^= ACTIVE;
-            maze[round(player[i]->y)][round(player[i]->x)] = -2;
+            maze[xrround(player[i]->y)][xrround(player[i]->x)] = -2;
             maze[ntrunc(player[i]->y)][ntrunc(player[i]->x)] = -2;  
             draw_tilex2(mainwindow, blank, player[i]->x*GRIDSIZE,
                         player[i]->y*GRIDSIZE, BLACK, RIGHT);
