--- lscore.c.org	Mon Oct 27 00:07:24 1997
+++ lscore.c	Wed Feb 18 22:33:56 1998
@@ -21,7 +21,7 @@
     FILE *lfp;
 
     for( i = 3; i; i-- )
-        if( lfp = fopen(lf,"r") )
+        if( (lfp = fopen(lf,"r")) )
         {
             fclose(lfp);
             sleep(2);
@@ -47,7 +47,7 @@
 
     lock_score();
     memset(scores,0,sizeof(scores));
-    if( sfp = fopen(sf,"r") )
+    if( (sfp = fopen(sf,"r")) )
     {
         for( scp = scores; scp < &scores[MAXSCORE]; scp++ )
             if( fscanf(sfp,"%d%d%d%d",
@@ -67,8 +67,8 @@
     SCORE *scp;
     for( scp = &scores[MAXSCORE]; scp > scores; scp-- )
         if( scp[0].score >  scp[-1].score ||
-            scp[0].score == scp[-1].score &&
-            scp[0].level >= scp[-1].level )
+            (scp[0].score == scp[-1].score &&
+             scp[0].level >= scp[-1].level ))
         {
             SCORE tmp = scp[0];
             scp[0] = scp[-1];
@@ -113,7 +113,7 @@
         if( scores[i].score )
         {
             printw("%5d00  %2d  ",scores[i].score,scores[i].level + 1);
-            if( pw = getpwuid(scores[i].uid) )
+            if( (pw = getpwuid(scores[i].uid)) )
                 addstr(pw->pw_name);
             else
                 printw("UID %d",scores[i].uid);
