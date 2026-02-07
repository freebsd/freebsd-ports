--- cfdblock.cpp.orig	1999-10-24 06:13:29 UTC
+++ cfdblock.cpp
@@ -17,7 +17,7 @@
 #ifndef __CFDBLOCK_CPP__
 #define __CFDBLOCK_CPP__
 
-#include <fstream.h>
+#include <fstream>
 #include "cftypes.h"
 #include "cfdblock.h"
 #include "cfheader.h"
@@ -124,7 +124,7 @@ int cabinet_datablock::read(istream& in,
 		ra_size = cab_header.get_datablock_ra_size();
 		reserved_area = new byte[ra_size];
 
-		if(in.read(reserved_area, ra_size).bad())
+		if(in.read((char*)reserved_area, ra_size).bad())
 		{
 			return (in.fail()) ? READ_ERROR : UNEXPECTED_EOF;
 		}
@@ -154,7 +154,7 @@ int cabinet_datablock::write(ostream& ou
 
 	if(ra_size)		 				// If reserve area, write it
 	{
-		if(out.write(reserved_area, ra_size).fail()) return WRITE_ERROR;
+		if(out.write((char*)reserved_area, ra_size).fail()) return WRITE_ERROR;
 	}
 					 				// write data to stream
 	// if(out.write(compressed_data, compressed_size).bad()) return WRITE_ERROR;
