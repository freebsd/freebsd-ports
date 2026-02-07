--- gifx_image.C.orig	Wed Jul 24 00:12:55 1996
+++ gifx_image.C	Tue Apr  7 15:34:33 1998
@@ -62,12 +62,16 @@
 	offset_rows=0;
 #endif
 	DropData();
-	switch(texture_mode) {
-	case 1:		Reset8();		break;
-	case 2:		Reset16();		break;
-	case 3:		Reset32();		break;
-	default:		fprintf( stderr, "depth not supported\n" );
-					exit(0);
+
+	extern int pixmap_depth;
+
+	switch(pixmap_depth) {
+	case 8:		Reset8();		break;
+	case 16:	Reset16();		break;
+	case 24:	Reset24();		break;
+	case 32:	Reset32();		break;
+	default:	fprintf( stderr, "depth not supported\n" );
+			exit(0);
 	}
 }
 
@@ -90,29 +94,40 @@
 }
 
 /*----------------------------------------------------------------------------*/
+
+#define CARD24 long
+
+#define	DATA_TYPE	CARD24
+#define	DATA_BYTES	3
+void GifXImage::Reset24() {
+#	include "reset_image.H"
+}
+#undef DATA_TYPE
+#undef DATA_BYTES
+/*----------------------------------------------------------------------------*/
 #define	DATA_TYPE	CARD32
-#define	DATA_PAD		4
+#define	DATA_BYTES	4
 void GifXImage::Reset32() {
 #	include "reset_image.H"
 }
 #undef DATA_TYPE
-#undef DATA_PAD
+#undef DATA_BYTES
 /*----------------------------------------------------------------------------*/
 #define	DATA_TYPE	CARD16
-#define	DATA_PAD		2
+#define	DATA_BYTES	2
 void GifXImage::Reset16() {
 #	include "reset_image.H"
 }
 #undef DATA_TYPE
-#undef DATA_PAD
+#undef DATA_BYTES
 /*----------------------------------------------------------------------------*/
 #define	DATA_TYPE	CARD8
-#define	DATA_PAD		1
+#define	DATA_BYTES	1
 void GifXImage::Reset8() {
 #	include "reset_image.H"
 }
 #undef DATA_TYPE
-#undef DATA_PAD
+#undef DATA_BYTES
 
 // ========================================================================
 
