--- CAIR.cpp.orig	2010-03-16 08:51:06.000000000 +0800
+++ CAIR.cpp	2010-03-16 08:55:11.000000000 +0800
@@ -276,7 +276,7 @@
 //Our thread function for the Grayscale
 void * Gray_Quadrant( void * id )
 {
-	int num = *((int *)id);
+	long int num = *((long int *)id);
 
 	while( true )
 	{
@@ -437,7 +437,7 @@
 //The thread function, splitting the image into strips
 void * Edge_Quadrant( void * id )
 {
-	int num = *((int *)id);
+	long int num = *((long int *)id);
 
 	while( true )
 	{
@@ -744,7 +744,7 @@
 //This works like Remove_Quadrant, strips across the image.
 void * Add_Quadrant( void * id )
 {
-	int num = *((int *)id);
+	long int num = *((long int *)id);
 	Thread_Params add_area;
 
 	while( true )
@@ -907,7 +907,7 @@
 //the areas are not quadrants, rather, more like strips, but I keep the name convention
 void * Remove_Quadrant( void * id )
 {
-	int num = *((int *)id);
+	long int num = *((long int *)id);
 	Thread_Params remove_area;
 
 	while( true )
