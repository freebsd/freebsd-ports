From: Paul Eggert <eggert@cs.ucla.edu>
Date: Fri, 28 Jan 2011 21:02:31 -0800
Subject: [PATCH] mktime: avoid problems on NetBSD 5 / i386

* lib/mktime.c (long_int): New type.  This works around a problem
on NetBSD 5 / i386, where 'long int' and 'int' are both 32 bits
but time_t is 64 bits, and where I expect the existing code is
wrong in some cases.
(leapyear, ydhms_diff, guess_time_tm, __mktime_internal): Use it.
(ydhms_diff): Bring back the compile-time check for wide-enough
year and yday.

--- lib/mktime.c.orig	2006-11-18 10:07:43 UTC
+++ lib/mktime.c
@@ -115,9 +115,15 @@ verify (twos_complement_arithmetic, TYPE_TWOS_COMPLEME
 #define TM_YEAR_BASE 1900
 verify (base_year_is_a_multiple_of_100, TM_YEAR_BASE % 100 == 0);
 
+#if INT_MAX <= LONG_MAX / 2
+typedef long int long_int;
+#else
+typedef long long int long_int;
+#endif
+
 /* Return 1 if YEAR + TM_YEAR_BASE is a leap year.  */
 static inline int
-leapyear (long int year)
+leapyear (long_int year)
 {
   /* Don't add YEAR to TM_YEAR_BASE, as that might overflow.
      Also, work even if YEAR is negative.  */
@@ -163,12 +169,12 @@ const unsigned short int __mon_yday[2][13] =
    detect overflow.  */
 
 static inline time_t
-ydhms_diff (long int year1, long int yday1, int hour1, int min1, int sec1,
+ydhms_diff (long_int year1, long_int yday1, int hour1, int min1, int sec1,
 	    int year0, int yday0, int hour0, int min0, int sec0)
 {
   verify (C99_integer_division, -1 / 2 == 0);
   verify (long_int_year_and_yday_are_wide_enough,
-	  INT_MAX <= LONG_MAX / 2 || TIME_T_MAX <= UINT_MAX);
+          INT_MAX == INT_MAX * (long_int) 2 / 2);
 
   /* Compute intervening leap days correctly even if year is negative.
      Take care to avoid integer overflow here.  */
@@ -199,7 +205,7 @@ ydhms_diff (long int year1, long int yday1, int hour1,
    If overflow occurs, yield the minimal or maximal value, except do not
    yield a value equal to *T.  */
 static time_t
-guess_time_tm (long int year, long int yday, int hour, int min, int sec,
+guess_time_tm (long_int year, long_int yday, int hour, int min, int sec,
 	       const time_t *t, const struct tm *tp)
 {
   if (tp)
@@ -301,8 +307,8 @@ __mktime_internal (struct tm *tp,
   int mon_remainder = mon % 12;
   int negative_mon_remainder = mon_remainder < 0;
   int mon_years = mon / 12 - negative_mon_remainder;
-  long int lyear_requested = year_requested;
-  long int year = lyear_requested + mon_years;
+  long_int lyear_requested = year_requested;
+  long_int year = lyear_requested + mon_years;
 
   /* The other values need not be in range:
      the remaining code handles minor overflows correctly,
@@ -314,8 +320,8 @@ __mktime_internal (struct tm *tp,
   int mon_yday = ((__mon_yday[leapyear (year)]
 		   [mon_remainder + 12 * negative_mon_remainder])
 		  - 1);
-  long int lmday = mday;
-  long int yday = mon_yday + lmday;
+  long_int lmday = mday;
+  long_int yday = mon_yday + lmday;
 
   time_t guessed_offset = *offset;
 
