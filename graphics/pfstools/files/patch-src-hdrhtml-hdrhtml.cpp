--- src/hdrhtml/hdrhtml.cpp.orig	2009-03-11 21:45:55 UTC
+++ src/hdrhtml/hdrhtml.cpp
@@ -27,6 +27,7 @@
 
 #include "hdrhtml.h"
 
+#include <limits>
 #include <algorithm>
 #include <math.h>
 #include <fstream>
@@ -48,6 +49,8 @@
 
 #include <config.h>
 
+#define log2f(x)	((float)logf(x)/logf(2))
+
 // ================================================
 //        Parameters controllig the web page 
 // ================================================
@@ -94,8 +97,8 @@ public:
     
     if( min_val > max_val )             // missing min/max info
     {
-      min_val = numeric_limits<T>::max();
-      max_val = numeric_limits<T>::min();
+      min_val = std::numeric_limits<T>::max();
+      max_val = std::numeric_limits<T>::min();
 
       for( int k=0; k < d_size; k++ ) {
         if( data[k] > max_val ) max_val = data[k];
@@ -195,6 +198,7 @@ public:
     this->y_i = new float[lut_size];
     own_y_i = true;
     memcpy(this->y_i, other.y_i, lut_size * sizeof(float));
+    return *this;
   }
 
   ~UniformArrayLUT()
@@ -341,7 +345,7 @@ public:
     for( int k = 1; k < bin_n; k++ )
       hist.n[k] += hist.n[k-1];
 
-//    cerr << "d_size: " << d_size << "  hist.n: " << hist.n[bin_n-1] << "\n";
+//    std::cerr << "d_size: " << d_size << "  hist.n: " << hist.n[bin_n-1] << "\n";
     assert( hist.n[bin_n-1] == d_size );    
   }
 
@@ -361,7 +365,7 @@ public:
 //            Text template file utils
 // ================================================
 
