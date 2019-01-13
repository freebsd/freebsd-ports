Remove erroneous abort() call
https://git.savannah.gnu.org/cgit/tar.git/diff/?id=85c005ee1345c342f707f3c55317daf6cb050603

--- src/extract.c.orig	2019-01-13 15:07:22 UTC
+++ src/extract.c
@@ -787,7 +787,7 @@ maybe_recoverable (char *file_name, bool regular, bool
 	case UNLINK_FIRST_OLD_FILES:
 	  break;
 	}
-      abort (); /* notreached */
+      FALLTHROUGH;
 
     case ENOENT:
       /* Attempt creating missing intermediate directories.  */
