--- src/core/uae/build68k.c.orig	2005-06-25 14:27:52 UTC
+++ src/core/uae/build68k.c
@@ -52,7 +52,7 @@ static int nextchtohex(void)
      case 'd': return 13;
      case 'e': return 14;
      case 'f': return 15;
-     default: abort();
+     default: uae_abort();
     }
 }
 
@@ -114,7 +114,7 @@ int main(int argc, char **argv)
 	     case 'R': currbit = bitR; break;
 	     case 'z': currbit = bitz; break;
 	     case 'p': currbit = bitp; break;
-	     default: abort();
+	     default: uae_abort();
 	    }
 	    if (!(bitmask & 1)) {
 		bitpos[n_variable] = currbit;
@@ -138,7 +138,7 @@ int main(int argc, char **argv)
 	 case '2': cpulevel = 2; break;
 	 case '3': cpulevel = 3; break;
 	 case '4': cpulevel = 4; break;
-	 default: abort();
+	 default: uae_abort();
 	}
 	getnextch();
 
@@ -147,7 +147,7 @@ int main(int argc, char **argv)
 	 case '1': plevel = 1; break;
 	 case '2': plevel = 2; break;
 	 case '3': plevel = 3; break;
-	 default: abort();
+	 default: uae_abort();
 	}
 	getnextch();
 
@@ -155,7 +155,7 @@ int main(int argc, char **argv)
 	    getnextch();
 
 	if (nextch != ':')
-	    abort();
+	    uae_abort();
 
 	for(i = 0; i < 5; i++) {
 	    getnextch();
@@ -176,7 +176,7 @@ int main(int argc, char **argv)
 	    getnextch();
 
 	if (nextch != ':')                        /* Get flag used information */
-	    abort();
+	    uae_abort();
 
 	for(i = 0; i < 5; i++) {
 	    getnextch();
@@ -194,7 +194,7 @@ int main(int argc, char **argv)
 	    getnextch();
 
 	if (nextch != ':')                        /* Get source/dest usage information */
-	    abort();
+	    uae_abort();
 
 	getnextch();
 	sduse = nextchtohex() << 4;
@@ -206,7 +206,7 @@ int main(int argc, char **argv)
 	    getnextch();
 
 	if (nextch != ':')
-	    abort();
+	    uae_abort();
 
 	fgets(opcstr, 250, tablef);
 	getnextch();
