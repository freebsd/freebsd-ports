
$FreeBSD$

--- shmap/shmap.c.orig	Mon Dec 30 22:56:29 2002
+++ shmap/shmap.c	Mon Dec 30 22:59:36 2002
@@ -706,7 +706,7 @@
 /*
         returns the amount of items in hashmap
 */
-unsigned int shmap_items ( shmap * map )
+size_t shmap_items ( shmap * map )
 {
         CHECK_NULL0(map)
 
