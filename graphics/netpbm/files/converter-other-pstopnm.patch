--- converter/other/pstopnm.c.orig	Wed Jun 23 04:22:33 2004
+++ converter/other/pstopnm.c	Fri Aug 12 07:57:41 2005
@@ -702,13 +702,13 @@
 
     if (verbose) {
         pm_message("execing '%s' with args '%s' (arg 0), "
-                   "'%s', '%s', '%s', '%s', '%s', '%s', '%s'",
+                   "'%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s",
                    ghostscriptProg, arg0,
-                   deviceopt, outfileopt, gopt, ropt, "-q", "-dNOPAUSE", "-");
+                   deviceopt, outfileopt, gopt, ropt, "-q", "-dNOPAUSE", "-dSAFER", "-");
     }
 
     execl(ghostscriptProg, arg0, deviceopt, outfileopt, gopt, ropt, "-q",
-          "-dNOPAUSE", "-", NULL);
+          "-dNOPAUSE", "-dSAFER", "-", NULL);
     
     pm_error("execl() of Ghostscript ('%s') failed, errno=%d (%s)",
              ghostscriptProg, errno, strerror(errno));
