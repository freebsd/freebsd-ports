--- include/snow.h.orig	2013-12-18 11:52:33 UTC
+++ include/snow.h
@@ -29,7 +29,7 @@
 #include "objects.h"
 
 
-struct Flake *flakes;
+extern struct Flake *flakes;
 
 struct Flake{
   float x,y;
