--- src/oss.c.orig	2009-08-26 21:58:16.000000000 -0400
+++ src/oss.c	2009-11-25 20:47:07.000000000 -0500
@@ -260,7 +260,7 @@ static int open_oss(ca_context *c, struc
             val = AFMT_S16_NE;
             break;
         case CA_SAMPLE_S16RE:
-#if __BYTE_ORDER == __LITTLE_ENDIAN
+#if _BYTE_ORDER == _LITTLE_ENDIAN
             val = AFMT_S16_BE;
 #else
             val = AFMT_S16_LE;
