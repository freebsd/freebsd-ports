--- cnv/giftorle.c.orig	Thu Mar 10 20:04:40 2005
+++ cnv/giftorle.c	Thu Mar 10 20:07:12 2005
@@ -278,7 +278,7 @@
 	max_code_size = 2*clear_code;
 	max_code = clear_code+2;
 
-	GetCode(fd,NULL,TRUE);
+	GetCode(fd,0,TRUE);
 		
 	fresh=TRUE;
 
