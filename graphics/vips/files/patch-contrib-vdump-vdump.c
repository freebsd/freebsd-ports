--- contrib/vdump/vdump.c.orig	Tue Feb  8 07:19:19 2005
+++ contrib/vdump/vdump.c
@@ -309,9 +309,9 @@
 	/* Print body of file.
 	 */
 	if( im->Bands == 3 )
-		encode_colour( im, scale, im->data );
+		encode_colour( im, scale, (struct pixel *) im->data );
 	else
-		encode_mono( im, scale, im->data );
+		encode_mono( im, scale, (struct mpixel *) im->data );
 	
 	/* Print trailer.
 	 */
