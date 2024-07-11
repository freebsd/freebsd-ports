--- src/synfig/main.cpp.orig	2024-05-21 08:01:41 UTC
+++ src/synfig/main.cpp
@@ -224,7 +224,7 @@
 
 	unsigned int i;
 #ifdef _DEBUG
-#ifndef __APPLE__
+#ifndef __clang__
 	std::set_terminate(__gnu_cxx::__verbose_terminate_handler);
 #endif
 #endif
@@ -546,7 +546,11 @@
 	/* Read from /proc/self/exe (symlink) */
 	//char* path2 = (char*)malloc(buf_size);
 	char* path2 = new char[buf_size];
-	strncpy(path2, "/proc/self/exe", buf_size - 1);
+#if defined(__FreeBSD__) || defined (__DragonFly__)
+		strncpy(path2, "/proc/curproc/file", buf_size - 1);
+#else
+		strncpy(path2, "/proc/self/exe", buf_size - 1);
+#endif
 
 	while (1) {
 		int i;
@@ -584,6 +588,7 @@
 	//free(path2);
 	delete[] path2;
 
+#if ! (defined(__FreeBSD__) || defined(__DragonFly__))
 	if (result == "")
 	{
 		/* readlink() or stat() failed; this can happen when the program is
@@ -625,7 +630,8 @@
 		free(line);
 		fclose(f);
 	}
-	
+#endif
+
 	free(path);
 
 #endif
