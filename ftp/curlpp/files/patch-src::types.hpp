--- src/types.hpp.orig	Wed Jan  8 11:28:59 2003
+++ src/types.hpp	Fri Feb 13 02:09:44 2004
@@ -47,8 +47,8 @@
    namespace time_condition
    {
       enum type { 
-         if_mod_since = TIMECOND_IFMODSINCE, 
-         if_unmod_sice = TIMECOND_IFUNMODSINCE 
+         if_mod_since = CURL_TIMECOND_IFMODSINCE, 
+         if_unmod_sice = CURL_TIMECOND_IFUNMODSINCE 
       };
    };
 
