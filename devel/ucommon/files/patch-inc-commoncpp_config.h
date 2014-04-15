--- inc/commoncpp/config.h.orig	2014-04-14 16:50:21.000000000 +0200
+++ inc/commoncpp/config.h	2014-04-14 17:02:39.000000000 +0200
@@ -50,7 +50,7 @@
  * @param string2 to compare.
  * @return 0 if equal, > 0 if s2 > s1, < 0 if s2 < s1.
  */
-extern "C" inline int stricmp(const char *string1, const char *string2)
+inline int stricmp(const char *string1, const char *string2)
     {return ucommon::String::case_compare(string1, string2);}
 
 /**
@@ -60,7 +60,7 @@
  * @param max size of string to compare.
  * @return 0 if equal, > 0 if s2 > s1, < 0 if s2 < s1.
  */
-extern "C" inline int strnicmp(const char *string1, const char *string2, size_t max)
+inline int strnicmp(const char *string1, const char *string2, size_t max)
     {return ucommon::String::case_compare(string1, string2, max);}
 
 #endif
