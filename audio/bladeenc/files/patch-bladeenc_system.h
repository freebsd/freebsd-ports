--- bladeenc/system.h.orig	Tue May  8 14:11:53 2001
+++ bladeenc/system.h	Thu Sep 19 10:25:02 2002
@@ -321,10 +321,4 @@
 
 typedef		unsigned	char 	uchar;
 
-#if (defined(UNIX_SYSTEM) && !defined(SYS_TYPES_H) && !defined(_SYS_TYPES_H)) || (!defined UNIX_SYSTEM  && !defined(__GNUC__))
-		typedef		unsigned short	ushort;
-		typedef		unsigned int	uint;
-#endif
-
-
 #endif		/* __SYSTEM__ */
