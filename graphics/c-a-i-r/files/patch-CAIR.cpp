--- CAIR.cpp.orig	2008-10-19 19:15:39.000000000 +0800
+++ CAIR.cpp	2008-10-19 19:17:24.000000000 +0800
@@ -252,7 +252,7 @@
 //Our thread function for the Grayscale
 void * Gray_Quadrant( void * id )
 {
-	int num = (int)id;
+	long int num = (long int)id;
 
 	while( true )
 	{
@@ -417,7 +417,7 @@
 //This is multi-threaded to 4 threads, spliting the image into 4 strips
 void * Edge_Quadrant( void * id )
 {
-	int num = (int)id;
+	long int num = (long int)id;
 
 	while( true )
 	{
@@ -612,7 +612,7 @@
 //=========================================================================================================//
 void * Energy_Left( void * id )
 {
-	int num = (int)id;
+	long int num = (long int)id;
 	int energy = 0;// current calculated enery
 	int min_x = 0, max_x = 0;
 
@@ -727,7 +727,7 @@
 //=========================================================================================================//
 void * Energy_Right( void * id )
 {
-	int num = (int)id;
+	long int num = (long int)id;
 	int energy = 0;// current calculated enery
 	int min_x = 0, max_x = 0;
 
@@ -938,7 +938,7 @@
 //This works like Remove_Quadrant, stripes across the image.
 void * Add_Quadrant( void * id )
 {
-	int num = (int)id;
+	long int num = (long int)id;
 	Thread_Params add_area;
 
 	while( true )
@@ -1245,7 +1245,7 @@
 //the areas are not quadrants, rather, more like strips, but I keep the name convention
 void * Remove_Quadrant( void * id )
 {
-	int num = (int)id;
+	long int num = (long int)id;
 	Thread_Params remove_area;
 
 	while( true )
