The calculate_gmt_offset attempt is a botch. It gets localtm passed in from the
self-test's yesterday, and then calls time() anew to obtain ::gmtime_r() by way of details::os::gmtime(),
and that cannot possibly work.

https://github.com/gabime/spdlog/issues/3483

Fix: Disable the non-working code and use tm_gmtoff instead.

--- include/spdlog/details/os-inl.h.orig	2025-10-11 12:53:05 UTC
+++ include/spdlog/details/os-inl.h
@@ -264,11 +264,7 @@ SPDLOG_INLINE int utc_minutes_offset(const std::tm &tm
     return offset;
 #else
 
-    #if defined(sun) || defined(__sun) || defined(_AIX) ||                        \
-        (defined(__NEWLIB__) && !defined(__TM_GMTOFF)) ||                         \
-        (!defined(__APPLE__) && !defined(_BSD_SOURCE) && !defined(_GNU_SOURCE) && \
-         (!defined(_POSIX_VERSION) || (_POSIX_VERSION < 202405L)))
-    // 'tm_gmtoff' field is BSD extension and it's missing on SunOS/Solaris
+    #if 0
     struct helper {
         static long int calculate_gmt_offset(const std::tm &localtm = details::os::localtime(),
                                              const std::tm &gmtm = details::os::gmtime()) {
