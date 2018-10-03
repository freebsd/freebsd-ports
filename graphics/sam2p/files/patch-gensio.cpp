--- gensio.cpp.orig	2014-01-19 19:50:35 UTC
+++ gensio.cpp
@@ -731,11 +731,7 @@ slen_t Filter::FlatD::vi_read(char *to_b
 /* --- */
 
 
-#if HAVE_lstat_in_sys_stat
-#  define PTS_lstat lstat
-#else
 #  define PTS_lstat stat
-#endif
 
 /** @param fname must start with '/' (dir separator)
  * @return true if file successfully created
