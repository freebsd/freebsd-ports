--- lib/fits.c.orig	2020-05-15 16:58:42 UTC
+++ lib/fits.c
@@ -1023,6 +1023,7 @@ gal_fits_key_date_to_seconds(char *fitsdate, char **su
   time_t t;
   char *tmp;
   struct tm tp;
+  size_t seconds;
   void *outptr=subsec;
 
   /* Fill in the 'tp' elements with values read from the string. */
@@ -1044,14 +1045,23 @@ gal_fits_key_date_to_seconds(char *fitsdate, char **su
                 tmp);
     }
 
-  /* Convert the 'tm' structure to 'time_t'. Note that the system's
-     timezone and daylight saving need to be subtracted from the output of
-     'mktime'. Otherwise the result will be different on different
-     host-system timezones (which is not what we want here: bug #57995). */
-  t=mktime(&tp)-timezone-daylight;
+  /* Convert the contents of the 'tm' structure to 'time_t' (a positive
+     integer) with 'mktime'. Note that by design, the system's timezone is
+     included in the returned value of 'mktime' (leading to situations like
+     bug #57995). But it writes the given time's timezone (number of
+     seconds ahead of UTC) in the 'tm_gmtoff' element of its input.
 
-  /* Return the value and set the output pointer. */
-  return (size_t)t;
+     IMPORTANT NOTE: the timezone that is calculated by 'mktime' (in
+     'tp.tm_gmtoff') belongs to the time that is already within 'tp' (this
+     is exactly what we want!). So for example when daylight saving is
+     activated at run-time, but at the time inside 'tp', there was no
+     daylight saving, the value of 'tp.tm_gmtoff' will be different from
+     the 'timezone' global variable. */
+  t=mktime(&tp);
+
+  /* Calculate the seconds and return it. */
+  seconds = (t == (time_t)(-1)) ? GAL_BLANK_SIZE_T : (t+tp.tm_gmtoff);
+  return seconds;
 }
 
 
