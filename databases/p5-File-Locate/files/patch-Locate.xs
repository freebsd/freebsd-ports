--- Locate.xs.orig	2007-02-17 13:56:53 UTC
+++ Locate.xs
@@ -48,7 +48,8 @@ extern int errno;
 uid_t UID;
 gid_t GID;
 
-typedef enum {false, true} boolean;
+// typedef enum {false, true} boolean;
+#include <stdbool.h>
 
 static char * last_literal_end (char *name) {
     static char *globfree = NULL;	/* A copy of the subpattern in NAME.  */
@@ -247,7 +248,7 @@ _locate (pathpart, ...) 
         FILE *fp;           /* The pathname database.  */
         int c;              /* An input byte.  */
         int nread;          /* Number of bytes read from an entry.  */
-        boolean globflag;   /* true if PATHPART contains globbing 
+        bool globflag;   /* true if PATHPART contains globbing 
                                metacharacters.  */
         char *patend;       /* The end of the last glob-free subpattern 
                                in PATHPART.  */
@@ -258,11 +259,11 @@ _locate (pathpart, ...) 
         char *cutoff;       /* Where in `path' to stop the backward search for
                                the last character in the subpattern.  Set
                                according to `count'.  */
-        boolean prev_fast_match = false;    /* true if we found a fast match
+        bool prev_fast_match = false;    /* true if we found a fast match
                                                (of patend) on the previous
                                                path.  */
         int printed = 0;                    /* The return value.  */
-        boolean old_format = false;         /* true if reading a bigram-encoded
+        bool old_format = false;         /* true if reading a bigram-encoded
                                                database.  */
         char bigram1[128], bigram2[128];    /* For the old database format, the
                                                first and second characters of
@@ -511,7 +512,7 @@ _slocate (str, ...)
 	char slevel = '1';
 	int res = 0;
 
-        boolean prev_fast_match = false;    /* true if we found a fast match
+        bool prev_fast_match = false;    /* true if we found a fast match
                                                (of patend) on the previous
                                                path.  */
 	register int i;
