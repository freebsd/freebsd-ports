--- lib/database/src/so/SoInput.c++.orig	2000-10-25 23:47:47 UTC
+++ lib/database/src/so/SoInput.c++
@@ -2810,7 +2810,7 @@ SoInput::addReference(const SbName &name
 
     if (addToGlobalDict) {
 	// Look for the first '+':
-	char *firstPlus = strchr(n, '+');
+	const char *firstPlus = strchr(n, '+');
 
 	if (firstPlus == NULL) {
 	    base->setName(name);
