--- gbpage.c.orig	2013-09-26 20:18:53.000000000 +0800
+++ gbpage.c	2013-09-26 20:19:22.000000000 +0800
@@ -13,6 +13,7 @@
 
 #include "gb2ps.h"
 
+void
 init_page()
 {
 /* define margins, line space and character space*/
@@ -39,7 +40,7 @@ init_page()
 	page[1]=page[0];
 }
 
-
+void
 begin_page()
 {
 
@@ -73,6 +74,7 @@ begin_page()
 		V=_TM-line_h[linecounter];	charcount=0;
 }
 
+void
 end_page ()
 {
 	if (pagecounter) {
@@ -97,6 +99,7 @@ end_page ()
 	pagecounter++;
 }
 
+void
 ps_header ()
 {
   fprintf(out,"%%!PS-Adobe-1.0\n");
@@ -110,9 +113,8 @@ ps_header ()
   fprintf(out,"%%%%EndProlog\n");
 }
 
+void
 ps_end()
 {
 	fprintf(out,"%%%%Trailer\n");
 }
-
-
