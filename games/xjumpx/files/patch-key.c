--- key.c.orig	2011-09-05 15:10:48.000000000 +0800
+++ key.c	2011-09-05 15:11:05.000000000 +0800
@@ -59,12 +59,12 @@ static void add( Display *d, int key, ch
 
 	sym = XStringToKeysym(keysym_name);
 	if( sym == NoSymbol ){
-		fprintf(stderr,"KeySym '%s' does not exist.\n");
+		fprintf(stderr,"KeySym '%%s' does not exist.\n");
 		return;
 	}
 	code = XKeysymToKeycode(d,sym);
 	if( code == 0 ){
-		fprintf(stderr,"KeySym '%s' is not defined for any KeyCode.\n");
+		fprintf(stderr,"KeySym '%%s' is not defined for any KeyCode.\n");
 		return;
 	}
 	KeyTable[code] |= key;
