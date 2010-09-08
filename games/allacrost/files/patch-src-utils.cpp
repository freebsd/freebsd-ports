--- src/utils.cpp.orig	2010-09-02 20:33:23.000000000 +0400
+++ src/utils.cpp	2010-09-02 20:34:01.000000000 +0400
@@ -337,7 +337,7 @@
 	}
 
 	const char *source_char = reinterpret_cast<const char *>(source);
-	#if (defined(_LIBICONV_VERSION) && _LIBICONV_VERSION == 0x0109)
+	#if 1
 	// We are using an iconv API that uses const char*
 	const char *sourceChar = source_char;
 	#else
@@ -369,7 +369,7 @@
 		return false;
 	}
 
-	#if (defined(_LIBICONV_VERSION) && _LIBICONV_VERSION == 0x0109)
+	#if 1
 		// We are using an iconv API that uses const char*
 		const char *sourceChar = source;
 	#else
