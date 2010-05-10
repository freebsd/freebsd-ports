--- src/oss.c.orig	2010-02-19 18:39:40.000000000 -0500
+++ src/oss.c	2010-03-14 15:04:16.000000000 -0400
@@ -262,7 +262,7 @@ static int open_oss(ca_context *c, struc
                 val = AFMT_S16_NE;
                 break;
         case CA_SAMPLE_S16RE:
-#if __BYTE_ORDER == __LITTLE_ENDIAN
+#if _BYTE_ORDER == _LITTLE_ENDIAN
                 val = AFMT_S16_BE;
 #else
                 val = AFMT_S16_LE;
