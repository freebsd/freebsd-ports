
$FreeBSD$

--- parser/src/parser.c.orig	Sun Aug 22 16:26:05 2004
+++ parser/src/parser.c	Sun Aug 22 16:26:25 2004
@@ -313,7 +313,7 @@
 		buf = mmap(0, *size, PROT_READ, MAP_SHARED, f, 0);
 		if (buf == MAP_FAILED) buf = NULL;
 		break;
-	    default:
+	    default: break;
 	}
     }
     close(f);
@@ -333,7 +333,7 @@
 	    // munmap
 	    munmap(text, size);
 	    break;
-	default:
+	default: break;
     }
 }
 
