--- src/rcsfnms.c
+++ freebsd/gnu/usr.bin/rcs/lib/rcsfnms.c
@@ -285,6 +284,9 @@ maketemp(n)
 {
 	char *p;
 	char const *t = tpnames[n];
+#	if has_mktemp
+	int fd;
+#	endif
 
 	if (t)
 		return t;
@@ -296,10 +298,12 @@ maketemp(n)
 	    size_t tplen = dir_useful_len(tp);
 	    p = testalloc(tplen + 10);
 	    VOID sprintf(p, "%.*s%cT%cXXXXXX", (int)tplen, tp, SLASH, '0'+n);
-	    if (!mktemp(p) || !*p)
+	    fd = mkstemp(p);
+	    if (fd < 0 || !*p)
 		faterror("can't make temporary pathname `%.*s%cT%cXXXXXX'",
 			(int)tplen, tp, SLASH, '0'+n
 		);
+	    close(fd);
 #	else
 	    static char tpnamebuf[TEMPNAMES][L_tmpnam];
 	    p = tpnamebuf[n];
@@ -868,6 +872,47 @@ getfullRCSname()
         }
 }
 
+/* Derived from code from the XFree86 project */
+	char const *
+getfullCVSname()
+/* Function: returns a pointer to the path name of the RCS file with the
+ * CVSROOT part stripped off, and with 'Attic/' stripped off (if present).
+ */
+{
+
+#define ATTICDIR "/Attic"
+
+	char const *namebuf = getfullRCSname();
+	char *cvsroot = cgetenv("CVSROOT");
+	int cvsrootlen;
+	char *c = NULL;
+	int alen = strlen(ATTICDIR);
+
+	if ((c = strrchr(namebuf, '/')) != NULL) {
+	    if (namebuf - c >= alen) {
+		if (!strncmp(c - alen, ATTICDIR, alen)) {
+		    while(*c != '\0') {
+			*(c - alen) = *c;
+			c++;
+		    }
+		    *(c - alen) = '\0';
+		}
+	    }
+	}
+	
+	if (!cvsroot)
+	    return(namebuf);
+	else
+	{
+	    cvsrootlen = strlen(cvsroot);
+	    if (!strncmp(namebuf, cvsroot, cvsrootlen) &&
+	        namebuf[cvsrootlen] == '/')
+		return(namebuf + cvsrootlen + 1);
+	    else
+		return(namebuf);
+	}
+}
+
 	static size_t
 dir_useful_len(d)
 	char const *d;
