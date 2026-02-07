--- score.C.orig	2002-06-16 00:20:30.000000000 +0900
+++ score.C	2011-12-14 16:34:35.000000000 +0900
@@ -73,7 +73,7 @@
     date[8] = '\0';
     strncpy(time, &buffer[53], 8);
     time[8] = '\0';
-    if (date[0] == '1') {
+    if (date[3] == '-') {
         for(int i=1; i<8; i++) {
             date[i-1] = date[i];
         }
@@ -372,12 +372,12 @@
     time_t t;
     struct tm *tp;
     struct passwd *pw;
-    char   namebuf[128], myname[NAMELEN+1], gecos[128], *po;
+    char   namebuf[NBUFLEN+1], myname[NAMELEN+1], gecos[GECOSLEN+1], *po;
 
     s1 = scoreToRegister / 1000;
     ms_to_hms(scoreToRegister, h, m, s);
     pw = getpwuid(getuid());
-    strcpy(gecos, pw->pw_gecos);
+    strncpy(gecos, pw->pw_gecos, GECOSLEN);
     if ((po = strchr(gecos, ',')) != NULL)
         *po = 0;
     sprintf(namebuf, "%-8.8s (%s)", pw->pw_name, gecos);

