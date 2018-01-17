--- src/synfig/main.cpp.orig	2017-04-02 22:19:06 UTC
+++ src/synfig/main.cpp
@@ -198,7 +198,7 @@ synfig::Main::Main(const synfig::String& basepath,Prog
 
 	unsigned int i;
 #ifdef _DEBUG
-#ifndef __APPLE__
+#ifndef __clang__
 	std::set_terminate(__gnu_cxx::__verbose_terminate_handler);
 #endif
 #endif
@@ -490,7 +490,11 @@ synfig::get_binary_path(const String &fallback_path)
 
 	/* Read from /proc/self/exe (symlink) */
 	char* path2 = (char*)malloc(buf_size);
+#if defined(__FreeBSD__) || defined (__DragonFly__)
+        strncpy(path2, "/proc/curproc/file", buf_size - 1);
+#else
 	strncpy(path2, "/proc/self/exe", buf_size - 1);
+#endif
 
 	while (1) {
 		int i;
@@ -524,9 +528,10 @@ synfig::get_binary_path(const String &fallback_path)
 		/* path is a symlink. Continue loop and resolve this. */
 		strncpy(path, path2, buf_size - 1);
 	}
-	
+
 	free(path2);
 
+#if ! (defined(__FreeBSD__) || defined(__DragonFly__))
 	if (result == "")
 	{
 		/* readlink() or stat() failed; this can happen when the program is
@@ -568,6 +573,7 @@ synfig::get_binary_path(const String &fallback_path)
 		free(line);
 		fclose(f);
 	}
+#endif
 	
 	free(path);
 
