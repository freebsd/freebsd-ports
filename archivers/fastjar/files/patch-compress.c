--- compress.c.orig	2008-10-15 17:25:36 UTC
+++ compress.c
@@ -86,6 +86,10 @@ write_data (int fd, void *buf, size_t len,
 	      exit(EXIT_FAILURE);
 	    }
 	}
+      else if (!next && here + len >= end_of_entries)
+	{
+	  end_of_entries = here + len;
+	}
     }
 
   return write (fd, buf, len);
