--- libsee/obj_Date.c.orig	Wed Jan 18 13:51:50 2006
+++ libsee/obj_Date.c	Mon Mar 27 10:56:41 2006
@@ -2167,20 +2167,12 @@
 DaylightSavingTA(t)
 	SEE_number_t t;
 {
-	SEE_number_t ysec = t - TimeFromYear((SEE_number_t)YearFromTime(t));
-	int ily = InLeapYear(t);
-	int wstart = WeekDay(TimeFromYear((SEE_number_t)YearFromTime(t)));
-	int equiv_year = yearmap[ily][wstart];
 	struct tm tm;
 	time_t dst_time, nodst_time;
+	time_t tt;
+        tt=t/1000;
+        tm=*localtime(&tt);
 
-	memset(&tm, 0, sizeof tm);
-	tm.tm_sec = SecFromTime(ysec);
-	tm.tm_min = MinFromTime(ysec);
-	tm.tm_hour = HourFromTime(ysec);
-	tm.tm_mday = DateFromTime(ysec);
-	tm.tm_mon = MonthFromTime(ysec) - 1;
-	tm.tm_year = equiv_year - 1900;
 	tm.tm_isdst = -1;
 
 	if (tm.tm_isdst == 0) return 0;
@@ -2189,7 +2181,7 @@
 	tm.tm_isdst = 0;
 	nodst_time = mktime(&tm);
 
-	return (dst_time - nodst_time) * 1000;
+	return -(dst_time - nodst_time) * 1000;
 }
 
 static void
