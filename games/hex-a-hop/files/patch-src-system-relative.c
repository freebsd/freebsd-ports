--- src/system-relative.c~
+++ src/system-relative.c
@@ -163,6 +163,8 @@ lisys_relative_exename ()
 	}
 
 	return strdup (name);
+#elif __FreeBSD__
+	return getprogname();
 #else
 #warning "Not supported."
 	return NULL;
@@ -177,7 +179,7 @@ lisys_relative_exename ()
 char*
 lisys_relative_exedir ()
 {
-#if defined WIN32 || defined linux
+#if defined WIN32 || defined linux || defined __FreeBSD__
 	char* tmp;
 	char* ptr;
 
