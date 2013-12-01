--- sys/melder.h.orig	2013-10-22 08:29:40.000000000 -0500
+++ sys/melder.h	2013-11-23 12:43:08.000000000 -0600
@@ -1073,6 +1073,11 @@
 			Melder_fclose (file, tmp);
 		}
 	}
+	// operator () is not working in Sound_files.cpp:226 for some reason
+	FILE * get_ptr(void)
+	{
+		return ptr;
+	}
 };
 
 class autoMelderFile {
