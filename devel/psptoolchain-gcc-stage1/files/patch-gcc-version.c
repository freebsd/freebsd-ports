--- gcc/version.c.orig	2005-03-16 06:04:10.000000000 +0000
+++ gcc/version.c	2006-05-07 13:47:56.000000000 +0100
@@ -8,7 +8,7 @@
    in parentheses.  You may also wish to include a number indicating
    the revision of your modified compiler.  */
 
-#define VERSUFFIX ""
+#define VERSUFFIX " (PSPDEV 20060507)"
 
 /* This is the location of the online document giving instructions for
    reporting bugs.  If you distribute a modified version of GCC,
@@ -17,7 +17,7 @@
    forward us bugs reported to you, if you determine that they are
    not bugs in your modifications.)  */
 
-const char bug_report_url[] = "<URL:http://gcc.gnu.org/bugs.html>";
+const char bug_report_url[] = "<URL:http://wiki.pspdev.org/psp:toolchain#bugs>";
 
 /* The complete version string, assembled from several pieces.
    BASEVER, DATESTAMP, and DEVPHASE are defined by the Makefile.  */
