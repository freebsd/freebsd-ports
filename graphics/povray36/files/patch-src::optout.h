--- src/optout.h.orig	Thu Aug  8 22:00:48 2002
+++ src/optout.h	Wed Aug 14 12:14:50 2002
@@ -46,8 +46,7 @@
 #define OFFICIAL_VERSION_NUMBER 350
 
 #define DISTRIBUTION_MESSAGE_1 "This is an unofficial version compiled by:"
-#error You must complete the following DISTRIBUTION_MESSAGE macro
-#define DISTRIBUTION_MESSAGE_2 " FILL IN NAME HERE........................."
+#define DISTRIBUTION_MESSAGE_2 "FreeBSD, http://www.freebsd.org/"
 #define DISTRIBUTION_MESSAGE_3 " The POV-Ray Team(tm) is not responsible for supporting this version."
 
 /* Number of help pages (numbered 0 to MAX_HELP_PAGE). */
