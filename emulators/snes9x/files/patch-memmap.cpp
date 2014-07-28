--- memmap.cpp	2007-10-03 11:11:07.000000000 -0500
+++ memmap.cpp	2007-10-03 11:11:34.000000000 -0500
@@ -169,7 +169,7 @@
 #include <ctype.h>
 #include <assert.h>
 
-#ifdef __linux
+#if defined(__linux) || defined(__FreeBSD__)
 #include <unistd.h>
 #endif
 
@@ -1473,7 +1473,7 @@
 		{
 			fwrite((char *) Multi.sramB, size, 1, file);
 			fclose(file);
-#ifdef __linux
+#if defined(__linux) || defined(__FreeBSD__)
 			chown(name, getuid(), getgid());
 #endif
 		}
@@ -1502,7 +1502,7 @@
 		{
 			fwrite((char *) SRAM, size, 1, file);
 			fclose(file);
-#ifdef __linux
+#if defined(__linux) || defined(__FreeBSD__)
 			chown(sramName, getuid(), getgid());
 #endif
 			if (Settings.SPC7110RTC)
