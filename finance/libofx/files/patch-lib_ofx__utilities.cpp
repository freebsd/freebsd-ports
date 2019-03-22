Emulate the behavior of the USG UXIX daylight variable implemented in glibc.
It is supposed to be 0 if the time zone does not have any daylight saving time
rules and non-zero if there is a time during the year when daylight saving
time applies. [1]

In FreeBSD, tzname[1] should be set to "   " (three spaces) if DST is never
observed. [2]

[1] https://www.gnu.org/software/libc/manual/html_node/Time-Zone-Functions.html#Time-Zone-Functions
[2] https://svnweb.freebsd.org/base/head/contrib/tzcode/stdtime/localtime.c?revision=313774&view=markup#l84

--- lib/ofx_utilities.cpp.orig	2018-05-02 19:39:38 UTC
+++ lib/ofx_utilities.cpp
@@ -142,6 +142,10 @@ time_t ofxdate_to_time_t(const string ofxdate)
   std::time(&temptime);
   local_offset = difftime(mktime(localtime(&temptime)), mktime(gmtime(&temptime)));
   /* daylight is set to 1 if the timezone indicated by the environment (either TZ or /etc/localtime) uses daylight savings time (aka summer time). We use it here to provisionally set tm_isdst. */
+#if defined(__FreeBSD__)
+  tzset();
+  int daylight = ((tzname[1][0] == ' ') ? 0 : 1);
+#endif
   time.tm_isdst = daylight;
 
   if (ofxdate.size() != 0)
