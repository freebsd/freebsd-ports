--- cppu/source/uno/data.cxx.kan	Wed Jul 24 23:39:23 2002
+++ cppu/source/uno/data.cxx	Wed Jul 24 23:38:49 2002
@@ -295,7 +295,7 @@
 #	pragma pack(8)
 #endif
 
-#if defined(__GNUC__) && defined(LINUX) && defined(INTEL)
+#if defined(__GNUC__) && (defined(LINUX) || defined(FREEBSD)) && defined(INTEL)
 #define MAX_ALIGNMENT_4
 #endif
 
@@ -307,7 +307,7 @@
     if (OFFSET_OF(s, m) != n) { fprintf( stderr, "### OFFSET_OF(" #s ", "  #m ") = %d instead of expected %d!!!\n", OFFSET_OF(s, m), n ); abort(); }
 
 #ifdef DEBUG
-#if defined(__GNUC__) && defined(LINUX) && (defined(INTEL) || defined(POWERPC))
+#if defined(__GNUC__) && (defined(LINUX) || defined(FREEBSD)) && (defined(INTEL) || defined(POWERPC))
 #define BINTEST_VERIFYSIZE( s, n ) \
     fprintf( stderr, "> sizeof(" #s ") = %d; __alignof__ (" #s ") = %d\n", sizeof(s), __alignof__ (s) ); \
     if (sizeof(s) != n) { fprintf( stderr, "### sizeof(" #s ") = %d instead of expected %d!!!\n", sizeof(s), n ); abort(); }