-typedef void (*replace_callback)( ostream &out, void *user_data, const char *parameter );
+typedef void (*replace_callback)( std::ostream &out, void *user_data, const char *parameter );
 
 class ReplacePattern
 {
@@ -403,7 +407,7 @@ public:
   {
   }
   
-  virtual void write_replacement( ostream &out, const char *parameter = NULL )
+  virtual void write_replacement( std::ostream &out, const char *parameter = NULL )
   {
     if( callback != NULL )
       callback( out, user_data, parameter );
@@ -567,7 +571,7 @@ public:
         // Skip white spaces
         while( line_str[pos] == ' ' || line_str[pos] == '\t' ) pos++;
         int new_pos = line_str.find_first_of( ',', pos );
-        int len;
+        size_t len;
         if( new_pos == std::string::npos ) {
           if( k != columns-1 ) {
             std::string full_message( "Missing column data in the file: " );
@@ -576,16 +580,16 @@ public:
           }
           len = std::string::npos;
         } else
-          len = new_pos-pos;
+          len = (size_t)(new_pos-pos);
         
         float value;
         if( len == 0 ) {
-          value = numeric_limits<float>::quiet_NaN();
+          value = std::numeric_limits<float>::quiet_NaN();
         } else {
           std::string token = line_str.substr( pos, len );
           const char *str_beg = token.c_str();
           char *str_end;
-//          cerr << "token: " << str_beg << "\n";
+//          std::cerr << "token: " << str_beg << "\n";
           value = strtof( str_beg, &str_end );
           if( str_beg == str_end ) {
             std::ostringstream error_message;
@@ -643,15 +647,15 @@ void HDRHTMLSet::add_image( int width, i
     basis_table.data[0][k] = log2f( basis_table.data[0][k] );
   
 // Fix zero and negative values in the image, convert to log2 space, find min and max values
-  float img_min = numeric_limits<float>::max();
-  float img_max = numeric_limits<float>::min();
+  float img_min = std::numeric_limits<float>::max();
+  float img_max = std::numeric_limits<float>::min();
   {
     float *arrays[] = { R, G, B, Y };
     int k;
 
     for( k = 0; k < 4; k++ ) {
       float *x = arrays[k];
-      float min_val = numeric_limits<float>::max(), max_val = numeric_limits<float>::min();
+      float min_val = std::numeric_limits<float>::max(), max_val = std::numeric_limits<float>::min();
       for( int i=0; i < pixels; i++ ) {
         if( x[i] < min_val && x[i] > 0)
           min_val = x[i];
@@ -741,7 +745,7 @@ void HDRHTMLSet::add_image( int width, i
   for( int k=1; k <= f8_stops+1; k++ ) {
 
 
-    float max_value = (float)numeric_limits<unsigned short>::max(); //(1<<16) -1;
+    float max_value = (float)std::numeric_limits<unsigned short>::max(); //(1<<16) -1;
 
     float exp_multip = log2f(1/powf( 2, l_start + k*8 ));
 
@@ -796,9 +800,9 @@ void HDRHTMLSet::add_image( int width, i
   
 }
 
-void print_image_objects( ostream &out, void *user_data, const char *parameter );
-void print_cf_table( ostream &out, void *user_data, const char *parameter );
-void print_image_htmlcode( ostream &out, void *user_data, const char *parameter );
+void print_image_objects( std::ostream &out, void *user_data, const char *parameter );
+void print_cf_table( std::ostream &out, void *user_data, const char *parameter );
+void print_image_htmlcode( std::ostream &out, void *user_data, const char *parameter );
 
 void HDRHTMLSet::generate_webpage( const char *page_template, const char *image_template,
   const char *object_output, const char *html_output)
@@ -852,11 +856,11 @@ void HDRHTMLSet::generate_webpage( const
   
 }
 
-void print_image_objects( ostream &out, void *user_data, const char *parameter )
+void print_image_objects( std::ostream &out, void *user_data, const char *parameter )
 {
   HDRHTMLSet *hdrhtml_set = (HDRHTMLSet*)user_data;
 
-  list<HDRHTMLImage>::iterator it;
+  std::list<HDRHTMLImage>::iterator it;
   for( it = hdrhtml_set->image_list.begin(); it != hdrhtml_set->image_list.end(); it++ ) {  
     std::string obj_name( "hdr_" );
     obj_name.append( it->base_name );
@@ -882,7 +886,7 @@ void print_image_objects( ostream &out, 
   
 }
 
-void print_image_htmlcode( ostream &out, HDRHTMLSet *hdrhtml_set, const HDRHTMLImage &it )
+void print_image_htmlcode( std::ostream &out, HDRHTMLSet *hdrhtml_set, const HDRHTMLImage &it )
 {
     std::string obj_name( "hdr_" );
     obj_name.append( it.base_name );
@@ -907,13 +911,13 @@ void print_image_htmlcode( ostream &out,
  
 }
 
-void print_image_htmlcode( ostream &out, void *user_data, const char *parameter )
+void print_image_htmlcode( std::ostream &out, void *user_data, const char *parameter )
 {
   HDRHTMLSet *hdrhtml_set = (HDRHTMLSet*)user_data;
 
   if( parameter != NULL ) {
 
-    list<HDRHTMLImage>::iterator it;
+    std::list<HDRHTMLImage>::iterator it;
     for( it = hdrhtml_set->image_list.begin(); it != hdrhtml_set->image_list.end(); it++ ) {
       if( it->base_name.compare( parameter ) == 0 )
         break;
@@ -925,7 +929,7 @@ void print_image_htmlcode( ostream &out,
     
   } else {
     
-    list<HDRHTMLImage>::iterator it;
+    std::list<HDRHTMLImage>::iterator it;
     for( it = hdrhtml_set->image_list.begin(); it != hdrhtml_set->image_list.end(); it++ ) {
       
       print_image_htmlcode( out, hdrhtml_set, *it );
@@ -935,7 +939,7 @@ void print_image_htmlcode( ostream &out,
   
 }
 
-void print_cf_table( ostream &out, void *user_data, const char *parameter )
+void print_cf_table( std::ostream &out, void *user_data, const char *parameter )
 {
   CSVTable *cf = (CSVTable*)user_data;
   
