--- driver/parse.y.orig	Mon Dec  2 00:00:22 2002
+++ driver/parse.y	Mon Dec  2 00:00:33 2002
@@ -133,6 +133,7 @@
 %%
 
 start: section_list
+     ;
 
 section_list
 	: section
