--- main.C.orig	Sun Jan  9 01:15:53 2000
+++ main.C	Sun Jan  9 01:15:55 2000
@@ -366,7 +366,7 @@
 
 	if (in1) 					p1 = new PBall( game_pball, in1 );
 	if (in2)						p2 = new PBall( game_pball, in2 );
-	if (!demo_flag&&!p1)		p1 = new PBall( game_pball, (disp)?disp:"" );
+	if (!demo_flag&&!p1)		p1 = new PBall( game_pball, (disp)?disp:(char *)"" );
 
 
 	g->DrawBackground();
