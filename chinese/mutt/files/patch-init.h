--- init.h.orig	2016-12-02 11:18:42.572961000 +0800
+++ init.h	2016-12-02 11:18:42.600298000 +0800
@@ -290,6 +290,11 @@ struct option_t MuttVars[] = {
   ** .pp
   ** Also see $$fast_reply.
   */
+  { "bbsislame",	DT_BOOL, R_NONE, OPTBBSISLAME, 0 },
+  /*
+  ** .pp
+  ** When this variable is set, mutt will beep when an error occurs.
+  */
   { "beep",		DT_BOOL, R_NONE, OPTBEEP, 1 },
   /*
   ** .pp
@@ -2667,7 +2672,7 @@ struct option_t MuttVars[] = {
   ** For the pager, this variable specifies the number of lines shown
   ** before search results. By default, search results will be top-aligned.
   */
-  { "send_charset",	DT_STR,  R_NONE, UL &SendCharset, UL "us-ascii:iso-8859-1:utf-8" },
+  { "send_charset",	DT_STR,  R_NONE, UL &SendCharset, UL "big5:gb2312:us-ascii:iso-8859-1:utf-8" },
   /*
   ** .pp
   ** A colon-delimited list of character sets for outgoing messages. Mutt will use the
@@ -3649,7 +3654,7 @@ struct option_t MuttVars[] = {
   ** When \fIset\fP, Mutt will jump to the next unread message, if any,
   ** when the current thread is \fIun\fPcollapsed.
   */
-  { "use_8bitmime",	DT_BOOL, R_NONE, OPTUSE8BITMIME, 0 },
+  { "use_8bitmime",	DT_BOOL, R_NONE, OPTUSE8BITMIME, 1 },
   /*
   ** .pp
   ** \fBWarning:\fP do not set this variable unless you are using a version
