
$FreeBSD$

--- wslib/info.c	2001/03/10 13:03:11	1.1
+++ wslib/info.c	2001/03/10 13:04:20
@@ -138,12 +138,6 @@
 		case AF_COMPRESSION_APPLE_MAC6:
 			fprintf(stderr, "Apple MAC6\n");
 			break;
-		case AF_COMPRESSION_MPEG1:
-			fprintf(stderr, "MPEG 1\n");
-			break;
-		case AF_COMPRESSION_AWARE_MULTIRATE:
-			fprintf(stderr, "Aware MultiRate\n");
-			break;
 		case AF_COMPRESSION_G726:
 			fprintf(stderr, "G726\n");
 			break;
@@ -158,18 +152,6 @@
 			break;
 		case AF_COMPRESSION_FS1016:
 			fprintf(stderr, "FS1016\n");
-			break;
-		case AF_COMPRESSION_DEFAULT_MPEG_I:
-			fprintf(stderr, "MPEG 1 Layer 1\n");
-			break;
-		case AF_COMPRESSION_DEFAULT_MPEG_II:
-			fprintf(stderr, "MPEG 1 Layer 2\n");
-			break;
-		case AF_COMPRESSION_DEFAULT_MULTIRATE:
-			fprintf(stderr, "MultiRate\n");
-			break;
-		case AF_COMPRESSION_DEFAULT_LOSSLESS:
-			fprintf(stderr, "Lossless\n");
 			break;
 		default:
 			fprintf(stderr, "Unknown\n");
