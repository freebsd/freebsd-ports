--- cfheader.cpp.orig	Tue Aug 19 18:24:35 2003
+++ cfheader.cpp	Tue Aug 19 18:28:27 2003
@@ -24,11 +24,14 @@
 #include "cfheader.h"
 
 #ifdef unix
-#include <strstream.h>
+#include <strstream>
 #else
 #include <strstrea.h>
 #endif
 
+using std::ostrstream;
+using std::ends;
+
 ////////////////////////////////////////****************************************
 
 // Initializes a valid fixed cabinet header
@@ -127,7 +130,7 @@
 		{
 			reserved_area = new byte[cabinet_ra_size];
 
-			if(in.read(reserved_area, cabinet_ra_size).bad())
+			if(in.read((char*)reserved_area, cabinet_ra_size).bad())
 			{
 				return (in.fail()) ? READ_ERROR : UNEXPECTED_EOF;
 			}
@@ -172,7 +175,7 @@
 
 		if(cabinet_ra_size > 0)			// If has cabinet reserved area
 		{
-			if(out.write(reserved_area, cabinet_ra_size).fail())
+			if(out.write((char*)reserved_area, cabinet_ra_size).fail())
 			{
 				return WRITE_ERROR;
 			}
@@ -210,4 +213,4 @@
 
 ////////////////////////////////////////****************************************
 
-#endif
\ No newline at end of file
+#endif
