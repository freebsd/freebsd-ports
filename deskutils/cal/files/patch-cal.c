*** cal.c.orig	Fri Jul 12 04:36:33 1996
--- cal.c	Mon May 12 15:23:51 1997
***************
*** 130,135 ****
--- 130,139 ----
  /* Note: Other unix systems may require this next re-define to work. */
  /* I believe that SCO is one such system.  Please send in any fixes  */
  /* needed to get your system running.                                */
+ #ifdef __FreeBSD__          /* Make FreeBSD compatible with stricmp() */
+ #define stricmp(a,b) strcasecmp(a,b) /* case-insensitive string comparison */
+ #endif
+  
  #ifdef __linux__          /* Make linux compatible with stricmp() */
  #define stricmp(a,b) strcasecmp(a,b) /* case-insensitive string comparison */
  #endif
***************
*** 1401,1408 ****
              strcpy(str, ".");
              strcpy(str, file);
              if ((fp = fopen(str, mode)) == NULL) {
!                 /* If still not found then look in a lib directory */
                  strcpy(str, "/usr/lib/");
                  strcat(str,file);
                  fp = fopen(str, mode);
              }
--- 1405,1416 ----
              strcpy(str, ".");
              strcpy(str, file);
              if ((fp = fopen(str, mode)) == NULL) {
!                 /* If still not found then look in config directory */
! #ifdef PREFIX
!                 strcpy(str, PREFIX "/etc/cal/");
! #else
                  strcpy(str, "/usr/lib/");
+ #endif
                  strcat(str,file);
                  fp = fopen(str, mode);
              }
