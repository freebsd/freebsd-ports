--- cal.c.orig	1996-07-11 19:36:33 UTC
+++ cal.c
@@ -130,6 +130,10 @@ BASIC DATA STRUCTURE:                   
 /* Note: Other unix systems may require this next re-define to work. */
 /* I believe that SCO is one such system.  Please send in any fixes  */
 /* needed to get your system running.                                */
+#ifdef __FreeBSD__          /* Make FreeBSD compatible with stricmp() */
+#define stricmp(a,b) strcasecmp(a,b) /* case-insensitive string comparison */
+#endif
+ 
 #ifdef __linux__          /* Make linux compatible with stricmp() */
 #define stricmp(a,b) strcasecmp(a,b) /* case-insensitive string comparison */
 #endif
@@ -1401,8 +1405,12 @@ FILE *efopen(const char *file, const cha
             strcpy(str, ".");
             strcpy(str, file);
             if ((fp = fopen(str, mode)) == NULL) {
-                /* If still not found then look in a lib directory */
+                /* If still not found then look in config directory */
+#ifdef PREFIX
+                strcpy(str, PREFIX "/etc/cal/");
+#else
                 strcpy(str, "/usr/lib/");
+#endif
                 strcat(str,file);
                 fp = fopen(str, mode);
             }
