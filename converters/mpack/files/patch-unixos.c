--- unixos.c.orig	2003-07-21 22:54:05.000000000 +0200
+++ unixos.c	2012-01-12 19:22:31.000000000 +0100
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
@@ -131,6 +137,20 @@
     rmdir(dir);
 }
 
+FILE *os_createfile(char *fname)
+{
+    int fd;
+    FILE *ret;
+    
+    fd=open(fname, O_RDWR|O_CREAT|O_TRUNC, 0600);
+
+    if (fd == -1)
+        return NULL;
+    
+    ret=fdopen(fd, "w");
+    return ret;
+}
+
 FILE *os_createnewfile(char *fname)
 {
     int fd;
@@ -194,7 +214,7 @@
 	do {
 	    if (outfile) fclose(outfile);
 	    sprintf(buf, "part%d", ++filesuffix);
-	} while (outfile = fopen(buf, "r"));
+	} while ((outfile = fopen(buf, "r")));
 	fname = buf;
     }
     else if (!overwrite_files && (outfile = fopen(fname, "r"))) {
@@ -202,7 +222,7 @@
 	    fclose(outfile);
 	    sprintf(buf, "%s.%d", fname, ++filesuffix);
 	 
-	} while (outfile = fopen(buf, "r"));
+	} while ((outfile = fopen(buf, "r")));
 	fname = buf;
     }
 
@@ -228,7 +248,7 @@
 
     p = strchr(descfname, '/');
     if (!p) p = descfname;
-    if (p = strrchr(p, '.')) *p = '\0';
+    if ((p = strrchr(p, '.'))) *p = '\0';
 
     strcat(descfname, ".desc");
     (void) rename(TEMPFILENAME, descfname);
