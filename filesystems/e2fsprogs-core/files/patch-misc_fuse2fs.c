--- misc/fuse2fs.c.orig	2026-03-06 17:17:36 UTC
+++ misc/fuse2fs.c
@@ -5117,7 +5117,9 @@ static int __translate_error(ext2_filsys fs, ext2_ino_
 #ifdef EILSEQ
 	case EILSEQ:
 #endif
+#if EUCLEAN != EIO
 	case EUCLEAN:
+#endif
 		/* these errnos usually denote corruption or persistence fail */
 		is_err = 1;
 		ret = -err;
