--- main.cc.orig	Sat Oct 18 01:27:29 2003
+++ main.cc	Sun Nov 16 18:16:41 2003
@@ -28,6 +28,7 @@
 #include <cstring>
 #include <vector>
 #include <getopt.h>
+#include <libgen.h>
 #include "common.h"
 #include "rectangle.h"
 #include "bitmap.h"
@@ -289,8 +290,8 @@
     {
     if( infile == stdin )
       {
-      std::ungetc( std::getc( infile ), infile );
-      if( std::feof( infile ) || std::ferror( infile ) ) infile = 0;
+      ungetc( getc( infile ), infile );
+      if( feof( infile ) || ferror( infile ) ) infile = 0;
       }
     while( infile != stdin )
       {
