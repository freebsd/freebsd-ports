--- scimark2.c.orig	Sat Apr 29 06:21:12 2000
+++ scimark2.c	Sat Apr  5 23:13:45 2003
@@ -58,7 +58,7 @@
 
 	
 		print_banner();
-		printf("Using %10.2f seconds min time per kenel.\n", min_time);
+		printf("Using %10.2f seconds min time per kernel.\n", min_time);
 
         res[1] = kernel_measureFFT( FFT_size, min_time, R);   
         res[2] = kernel_measureSOR( SOR_size, min_time, R);   
