--- objects.C.orig	Wed Jul 24 15:06:28 1996
+++ objects.C	Tue Apr  7 15:34:33 1998
@@ -533,28 +533,30 @@
 }
 
 #define DATA_TYPE	CARD32
-#define DATA_PAD	4
 void PixmapPiece::CreateTilemap32() {
 #	include "rotate.H"
 }
 #undef DATA_TYPE
-#undef DATA_PAD
+
+#define CARD24 long
+
+#define DATA_TYPE	CARD24
+void PixmapPiece::CreateTilemap24() {
+#	include "rotate.H"
+}
+#undef DATA_TYPE
 
 #define DATA_TYPE	CARD16
-#define DATA_PAD	2
 void PixmapPiece::CreateTilemap16() {
 #	include "rotate.H"
 }
 #undef DATA_TYPE
-#undef DATA_PAD
 
 #define DATA_TYPE	CARD8
-#define DATA_PAD	1
 void PixmapPiece::CreateTilemap8() {
 #	include "rotate.H"
 }
 #undef DATA_TYPE
-#undef DATA_PAD
 
 
 void PixmapPiece::DirectionChanged() {
@@ -573,10 +575,16 @@
 			XPix(wcenter.X())-offx, YPix(wcenter.Y())-offy, width, height, 0, 0 );
 	}
 	else {
-		switch(texture_mode) {
-		case 1:		CreateTilemap8();		break;
-		case 2:		CreateTilemap16();	break;
-		case 3:		CreateTilemap32();	break;
+		extern int pixmap_depth;
+
+		switch(pixmap_depth) {
+		case 8:		CreateTilemap8();	break;
+		case 16:	CreateTilemap16();	break;
+		case 32:	CreateTilemap32();	break;
+		case 24:	CreateTilemap24();	break;
+		default:
+			fprintf(stderr,"unhandled depth = %d\n",pixmap_depth);
+			exit(1);
 		}
 	}
 }
