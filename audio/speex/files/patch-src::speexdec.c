--- src/speexdec.c.orig	Sun Jun  1 14:58:51 2003
+++ src/speexdec.c	Wed Jun 11 02:07:49 2003
@@ -72,6 +72,14 @@
                            ((buf[base+1]<<8)&0xff00)| \
   	           	    (buf[base]&0xff))
 
+#if !defined(AFMT_S16_NE)
+#if defined(BYTE_ORDER) && (BYTE_ORDER == BIG_ENDIAN)
+#define AFMT_S16_NE AFMT_S16_BE
+#else
+#define AFMT_S16_NE AFMT_S16_LE
+#endif
+#endif
+
 static void print_comments(char *comments, int length)
 {
    char *c=comments;
