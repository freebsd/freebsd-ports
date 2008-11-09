--- src/macros.h.orig	2008-10-28 21:23:51.000000000 +0300
+++ src/macros.h	2008-11-05 03:52:54.000000000 +0300
@@ -87,12 +87,10 @@
 			#define strcasecmp _stricmp
 		#endif
 
-	/* C99 standard has this
+	#endif // #if defined(__WIN32__)
 	// log2 workaround
 		#if !defined(log2)
 			#define log2(value) log((double)value)/log(2.0)
 		#endif
-	*/
-	#endif // #if defined(__WIN32__)
 #endif
 
