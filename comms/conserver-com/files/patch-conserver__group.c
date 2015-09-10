--- ./conserver/group.c.orig	2009-09-26 05:58:05.000000000 -0400
+++ ./conserver/group.c	2013-02-15 18:34:20.000000000 -0500
@@ -72,6 +72,7 @@
 #include <master.h>
 #include <main.h>
 #include <version.h>
+#include <stdio.h>
 
 #if HAVE_PAM
 #include <security/pam_appl.h>
@@ -1930,7 +1931,7 @@
 	    FileWrite(pCL->fd, FLAGFALSE, sendtok.value, sendtok.length);
 	    FileSetQuoteIAC(pCL->fd, FLAGTRUE);
 	    pCL->iState = S_NORMAL;
-	    gss_release_buffer(NULL, &sendtok);
+	    gss_release_buffer(&stmin, &sendtok);
 	    BuildString((char *)0, pCL->username);
 	    BuildString((char *)0, pCL->acid);
 	    stmaj = gss_display_name(&stmin, user, &dbuf, NULL);
@@ -1940,7 +1941,7 @@
 	    BuildStringChar('@', pCL->acid);
 	    BuildString(pCL->peername->string, pCL->acid);
 	    gss_release_name(&stmin, &user);
-	    gss_release_buffer(NULL, &dbuf);
+	    gss_release_buffer(&stmin, &dbuf);
 	    ret = 1;
 	    break;
 	case GSS_S_CREDENTIALS_EXPIRED:
