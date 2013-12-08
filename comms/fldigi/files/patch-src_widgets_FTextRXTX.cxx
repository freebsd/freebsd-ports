--- src/widgets/FTextRXTX.cxx.orig	2013-11-18 20:37:04.508734484 -0500
+++ src/widgets/FTextRXTX.cxx	2013-11-18 20:37:26.598733044 -0500
@@ -263,7 +263,7 @@
 	if (c == '\r')
 		return;
 
-	char s[] = { '\0', '\0', FTEXT_DEF + attr, '\0' };
+	char s[] = { '\0', '\0', static_cast<char>(FTEXT_DEF + attr), '\0' };
 	const char *cp = &s[0];
 
 	// The user may have moved the cursor by selecting text or
