--- src/file.c.orig	Wed Oct 13 14:52:57 2004
+++ src/file.c	Wed Oct 13 14:53:07 2004
@@ -173,7 +173,7 @@
 	   case FAB$C_STMLF:  rfm = "stmlf"; break;
 	   case FAB$C_STMCR:  rfm = "stmcr"; break;
 	  }
-	mode = s.st_mode & 0777;
+	mode = s.st_mode & 07777;
      }
    else strcpy (rat_buf, "rat=cr");
    
@@ -1729,7 +1729,7 @@
 #ifdef REAL_UNIX_SYSTEM
 	int u;
 	
-	u = umask (mask & 0777);
+	u = umask (mask & 07777);
 	if (default_umask == 0) default_umask = u;
 #endif
      }
