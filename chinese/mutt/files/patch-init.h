--- init.h.orig	Tue Jul 18 15:47:08 2000
+++ init.h	Mon Aug 14 02:50:40 2000
@@ -261,7 +261,7 @@
   ** When this variable is set, mutt will include Delivered-To headers when
   ** bouncing messages.  Postfix users may wish to unset this variable.
   */
-  { "charset",		DT_STR,	 R_NONE, UL &Charset, UL "iso-8859-1" },
+  { "charset",		DT_STR,	 R_NONE, UL &Charset, UL "big5" },
   /*
   ** .pp
   ** Character set your terminal uses to display and enter textual data.
@@ -2043,7 +2043,7 @@
   ** recipient.  The fifth character is used to indicate mail that was sent
   ** by \fIyou\fP.
   */
-  { "use_8bitmime",	DT_BOOL, R_NONE, OPTUSE8BITMIME, 0 },
+  { "use_8bitmime",	DT_BOOL, R_NONE, OPTUSE8BITMIME, 1 },
   /*
   ** .pp
   ** \fBWarning:\fP do not set this variable unless you are using a version
