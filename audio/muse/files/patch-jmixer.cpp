--- jmixer.cpp.orig	Tue Jul 23 04:48:56 2002
+++ jmixer.cpp	Sat Dec 28 09:41:10 2002
@@ -808,7 +808,7 @@
 }
 
 /* this is the function selecting files for the scandir */
-int selector(const struct dirent *dir) {
+int selector(struct dirent *dir) {
   if( strncasecmp(dir->d_name+strlen(dir->d_name)-4,".mp3",4)==0
 #ifdef HAVE_VORBIS
       || strncasecmp(dir->d_name+strlen(dir->d_name)-4,".ogg",4)==0
