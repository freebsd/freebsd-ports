--- apr/misc/unix/getopt.c.orig	Thu Nov 29 06:19:51 2001
+++ apr/misc/unix/getopt.c	Sun Aug 11 11:29:01 2002
@@ -237,10 +237,12 @@
 	    for (i = 0; ; i++) {
 	        if (opts[i].optch == 0)             /* No match */
 		    return serr(os, "invalid option", p - 2, APR_BADCH);
+		if (opts[i].name) {
 		len = strlen(opts[i].name);
 		if (strncmp(p, opts[i].name, len) == 0
 		    && (p[len] == '\0' || p[len] == '='))
 		    break;
+		}
 	    }
 	    *optch = opts[i].optch;
 
