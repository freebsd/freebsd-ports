--- cffolder.cpp.orig	1999-10-24 06:13:29 UTC
+++ cffolder.cpp
@@ -17,7 +17,7 @@
 #ifndef __CFFOLDER_CPP__
 #define __CFFOLDER_CPP__
 
-#include <fstream.h>
+#include <fstream>
 #include "cftypes.h"
 #include "cfheader.h"
 #include "cffolder.h"
@@ -70,7 +70,7 @@ Error cabinet_folder_header::read(istrea
 			ra_size = cab_header.get_folder_ra_size();
 			reserved_area = new byte[ra_size];
 
-			if(in.read(reserved_area, ra_size).bad())
+			if(in.read((char*)reserved_area, ra_size).bad())
 			{
 				return (in.fail()) ? READ_ERROR : UNEXPECTED_EOF;
 			}
@@ -90,7 +90,7 @@ Error cabinet_folder_header::write(ostre
 
 	if(ra_size)					// If reserved area present
 	{
-		if(out.write(reserved_area, ra_size).fail()) { return WRITE_ERROR; }
+		if(out.write((char*)reserved_area, ra_size).fail()) { return WRITE_ERROR; }
 	}
 
 	return OK;
