--- Modules/cjkcodecs/_codecs_iso2022.c.orig	Sun Jul 18 13:34:33 2004
+++ Modules/cjkcodecs/_codecs_iso2022.c	Sat Aug 21 09:07:17 2004
@@ -2,7 +2,7 @@
  * _codecs_iso2022.c: Codecs collection for ISO-2022 encodings.
  *
  * Written by Hye-Shik Chang <perky@FreeBSD.org>
- * $CJKCodecs: _codecs_iso2022.c,v 1.18 2004/07/07 18:30:17 perky Exp $
+ * $CJKCodecs: _codecs_iso2022.c,v 1.22 2004/08/19 17:08:13 perky Exp $
  */
 
 #define USING_IMPORTED_MAPS
@@ -117,7 +117,7 @@
 
 struct iso2022_config {
 	int flags;
-	const struct iso2022_designation designations[]; /* non-ascii desigs */
+	const struct iso2022_designation *designations; /* non-ascii desigs */
 };
 
 /*-*- iso-2022 codec implementation -*-*/
@@ -197,7 +197,9 @@
 					length = 2;
 #if Py_UNICODE_SIZE == 2
 				if (length == 2) {
-					ucs4_t u4in[2] = {IN1, IN2};
+					ucs4_t u4in[2];
+					u4in[0] = (ucs4_t)IN1;
+					u4in[1] = (ucs4_t)IN2;
 					encoded = dsg->encoder(u4in, &length);
 				} else
 					encoded = dsg->encoder(&c, &length);
@@ -420,7 +422,7 @@
 DECODER(iso2022)
 {
 	const struct iso2022_designation *dsgcache = NULL;
-	
+
 	while (inleft > 0) {
 		unsigned char c = IN1;
 		int err;
@@ -1047,50 +1049,52 @@
 #define REGISTRY_ISO8859_7	{ CHARSET_ISO8859_7, 2, 1,		\
 				  NULL, dummy_decoder, dummy_encoder }
 #define REGISTRY_SENTINEL	{ 0, }
+#define CONFIGDEF(var, attrs)						\
+	static const struct iso2022_config iso2022_##var##_config = {	\
+		attrs, iso2022_##var##_designations			\
+	};
 
-static const struct iso2022_config iso2022_kr_config = {
-	0,
-	{ REGISTRY_KSX1001, REGISTRY_SENTINEL },
+static const struct iso2022_designation iso2022_kr_designations[] = {
+	REGISTRY_KSX1001, REGISTRY_SENTINEL
 };
+CONFIGDEF(kr, 0)
 
-static const struct iso2022_config iso2022_jp_config = {
-	NO_SHIFT | USE_JISX0208_EXT,
-	{ REGISTRY_JISX0208, REGISTRY_JISX0201_R, REGISTRY_JISX0208_O,
-	  REGISTRY_SENTINEL },
+static const struct iso2022_designation iso2022_jp_designations[] = {
+	REGISTRY_JISX0208, REGISTRY_JISX0201_R, REGISTRY_JISX0208_O,
+	REGISTRY_SENTINEL
 };
+CONFIGDEF(jp, NO_SHIFT | USE_JISX0208_EXT)
 
-static const struct iso2022_config iso2022_jp_1_config = {
-	NO_SHIFT | USE_JISX0208_EXT,
-	{ REGISTRY_JISX0208, REGISTRY_JISX0212, REGISTRY_JISX0201_R,
-	  REGISTRY_JISX0208_O, REGISTRY_SENTINEL },
+static const struct iso2022_designation iso2022_jp_1_designations[] = {
+	REGISTRY_JISX0208, REGISTRY_JISX0212, REGISTRY_JISX0201_R,
+	REGISTRY_JISX0208_O, REGISTRY_SENTINEL
 };
+CONFIGDEF(jp_1, NO_SHIFT | USE_JISX0208_EXT)
 
-static const struct iso2022_config iso2022_jp_2_config = {
-	NO_SHIFT | USE_G2 | USE_JISX0208_EXT,
-	{ REGISTRY_JISX0208, REGISTRY_JISX0212, REGISTRY_KSX1001,
-	  REGISTRY_GB2312, REGISTRY_JISX0201_R, REGISTRY_JISX0208_O,
-	  REGISTRY_ISO8859_1, REGISTRY_ISO8859_7, REGISTRY_SENTINEL },
+static const struct iso2022_designation iso2022_jp_2_designations[] = {
+	REGISTRY_JISX0208, REGISTRY_JISX0212, REGISTRY_KSX1001,
+	REGISTRY_GB2312, REGISTRY_JISX0201_R, REGISTRY_JISX0208_O,
+	REGISTRY_ISO8859_1, REGISTRY_ISO8859_7, REGISTRY_SENTINEL
 };
+CONFIGDEF(jp_2, NO_SHIFT | USE_G2 | USE_JISX0208_EXT)
 
-static const struct iso2022_config iso2022_jp_2004_config = {
-	NO_SHIFT | USE_G2 | USE_JISX0208_EXT,
-	{ REGISTRY_JISX0213_2004_1_PAIRONLY, REGISTRY_JISX0208,
-	  REGISTRY_JISX0213_2004_1, REGISTRY_JISX0213_2004_2,
-	  REGISTRY_SENTINEL },
+static const struct iso2022_designation iso2022_jp_2004_designations[] = {
+	REGISTRY_JISX0213_2004_1_PAIRONLY, REGISTRY_JISX0208,
+	REGISTRY_JISX0213_2004_1, REGISTRY_JISX0213_2004_2, REGISTRY_SENTINEL
 };
+CONFIGDEF(jp_2004, NO_SHIFT | USE_JISX0208_EXT)
 
-static const struct iso2022_config iso2022_jp_3_config = {
-	NO_SHIFT | USE_JISX0208_EXT,
-	{ REGISTRY_JISX0213_2000_1_PAIRONLY, REGISTRY_JISX0208,
-	  REGISTRY_JISX0213_2000_1, REGISTRY_JISX0213_2000_2,
-	  REGISTRY_SENTINEL },
+static const struct iso2022_designation iso2022_jp_3_designations[] = {
+	REGISTRY_JISX0213_2000_1_PAIRONLY, REGISTRY_JISX0208,
+	REGISTRY_JISX0213_2000_1, REGISTRY_JISX0213_2000_2, REGISTRY_SENTINEL
 };
+CONFIGDEF(jp_3, NO_SHIFT | USE_JISX0208_EXT)
 
-static const struct iso2022_config iso2022_jp_ext_config = {
-	NO_SHIFT | USE_JISX0208_EXT,
-	{ REGISTRY_JISX0208, REGISTRY_JISX0212, REGISTRY_JISX0201_R,
-	  REGISTRY_JISX0201_K, REGISTRY_JISX0208_O, REGISTRY_SENTINEL },
+static const struct iso2022_designation iso2022_jp_ext_designations[] = {
+	REGISTRY_JISX0208, REGISTRY_JISX0212, REGISTRY_JISX0201_R,
+	REGISTRY_JISX0201_K, REGISTRY_JISX0208_O, REGISTRY_SENTINEL
 };
+CONFIGDEF(jp_ext, NO_SHIFT | USE_JISX0208_EXT)
 
 
 BEGIN_MAPPINGS_LIST
