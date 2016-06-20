--- CAIR.cpp.orig	2016-06-20 15:51:27 UTC
+++ CAIR.cpp
@@ -276,7 +276,7 @@ inline CML_byte Grayscale_Pixel( CML_RGB
 //Our thread function for the Grayscale
 void * Gray_Quadrant( void * id )
 {
-	int num = *((int *)id);
+	long int num = *((long int *)id);
 
 	while( true )
 	{
@@ -437,7 +437,7 @@ int Convolve_Pixel( CML_image_ptr * Sour
 //The thread function, splitting the image into strips
 void * Edge_Quadrant( void * id )
 {
-	int num = *((int *)id);
+	long int num = *((long int *)id);
 
 	while( true )
 	{
@@ -744,7 +744,7 @@ CML_RGBA Average_Pixels( CML_RGBA Pixel1
 //This works like Remove_Quadrant, strips across the image.
 void * Add_Quadrant( void * id )
 {
-	int num = *((int *)id);
+	long int num = *((long int *)id);
 	Thread_Params add_area;
 
 	while( true )
@@ -907,7 +907,7 @@ bool CAIR_Add( CML_image * Source, CML_i
 //the areas are not quadrants, rather, more like strips, but I keep the name convention
 void * Remove_Quadrant( void * id )
 {
-	int num = *((int *)id);
+	long int num = *((long int *)id);
 	Thread_Params remove_area;
 
 	while( true )
