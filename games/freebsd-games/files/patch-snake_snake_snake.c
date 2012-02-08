Index: snake/snake/snake.c
@@ -183,7 +181,7 @@
 	snrand(&money);
 	snrand(&snake[0]);
 
-	if ((orig.sg_ospeed < B9600) ||
+	if ((cfgetospeed(&orig) < B9600) ||
 	    ((! CM) && (! TA))) fast=0;
 	for(i=1;i<6;i++)
 		chase (&snake[i], &snake[i-1]);
