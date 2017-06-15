--- src/codegen/writexml.xsl.orig	2013-10-30 17:33:35 UTC
+++ src/codegen/writexml.xsl
@@ -15,7 +15,7 @@ xmlChar *toXmlChar(const Context *ctx, c
 	if (ctx-&gt;convertEncoding) {
 		size_t len = strlen(from_str);
 		iconv_t cd = iconv_open("UTF-8", ctx-&gt;swf_encoding);
-		if (cd &lt; 0) {
+		if (cd == (iconv_t)-1) {
 			fprintf(stderr, "iconv_open failed.\n");
 			return xmlCharStrdup("");
 		}
