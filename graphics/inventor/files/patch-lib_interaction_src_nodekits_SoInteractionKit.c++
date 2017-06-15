--- lib/interaction/src/nodekits/SoInteractionKit.c++.orig	2000-08-15 12:56:25 UTC
+++ lib/interaction/src/nodekits/SoInteractionKit.c++
@@ -854,8 +854,8 @@ SoInteractionKit::setAnySurrogatePath( c
 	    // (as in "childList[0].appearance")
 	    // If so, get the string up to whichever came first.
 	    // This will be the 'intermediary' we look for.
-	    char *dotPtr   = strchr( partName.getString(), '.' );
-	    char *brackPtr = strchr( partName.getString(), '[' );
+	    const char *dotPtr   = strchr( partName.getString(), '.' );
+	    const char *brackPtr = strchr( partName.getString(), '[' );
 
 	    if ( dotPtr != NULL || brackPtr != NULL ) {
 		char *nameCopy = strdup( partName.getString() );
