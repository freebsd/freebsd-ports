--- data.c.orig	2013-11-17 11:25:40.820307151 +0400
+++ data.c	2013-11-17 11:27:32.743383408 +0400
@@ -460,7 +460,7 @@
 my_double can_go_x(my_double old_x,my_double new_x,int yh, int yl,unsigned char *flag)
 {
 	int x,y;
-	
+	if (yh<0) yh=0;
 	if (old_x==new_x+.5)
 	{
 		if(flag)*flag=0;
@@ -494,7 +494,7 @@
 my_double can_go_y(my_double old_y, my_double new_y,int xl, int xr,unsigned char *flag,unsigned char down_ladder)
 {
 	int x,y;
-	
+	if (xl<0) xl=0;
 	if (old_y==new_y){if(flag)*flag=0;return new_y;}
 	if(flag)*flag=1;
 	if (old_y<new_y)
