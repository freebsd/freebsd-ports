--- main.c.orig	2008-03-06 06:58:16.000000000 +0900
+++ main.c	2012-04-23 14:26:03.000000000 +0900
@@ -836,6 +836,7 @@
     if(gameOver) {
         while(W_EventsPending()) {
             W_NextEvent(&wev);
+	    if (wev.key >= 256) wev.key -= 256;
         
 	    if(gameOver)
 	      mouseControl = 1;
@@ -922,6 +923,7 @@
 
     while(W_EventsPending()) {
         W_NextEvent(&wev);
+	if (wev.key >= 256) wev.key -= 256;
 
         switch(wev.type) {
         case W_EV_KEY_OFF:
