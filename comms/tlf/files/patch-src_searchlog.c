--- src/searchlog.c.orig	Fri May 21 12:15:14 2004
+++ src/searchlog.c	Sun Jul 11 01:04:54 2004
@@ -26,6 +26,8 @@
 #	include <config.h>
 #endif

+static char searchresult[MAX_CALLS][82];
+static char result[MAX_CALLS][82];

  	int searchlog(char *searchstring)

@@ -75,9 +77,7 @@
     extern int itumult;


-char searchresult[MAX_CALLS][82];
 int srch_index=0;
-char result[MAX_CALLS][82];
 int r_index=0;
 char s_inputbuffer[82] =  "";
 char s_inputbuffercpy[82] =  "";
@@ -90,13 +90,13 @@
 char *tmpstr;

 char callmaster_location[80];
-
+#if 0
 	if (strlen(s_inputbuffer)>=83)
 	{
 		printf ("WARNING: Input buffer is longer than 82 characters! exiting...");
 		exit(1);
 	}
-
+#endif
 	strcpy(callmaster_location, PACKAGE_DATA_DIR) ;
 	strcat(callmaster_location, "/callmaster ") ;

