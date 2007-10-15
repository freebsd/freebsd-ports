--- cripple.h.orig	2005-05-01 22:56:23.000000000 +0200
+++ cripple.h	2007-10-15 14:02:04.000000000 +0200
@@ -68,6 +68,8 @@
 
 #ifdef __sun
 #  define DEF_CD_DEV	"/vol/dev/aliases/cdrom0"
+#elif defined(__FreeBSD__) 
+#  define DEF_CD_DEV	"/dev/acd0"
 #elif defined(__win32__)
 /*
  * on win32 a null path will cause read_cdtoc_from_drive() to search for one.
