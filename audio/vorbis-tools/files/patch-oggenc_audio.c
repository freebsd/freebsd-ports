--- oggenc/audio.c.orig	2010-03-24 08:27:14 UTC
+++ oggenc/audio.c
@@ -245,8 +245,8 @@ static int aiff_permute_matrix[6][6] = 
 int aiff_open(FILE *in, oe_enc_opt *opt, unsigned char *buf, int buflen)
 {
     int aifc; /* AIFC or AIFF? */
-    unsigned int len;
-    unsigned char *buffer;
+    unsigned int len, readlen;
+    unsigned char buffer[22];
     unsigned char buf2[8];
     aiff_fmt format;
     aifffile *aiff = malloc(sizeof(aifffile));
@@ -269,9 +269,9 @@ int aiff_open(FILE *in, oe_enc_opt *opt,
         return 0; /* Weird common chunk */
     }
 
-    buffer = alloca(len);
-
-    if(fread(buffer,1,len,in) < len)
+    readlen = len < sizeof(buffer) ? len : sizeof(buffer);
+    if(fread(buffer,1,readlen,in) < readlen ||
+       (len > readlen && !seek_forward(in, len-readlen)))
     {
         fprintf(stderr, _("Warning: Unexpected EOF in reading AIFF header\n"));
         return 0;
