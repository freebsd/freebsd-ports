--- scimark4.c.orig	2018-07-29 20:02:32 UTC
+++ scimark4.c
@@ -106,7 +106,7 @@ int main(int argc, char *argv[])
 
   
  print_banner();
- printf("Using %10.2f seconds min time per kenel.", min_time);
+ printf("Using %10.2f seconds min time per kernel.", min_time);
  if (huge_flag)
  {
       printf(" Approx. problem size: %d (MB)", atoi(argv[2]));
