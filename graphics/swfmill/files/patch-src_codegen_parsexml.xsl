--- src/codegen/parsexml.xsl.orig	2013-10-30 17:33:35 UTC
+++ src/codegen/parsexml.xsl
@@ -19,7 +19,7 @@ char *fromXmlChar(const Context *ctx, co
 	if (ctx-&gt;convertEncoding) {
 		size_t len = strlen((const char *)from_str);
 		iconv_t cd = iconv_open(ctx-&gt;swf_encoding, "UTF-8");
-		if (cd &lt; 0) {
+		if (cd == (iconv_t)-1) {
 			fprintf(stderr, "iconv_open failed.\n");
 			char *buf = new char[1];
 			buf[0] = '\0';
