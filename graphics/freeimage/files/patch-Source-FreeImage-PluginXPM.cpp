--- Source/FreeImage/PluginXPM.cpp.orig	2013-11-29 19:29:14 UTC
+++ Source/FreeImage/PluginXPM.cpp
@@ -181,6 +181,11 @@ Load(FreeImageIO *io, fi_handle handle, 
 		}
 		free(str);
 
+		// check info string
+		if((width <= 0) || (height <= 0) || (colors <= 0) || (cpp <= 0)) {
+			throw "Improperly formed info string";
+		}
+
         if (colors > 256) {
 			dib = FreeImage_AllocateHeader(header_only, width, height, 24, FI_RGBA_RED_MASK, FI_RGBA_GREEN_MASK, FI_RGBA_BLUE_MASK);
 		} else {
@@ -193,7 +198,7 @@ Load(FreeImageIO *io, fi_handle handle, 
 			FILE_RGBA rgba;
 
 			str = ReadString(io, handle);
-			if(!str)
+			if(!str || (strlen(str) < (size_t)cpp))
 				throw "Error reading color strings";
 
 			std::string chrs(str,cpp); //create a string for the color chars using the first cpp chars
