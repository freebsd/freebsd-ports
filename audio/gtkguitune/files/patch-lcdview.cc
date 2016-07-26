--- lcdview.cc.orig	2008-09-16 09:56:09 UTC
+++ lcdview.cc
@@ -23,11 +23,12 @@
 
 #include "lcdview.h"
 
-LCDView::LCDView(const char * str = 0)
+LCDView::LCDView(const char * str)
 {
     i_LCD_num = 11;
     i_string_maxlen = 1000;
     i_string = new char [i_string_maxlen];
+    str = 0;
     set( str );
         
     i_col_bg. set( "black" );      get_colormap()->alloc_color( i_col_bg  );
