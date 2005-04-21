--- libsee/obj_Date.c.orig	2004-10-17 15:50:50.000000000 +0200
+++ libsee/obj_Date.c	2005-04-21 14:51:24.086576359 +0200
@@ -113,13 +113,16 @@
 static SEE_number_t DateFromTime(SEE_number_t);		/* 15.9.1.5 */
 #define WeekDay(t)		modulo(Day(t)+4,7)	/* 15.9.1.6 */
 
-/*
- * XXX TODO: timezone conversion functions. Currently we assume local == UTC
- */
-#define LocalTZA	0 				/* 15.9.1.7 */
-#define DaylightSavingTA(t) 0 				/* 15.9.1.8 */
-#define LocalTime(t)	((t) + LocalTZA + DaylightSavingTA(t)) /* 15.9.1.9 */
-#define UTC(t)		((t) - LocalTZA - DaylightSavingTA(t - LocalTZA))
+#define UTC(t)         (t)
+SEE_number_t LocalTime(SEE_number_t t) {
+  SEE_number_t ret;
+  const time_t tt=time(NULL);
+  ret=timegm(localtime(&tt));
+  ret-=tt;
+  ret*=1000;
+  ret+=t;
+  return ret;
+}
 
 /* 15.9.1.10 */
 #define	HourFromTime(t)	modulo(floor((t) / msPerHour), HoursPerDay)
