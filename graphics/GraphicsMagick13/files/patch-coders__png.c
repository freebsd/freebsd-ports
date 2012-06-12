--- ./coders/png.c.orig	2012-04-28 15:45:16.000000000 -0400
+++ ./coders/png.c	2012-06-12 10:41:35.000000000 -0400
@@ -1601,6 +1601,12 @@
       115,  67,  65,  76, '\0',   /* sCAL */
       115,  80,  76,  84, '\0',   /* sPLT */
       116,  73,  77,  69, '\0',   /* tIME */
+#ifdef PNG_APNG_SUPPORTED /* libpng was built with APNG patch; */
+                          /* ignore the APNG chunks */
+       97,  99,  84,  76, '\0',   /* acTL */
+      102,  99,  84,  76, '\0',   /* fcTL */
+      102, 100,  65,  84, '\0',   /* fdAT */
+#endif
     };
 #endif
 
@@ -1707,6 +1713,11 @@
                               (int)sizeof(unused_chunks)/5);
 #endif
 
+#ifdef PNG_READ_CHECK_FOR_INVALID_INDEX_SUPPORTED
+    /* Disable new libpng-1.5.10 feature */
+    png_set_check_for_invalid_index (ping, 0);
+#endif
+
 #if defined(PNG_USE_PNGGCCRD) && defined(PNG_ASSEMBLER_CODE_SUPPORTED)  \
   && (PNG_LIBPNG_VER >= 10200)
   /* Disable thread-unsafe features of pnggccrd */
@@ -6356,6 +6367,12 @@
   /*
     Prepare PNG for writing.
   */
+
+#ifdef PNG_WRITE_CHECK_FOR_INVALID_INDEX_SUPPORTED
+    /* Disable new libpng-1.5.10 feature */
+    png_set_check_for_invalid_index (ping, 0);
+#endif
+
 #if defined(PNG_MNG_FEATURES_SUPPORTED)
   if (mng_info->write_mng)
     (void) png_permit_mng_features(ping,PNG_ALL_MNG_FEATURES);
