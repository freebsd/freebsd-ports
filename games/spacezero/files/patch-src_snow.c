--- src/snow.c.orig	2013-12-18 11:50:44 UTC
+++ src/snow.c
@@ -38,6 +38,7 @@
 
 #define NFLAKES 1000
 
+struct Flake *flakes;
 
 void CreateSnow(int w,int h){
   int i;
