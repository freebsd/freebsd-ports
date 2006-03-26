--- unixpk.c.orig	Mon Jul 21 23:50:41 2003
+++ unixpk.c	Sun Mar 26 23:35:56 2006
@@ -23,23 +23,25 @@
  * SOFTWARE.
  */
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 #include <errno.h>
+#include <sys/types.h>
+#include <sys/wait.h>
+#include <unistd.h>
 #include "common.h"
 #include "version.h"
 #include "xmalloc.h"
 
 #define MAXADDRESS 100
 
-extern char *getenv();
-
-extern int errno;
-extern int optind;
-extern char *optarg;
-
 void usage(void);
 void sendmail(FILE *infile, char **addr, int start);
 void inews(FILE *infile);
+void os_perror(char *str);
+int encode(FILE *infile, FILE *applefile, char *fname, FILE *descfile,
+	   char *subject, char *headers, long int maxsize,
+	   char *typeoverride, char *outfname);
 
 int main(int argc, char **argv)
 {
@@ -155,7 +157,7 @@
 	    fprintf(stderr, "A subject is required\n");
 	    usage();
 	}
-	if (p = strchr(sbuf, '\n')) *p = '\0';
+	if ((p = strchr(sbuf, '\n'))) *p = '\0';
 	subject = sbuf;
     }	
 
@@ -164,10 +166,10 @@
 	    strcpy(fnamebuf, getenv("TMPDIR"));
 	}
 	else {
-	    strcpy(fnamebuf, "/usr/tmp");
+	    strcpy(fnamebuf, "/tmp");
 	}
 	strcat(fnamebuf, "/mpackXXXXXX");
-	mktemp(fnamebuf);
+	close(mkstemp(fnamebuf));
 	outfname = strsave(fnamebuf);
     }
 
