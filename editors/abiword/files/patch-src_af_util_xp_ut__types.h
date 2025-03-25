--- src/af/util/xp/ut_types.h.orig	2021-07-03 15:46:07 UTC
+++ src/af/util/xp/ut_types.h
@@ -40,7 +40,7 @@ typedef guint8		UT_Byte;
 
 typedef guint8		UT_Byte;
 
-typedef gunichar        UT_UCS4Char;
+typedef char32_t        UT_UCS4Char;
 typedef guint16      UT_UCS2Char;
 typedef gint32          UT_GrowBufElement;
 
