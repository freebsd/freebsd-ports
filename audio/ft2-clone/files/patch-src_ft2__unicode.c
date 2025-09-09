--- src/ft2_unicode.c.orig	2025-09-09 06:08:58 UTC
+++ src/ft2_unicode.c
@@ -4,20 +4,21 @@
 #endif
 
 // for detecting if musl or glibc is used
-#if !defined _WIN32 && !defined __APPLE__
-	#ifndef _GNU_SOURCE
-		#define _GNU_SOURCE
-	  #include <features.h>
-	  #ifndef __USE_GNU
-	      #define __MUSL__
-	  #endif
-	  #undef _GNU_SOURCE /* don't contaminate other includes unnecessarily */
-	#else
-	  #include <features.h>
-	  #ifndef __USE_GNU
-	      #define __MUSL__
-	  #endif
-	#endif
+#if defined(__linux__)
+  /* Only Linux has glibc's <features.h>. On BSDs (including FreeBSD) and others,
+     skip this block to avoid a missing-header error. */
+  #ifdef __has_include
+    #if __has_include(<features.h>)
+      #include <features.h>
+    #endif
+  #else
+    /* If the compiler doesn't support __has_include, assume features.h exists on glibc. */
+    #include <features.h>
+  #endif
+  /* If <features.h> didn't define glibc's GNU extensions, assume musl. */
+  #ifndef __USE_GNU
+    #define __MUSL__
+  #endif
 #endif
 
 #include <stdlib.h>
