--- cffolder.cpp.orig	Tue Aug 19 18:23:48 2003
+++ cffolder.cpp	Tue Aug 19 18:24:14 2003
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
