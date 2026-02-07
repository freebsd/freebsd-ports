--- eme.c.orig	2023-02-21 23:04:27 UTC
+++ eme.c
@@ -1543,7 +1543,7 @@ return (x-(int)(x))*2*PI_L;
 }
 
 
-void calculate_moon_data()
+void calculate_moon_data(void)
 {
 char s[80];
 int k, day;
