--- cfheader.cpp.orig	1999-10-24 02:13:29.000000000 -0400
+++ cfheader.cpp	2014-02-21 16:02:37.285291121 -0500
@@ -18,17 +18,23 @@
 #define __CFHEADER_CPP__
 
 #include <string.h>
-#include <fstream.h>
+#include <fstream>
 #include "bstring.h"
 #include "cftypes.h"
 #include "cfheader.h"
 
 #ifdef unix
-#include <strstream.h>
+#include <strstream>
 #else
 #include <strstrea.h>
 #endif
 
+using std::ios;
+using std::ifstream;
+using std::ofstream;
+using std::ostrstream;
+using std::ends;
+
 ////////////////////////////////////////****************************************
 
 // Initializes a valid fixed cabinet header
@@ -127,7 +133,7 @@
 		{
 			reserved_area = new byte[cabinet_ra_size];
 
-			if(in.read(reserved_area, cabinet_ra_size).bad())
+			if(in.read((char*)reserved_area, cabinet_ra_size).bad())
 			{
 				return (in.fail()) ? READ_ERROR : UNEXPECTED_EOF;
 			}
@@ -172,7 +178,7 @@
 
 		if(cabinet_ra_size > 0)			// If has cabinet reserved area
 		{
-			if(out.write(reserved_area, cabinet_ra_size).fail())
+			if(out.write((char*)reserved_area, cabinet_ra_size).fail())
 			{
 				return WRITE_ERROR;
 			}
@@ -210,4 +216,4 @@
 
 ////////////////////////////////////////****************************************
 
-#endif
\ No newline at end of file
+#endif
