--- inc/ucommon/string.h.orig	2014-04-14 17:03:00.000000000 +0200
+++ inc/ucommon/string.h	2014-04-14 17:03:09.000000000 +0200
@@ -1627,7 +1627,7 @@
  * @param string2 to compare.
  * @return 0 if equal, > 0 if s2 > s1, < 0 if s2 < s1.
  */
-extern "C" inline int stricmp(const char *string1, const char *string2)
+inline int stricmp(const char *string1, const char *string2)
     {return String::case_compare(string1, string2);}
 
 /**
@@ -1637,7 +1637,7 @@
  * @param max size of string to compare.
  * @return 0 if equal, > 0 if s2 > s1, < 0 if s2 < s1.
  */
-extern "C" inline int strnicmp(const char *string1, const char *string2, size_t max)
+inline int strnicmp(const char *string1, const char *string2, size_t max)
     {return String::case_compare(string1, string2, max);}
 
 #endif
