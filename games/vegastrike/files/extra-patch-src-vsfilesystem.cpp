--- src/vsfilesystem.cpp.orig	2008-04-24 16:12:39.000000000 +0400
+++ src/vsfilesystem.cpp	2010-04-04 05:19:55.000000000 +0400
@@ -77,7 +77,7 @@
 
 string selectcurrentdir;
 
-#if defined (__FreeBSD__) || defined(__APPLE__)
+#if defined(__APPLE__)
 int	selectdirs( struct dirent * entry)
 #else
 int	selectdirs( const struct dirent * entry)
@@ -106,7 +106,7 @@
 	return 0;
 }
 
-#if defined (__FreeBSD__) || defined(__APPLE__)
+#if defined(__APPLE__)
 int	selectpk3s( struct dirent * entry)
 #else
 int	selectpk3s( const struct dirent * entry)
@@ -118,7 +118,7 @@
 	return 0;
 }
 
-#if defined (__FreeBSD__) || defined(__APPLE__)
+#if defined(__APPLE__)
 int	selectbigpk3s( struct dirent * entry)
 #else
 int	selectbigpk3s( const struct dirent * entry)
