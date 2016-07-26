--- src/oss.c.orig	2011-02-23 01:51:00 UTC
+++ src/oss.c
@@ -259,7 +259,7 @@ static int open_oss(ca_context *c, struc
                 val = AFMT_S16_NE;
                 break;
         case CA_SAMPLE_S16RE:
-#if __BYTE_ORDER == __LITTLE_ENDIAN
+#if _BYTE_ORDER == _LITTLE_ENDIAN
                 val = AFMT_S16_BE;
 #else
                 val = AFMT_S16_LE;
