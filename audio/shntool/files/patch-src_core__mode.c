--- src/core_mode.c.orig	2009-03-30 05:55:33 UTC
+++ src/core_mode.c
@@ -467,13 +467,6 @@ static wlong is_m_ss_nnn(unsigned char *buf,wave_info 
    host does not conform to Posix.  */
 #define ISDIGIT(c) ((unsigned) (c) - '0' <= 9)
 
-#undef __strverscmp
-#undef strverscmp
-
-#ifndef weak_alias
-# define __strverscmp strverscmp
-#endif
-
 /* Compare S1 and S2 as strings holding indices/version numbers,
    returning less than, equal to or greater than zero if S1 is less than,
    equal to or greater than S2 (for more info, see the texinfo doc).
@@ -548,13 +541,10 @@ __strverscmp (const char *s1, const char *s2)
       return state;
     }
 }
-#ifdef weak_alias
-static weak_alias (__strverscmp, strverscmp)
-#endif
 
 static int compare_version(const wave_info **w1,const wave_info **w2)
 {
-  return strverscmp(w1[0]->filename,w2[0]->filename);
+  return __strverscmp(w1[0]->filename,w2[0]->filename);
 }
 
 static int compare_ascii(const wave_info **w1,const wave_info **w2)
