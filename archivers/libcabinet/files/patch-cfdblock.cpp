--- cfdblock.cpp.orig	Tue Aug 19 18:22:14 2003
+++ cfdblock.cpp	Tue Aug 19 18:23:24 2003
@@ -124,7 +124,7 @@
 		ra_size = cab_header.get_datablock_ra_size();
 		reserved_area = new byte[ra_size];
 
-		if(in.read(reserved_area, ra_size).bad())
+		if(in.read((char*)reserved_area, ra_size).bad())
 		{
 			return (in.fail()) ? READ_ERROR : UNEXPECTED_EOF;
 		}
@@ -154,7 +154,7 @@
 
 	if(ra_size)		 				// If reserve area, write it
 	{
-		if(out.write(reserved_area, ra_size).fail()) return WRITE_ERROR;
+		if(out.write((char*)reserved_area, ra_size).fail()) return WRITE_ERROR;
 	}
 					 				// write data to stream
 	// if(out.write(compressed_data, compressed_size).bad()) return WRITE_ERROR;
