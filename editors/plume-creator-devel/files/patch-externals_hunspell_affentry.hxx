https://github.com/hunspell/hunspell/commit/be3b8d945a25
https://github.com/hunspell/hunspell/commit/dd3a71c38b61

--- externals/hunspell/affentry.hxx.orig	2015-05-10 16:46:22 UTC
+++ externals/hunspell/affentry.hxx
@@ -27,7 +27,7 @@ class LIBHUNSPELL_DLL_EXPORTED PfxEntry : protected Af
   struct hentry *      checkword(const char * word, int len, char in_compound, 
                             const FLAG needflag = FLAG_NULL);
 
-  struct hentry *      check_twosfx(const char * word, int len, char in_compound, const FLAG needflag = NULL);
+  struct hentry *      check_twosfx(const char * word, int len, char in_compound, const FLAG needflag = FLAG_NULL);
 
   char *      check_morph(const char * word, int len, char in_compound,
                             const FLAG needflag = FLAG_NULL);
@@ -87,10 +87,9 @@ class LIBHUNSPELL_DLL_EXPORTED SfxEntry : protected Af
   inline bool          allowCross() { return ((opts & aeXPRODUCT) != 0); }
   struct hentry *   checkword(const char * word, int len, int optflags, 
                     PfxEntry* ppfx, char ** wlst, int maxSug, int * ns,
-//                    const FLAG cclass = FLAG_NULL, const FLAG needflag = FLAG_NULL, char in_compound=IN_CPD_NOT);
-                    const FLAG cclass = FLAG_NULL, const FLAG needflag = FLAG_NULL, const FLAG badflag = 0);
+                    const FLAG cclass = FLAG_NULL, const FLAG needflag = FLAG_NULL, const FLAG badflag = FLAG_NULL);
 
-  struct hentry *   check_twosfx(const char * word, int len, int optflags, PfxEntry* ppfx, const FLAG needflag = NULL);
+  struct hentry *   check_twosfx(const char * word, int len, int optflags, PfxEntry* ppfx, const FLAG needflag = FLAG_NULL);
 
   char *      check_twosfx_morph(const char * word, int len, int optflags,
                  PfxEntry* ppfx, const FLAG needflag = FLAG_NULL);
