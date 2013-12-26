--- ./transition.c.orig	2002-05-31 05:15:46.000000000 +0200
+++ ./transition.c	2013-12-24 13:48:47.000000000 +0100
@@ -164,7 +164,8 @@
 	// wait for click, scroll score (or whatever)
 	while (!done) 
 	{
-		while(pollevent(&event));
+		while(pollevent(&event))
+		;
 		{
 			if (event.type == SDL_QUIT)
 			{
