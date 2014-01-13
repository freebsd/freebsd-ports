--- ./main.c.orig	2012-09-20 19:56:38.000000000 +0200
+++ ./main.c	2014-01-11 04:44:10.000000000 +0100
@@ -242,7 +242,7 @@
     }
 }
 
-int wb_select(){
+void wb_select(){
     option_t *opt;
     option_start_iter(Option);
     while((opt=option_next(Option))){
