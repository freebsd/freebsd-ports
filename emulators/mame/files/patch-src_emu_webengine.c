--- src/emu/webengine.c.orig	2015-09-30 06:29:01 UTC
+++ src/emu/webengine.c
@@ -330,7 +330,7 @@ int web_engine::begin_request_handler(st
 		// That upload_data contains more than we need. It also has the headers.
 		// We'll need to strip it down to just what we want.
 
-		if ((&data_length > 0) && (sizeof(file_name) > 0))
+		if ((data_length > 0) && (sizeof(file_name) > 0))
 		{
 			// MSVC doesn't yet support variable-length arrays, so chop the string the old-fashioned way
 			upload_data[data_length] = '\0';
