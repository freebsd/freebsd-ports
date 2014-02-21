--- cffolder.cpp.orig	1999-10-24 02:13:29.000000000 -0400
+++ cffolder.cpp	2014-02-21 15:53:49.255245183 -0500
@@ -17,7 +17,7 @@
 #ifndef __CFFOLDER_CPP__
 #define __CFFOLDER_CPP__
 
-#include <fstream.h>
+#include <fstream>
 #include "cftypes.h"
 #include "cfheader.h"
 #include "cffolder.h"
@@ -70,7 +70,7 @@
 			ra_size = cab_header.get_folder_ra_size();
 			reserved_area = new byte[ra_size];
 
-			if(in.read(reserved_area, ra_size).bad())
+			if(in.read((char*)reserved_area, ra_size).bad())
 			{
 				return (in.fail()) ? READ_ERROR : UNEXPECTED_EOF;
 			}
@@ -90,7 +90,7 @@
 
 	if(ra_size)					// If reserved area present
 	{
-		if(out.write(reserved_area, ra_size).fail()) { return WRITE_ERROR; }
+		if(out.write((char*)reserved_area, ra_size).fail()) { return WRITE_ERROR; }
 	}
 
 	return OK;
