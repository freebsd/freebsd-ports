--- platform/x11/os_x11.cpp.orig	2018-01-10 10:08:3 UTC
+++ platform/x11/os_x11.cpp
@@ -1243,7 +1243,7 @@ static Property read_property(Display *p
 
 	} while (bytes_after != 0);
 
-	Property p = { ret, actual_format, nitems, actual_type };
+	Property p = { ret, actual_format, (int)nitems, actual_type };
 
 	return p;
 }
