--- server/externs.h.orig	2015-05-03 12:56:01 UTC
+++ server/externs.h
@@ -455,9 +455,9 @@ extern auction_type *auctions;
 extern u32b auction_alloc;
 
 /* Array used by everyone_lite_later_spot */
-struct worldspot *lite_later;
-int lite_later_alloc;
-int lite_later_num;
+extern struct worldspot *lite_later;
+extern int lite_later_alloc;
+extern int lite_later_num;
 
 /*
  * The spell list of schools
