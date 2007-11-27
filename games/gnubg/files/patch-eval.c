--- eval.c.orig	2007-11-25 23:01:11.000000000 +0100
+++ eval.c	2007-11-25 23:02:20.000000000 +0100
@@ -798,7 +798,7 @@
 	    if( !fstat( h, &st ) &&
 		( p = mmap( NULL, st.st_size, PROT_READ | PROT_WRITE,
 			    MAP_PRIVATE, h, 0 ) ) ) {
-		( (float *) p ) += 2; /* skip magic number and version */
+		p += 2; /* skip magic number and version */
 		fReadWeights =
 		    ( p = NeuralNetCreateDirect( &nnContact, p ) ) &&
 		    ( p = NeuralNetCreateDirect( &nnRace, p ) ) &&
