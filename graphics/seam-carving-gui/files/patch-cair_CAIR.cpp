--- cair/CAIR.cpp.orgi	2008-11-23 23:22:33.000000000 +0100
+++ cair/CAIR.cpp	2008-11-23 23:23:59.000000000 +0100
@@ -260,7 +260,7 @@
 //Our thread function for the Grayscale
 void * Gray_Quadrant( void * id )
 {
-	int num = (int)id;
+	long int num = (long int)id;
 
 	while( true )
 	{
@@ -425,7 +425,7 @@
 //The thread function, splitting the image into strips
 void * Edge_Quadrant( void * id )
 {
-	int num = (int)id;
+	long int num = (long int)id;
 
 	while( true )
 	{
@@ -619,7 +619,7 @@
 //=========================================================================================================//
 void * Energy_Left( void * id )
 {
-	int num = (int)id;
+	long int num = (long int)id;
 	int energy = 0;// current calculated enery
 	int min_x = 0, max_x = 0;
 
@@ -734,7 +734,7 @@
 //=========================================================================================================//
 void * Energy_Right( void * id )
 {
-	int num = (int)id;
+	long int num = (long int)id;
 	int energy = 0;// current calculated enery
 	int min_x = 0, max_x = 0;
 
@@ -945,7 +945,7 @@
 //This works like Remove_Quadrant, stripes across the image.
 void * Add_Quadrant( void * id )
 {
-	int num = (int)id;
+	long int num = (long int)id;
 	Thread_Params add_area;
 
 	while( true )
@@ -1260,7 +1260,7 @@
 //the areas are not quadrants, rather, more like strips, but I keep the name convention
 void * Remove_Quadrant( void * id )
 {
-	int num = (int)id;
+	long int num = (long int)id;
 	Thread_Params remove_area;
 
 	while( true )
