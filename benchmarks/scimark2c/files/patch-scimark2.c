--- scimark2.c.orig	2006-07-25 20:11:47 UTC
+++ scimark2.c
@@ -58,7 +58,7 @@ int main(int argc, char *argv[])
 
 	
 		print_banner();
-		printf("Using %10.2f seconds min time per kenel.\n", min_time);
+		printf("Using %10.2f seconds min time per kernel.\n", min_time);
 
         res[1] = kernel_measureFFT( FFT_size, min_time, R);   
         res[2] = kernel_measureSOR( SOR_size, min_time, R);   
