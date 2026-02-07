--- siod.c	2014-03-25 04:10:42.000000000 -0400
+++ siod.c	2021-02-15 23:07:49.223752000 -0500
@@ -13,5 +13,5 @@
 #include "siod.h"
 
-static char *siod_argv[] = {
+static const char *siod_argv[] = {
   "siod",
   "-h1000000:50",
