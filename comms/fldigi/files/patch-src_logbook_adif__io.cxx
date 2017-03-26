--- src/logbook/adif_io.cxx.orig	2017-01-29 13:26:25 UTC
+++ src/logbook/adif_io.cxx
@@ -316,7 +316,7 @@ void cAdifIO::do_readfile(const char *fn
 			} else {
 				ptr2 = ptr + 1;
 			}
-			if ((ptr2) > 0 && (unsigned)(ptr2 - ptr) <= p)
+			if ((unsigned long)(ptr2) > 0 && (unsigned long)(ptr2 - ptr) <= p)
 				ptr = strchr(ptr2,'<');
 			else
 				break; // corrupt record
