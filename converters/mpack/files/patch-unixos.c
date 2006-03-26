--- unixos.c.orig	Mon Jul 21 23:54:05 2003
+++ unixos.c	Sun Mar 26 23:03:33 2006
@@ -23,24 +23,30 @@
  * SOFTWARE.
  */
 #include <stdio.h>
+#include <stdlib.h>
 #include <ctype.h>
 #include <string.h>
 #include <errno.h>
 #include <sys/types.h>
+#include <sys/stat.h>
 #include <sys/param.h>
+#include <time.h>
 #include <netdb.h>
 #include <fcntl.h>
+#include <unistd.h>
 #include "xmalloc.h"
 #include "common.h"
 #include "part.h"
 
+extern void warn(char *s);
+
 #ifndef MAXHOSTNAMELEN
 #define MAXHOSTNAMELEN 64
 #endif
 
+#ifndef errno
 extern int errno;
-extern char *malloc();
-extern char *getenv();
+#endif
 
 int overwrite_files = 0;
 int didchat;
@@ -76,7 +82,7 @@
     }
 
     result = malloc(25+strlen(hostname));
-    sprintf(result, "%d.%d@%s", pid, curtime++, hostname);
+    sprintf(result, "%d.%lu@%s", pid, (unsigned long) curtime++, hostname);
     return result;
 }
 
@@ -90,7 +96,7 @@
 	strcpy(buf, getenv("TMPDIR"));
     }
     else {
-	strcpy(buf, "/usr/tmp");
+	strcpy(buf, "/tmp");
     }
     strcat(buf, "/m-prts-");
     p = getenv("USER");
@@ -136,11 +142,7 @@
     int fd;
     FILE *ret;
      
-#ifdef O_EXCL
-    fd=open(fname, O_RDWR|O_CREAT|O_EXCL, 0644);
-#else
     fd=open(fname, O_RDWR|O_CREAT|O_TRUNC, 0644);
-#endif
 
     if (fd == -1)
         return NULL;
@@ -194,7 +196,7 @@
 	do {
 	    if (outfile) fclose(outfile);
 	    sprintf(buf, "part%d", ++filesuffix);
-	} while (outfile = fopen(buf, "r"));
+	} while ((outfile = fopen(buf, "r")));
 	fname = buf;
     }
     else if (!overwrite_files && (outfile = fopen(fname, "r"))) {
@@ -202,7 +204,7 @@
 	    fclose(outfile);
 	    sprintf(buf, "%s.%d", fname, ++filesuffix);
 	 
-	} while (outfile = fopen(buf, "r"));
+	} while ((outfile = fopen(buf, "r")));
 	fname = buf;
     }
 
@@ -228,7 +230,7 @@
 
     p = strchr(descfname, '/');
     if (!p) p = descfname;
-    if (p = strrchr(p, '.')) *p = '\0';
+    if ((p = strrchr(p, '.'))) *p = '\0';
 
     strcat(descfname, ".desc");
     (void) rename(TEMPFILENAME, descfname);
