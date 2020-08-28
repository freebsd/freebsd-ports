--- init.c.orig	1995-11-23 22:18:58 UTC
+++ init.c
@@ -19,7 +19,6 @@ char    *title;
 PAPER   paper;
 int     min_bm;
 int     min_lm;
-int     s_width;
 int     s_width_nl;
 
 /* Exact hangul Postscript font names 
@@ -211,7 +210,7 @@ setnalza()
     Time = localtime(&T.tv_sec);
     sprintf(nalza, "%02d:%02d,    %d/%d/%d",
 	    Time->tm_hour,  Time->tm_min,
-            Time->tm_mon+1, Time->tm_mday, Time->tm_year );
+            Time->tm_mon+1, Time->tm_mday, Time->tm_year + 1900);
 }
 
 /***  EOF  ***/
