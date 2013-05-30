--- ./batt.c.orig	1997-05-13 15:45:51.000000000 +0000
+++ ./batt.c	2013-05-28 08:46:50.000000000 +0000
@@ -13,7 +13,7 @@
 int salvo_play=0;                                 /* paramaters uncluttered*/
 int first_time=0;
 
-int main(int argc, char *argv)
+int main(int argc, char **argv)
 {  
    MAIN_THINGY *main_thing;
    
