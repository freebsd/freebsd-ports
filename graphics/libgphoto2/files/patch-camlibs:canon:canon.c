--- camlibs/canon/canon.c.orig	Sun Aug 10 20:51:13 2003
+++ camlibs/canon/canon.c	Mon Oct 20 10:17:48 2003
@@ -138,6 +138,8 @@
         /* 0x306D is S45 in PTP mode */
 	{"Canon:PowerShot G3 (normal mode)",	CANON_PS_G3,	0x04A9, 0x306E, CAP_SUP, S99M, S32K, NULL},
         /* 0x306F is G3 in PTP mode */
+	{"Canon:PowerShot G5 (normal mode)",	CANON_PS_G5,	0x04A9, 0x3085, CAP_SUP, S99M, S32K, NULL},
+        /* XXX 0x???? is G5 in PTP mode */
 	{"Canon:PowerShot S230 (normal mode)",	CANON_PS_S230,	0x04A9, 0x3070, CAP_SUP, S99M, S32K, NULL},
         /* 0x3071 is S230 in PTP mode */
 	{"Canon:Digital IXUS v3 (normal mode)",	CANON_PS_S230,	0x04A9, 0x3070, CAP_SUP, S99M, S32K, NULL},
@@ -250,6 +252,7 @@
 	case CANON_PS_S40:
 	case CANON_PS_S45:
 	case CANON_PS_G3:
+	case CANON_PS_G5:
 		break;
 	default:
 		GP_DEBUG ("canon_int_filename2audioname: camera model doesn't support audio files",
