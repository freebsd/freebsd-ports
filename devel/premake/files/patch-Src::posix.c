--- Src/posix.c.orig	Tue Feb 24 21:49:57 2004
+++ Src/posix.c	Thu Mar 25 21:10:21 2004
@@ -20,6 +20,9 @@
 
 #if defined(__linux__)
 const char* osIdent = "linux";
+#endif
+#if defined(__FreeBSD__)
+const char* osIdent = "linux";
 #else
 #error Unknown OS type.
 #endif
@@ -87,31 +90,7 @@
 		return 1;
 	}
 
-	FILE* file = fopen("/etc/ld.so.conf", "rt");
-	if (file == NULL) return 0;
-
-	while (!feof(file))
-	{
-		// Read a line and trim off any trailing whitespace
-		char linebuffer[2048];
-		char* ptr;
-
-		fgets(buffer, 2048, file);
-		ptr = &buffer[strlen(buffer) - 1];
-		while (isspace(*ptr))
-			*(ptr--) = '\0';
-
-		if (findLib(lib, buffer))
-		{
-			fclose(file);
-			return 1;
-		}
-	}
-
-	fclose(file);
-	return 0;
 }
-
 //-----------------------------------------------------------------------------
 
 int plat_generateUUID(char* uuid)
