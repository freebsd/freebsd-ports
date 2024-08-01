--- jdk/src/share/native/com/sun/java/util/jar/pack/constants.h.orig	2024-07-27 18:28:39 UTC
+++ jdk/src/share/native/com/sun/java/util/jar/pack/constants.h
@@ -223,7 +223,7 @@ enum {
     AO_HAVE_FIELD_FLAGS_HI    = 1<<10,
     AO_HAVE_METHOD_FLAGS_HI   = 1<<11,
     AO_HAVE_CODE_FLAGS_HI     = 1<<12,
-    AO_UNUSED_MBZ             = (-1)<<13, // options bits reserved for future use.
+    AO_UNUSED_MBZ             = (~0u)<<13, // options bits reserved for future use.
 
 #define ARCHIVE_BIT_DO(F) \
          F(AO_HAVE_SPECIAL_FORMATS) \
