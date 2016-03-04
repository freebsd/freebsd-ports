--- p2clib.c.orig	1993-12-08 05:36:53 UTC
+++ p2clib.c
@@ -890,7 +890,7 @@ int *Day, *Month, *Year, *Hour, *Min, *S
 {
 #ifndef NO_TIME
     struct tm *tm;
-    long clock;
+    time_t clock;
 
     time(&clock);
     tm = localtime(&clock);
@@ -908,7 +908,7 @@ int *Day, *Month, *Year, *Hour, *Min, *S
 Void VAXdate(s)
 char *s;
 {
-    long clock;
+    time_t clock;
     char *c;
     int i;
     static int where[] = {8, 9, 0, 4, 5, 6, 0, 20, 21, 22, 23};
@@ -924,7 +924,7 @@ char *s;
 Void VAXtime(s)
 char *s;
 {
-    long clock;
+    time_t clock;
     char *c;
     int i;
 
