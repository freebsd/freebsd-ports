
$FreeBSD$

--- src/plugin_common/charset.c.orig
+++ src/plugin_common/charset.c
@@ -83,6 +83,8 @@
 	/* Due to a GLIBC bug, round outbuf_size up to a multiple of 4 */
 	/* + 1 for nul in case len == 1 */
 	outsize = ((length + 3) & ~3) + 1;
+	if(outsize < length) /* overflow check */
+		return NULL;
 	out = (char*)malloc(outsize);
 	outleft = outsize - 1;
 	outptr = out;
@@ -95,6 +97,10 @@
 		{
 			case E2BIG:
 				used = outptr - out;
+				if((outsize - 1) * 2 + 1 <= outsize) { /* overflow check */
+					free(out);
+					return NULL;
+				}
 				outsize = (outsize - 1) * 2 + 1;
 				out = realloc(out, outsize);
 				outptr = out + used;
