--- node_modules/spellchecker/vendor/hunspell/src/hunspell/affentry.hxx.orig	2019-12-27 07:21:39 UTC
+++ node_modules/spellchecker/vendor/hunspell/src/hunspell/affentry.hxx
@@ -24,10 +24,10 @@ class LIBHUNSPELL_DLL_EXPORTED PfxEntry : protected Af
   ~PfxEntry();
 
   inline bool          allowCross() { return ((opts & aeXPRODUCT) != 0); }
-  struct hentry *      checkword(const char * word, int len, char in_compound, 
+  struct hentry *      checkword(const char * word, int len, char in_compound,
                             const FLAG needflag = FLAG_NULL);
 
-  struct hentry *      check_twosfx(const char * word, int len, char in_compound, const FLAG needflag = NULL);
+  struct hentry *      check_twosfx(const char * word, int len, char in_compound, const FLAG needflag = FLAG_NULL);
 
   char *      check_morph(const char * word, int len, char in_compound,
                             const FLAG needflag = FLAG_NULL);
@@ -36,15 +36,15 @@ class LIBHUNSPELL_DLL_EXPORTED PfxEntry : protected Af
                   char in_compound, const FLAG needflag = FLAG_NULL);
 
   inline FLAG getFlag()   { return aflag;   }
-  inline const char *  getKey()    { return appnd;  } 
+  inline const char *  getKey()    { return appnd;  }
   char *               add(const char * word, int len);
 
-  inline short getKeyLen() { return appndl; } 
+  inline short getKeyLen() { return appndl; }
 
-  inline const char *  getMorph()    { return morphcode;  } 
+  inline const char *  getMorph()    { return morphcode;  }
 
-  inline const unsigned short * getCont()    { return contclass;  } 
-  inline short           getContLen()    { return contclasslen;  } 
+  inline const unsigned short * getCont()    { return contclass;  }
+  inline short           getContLen()    { return contclasslen;  }
 
   inline PfxEntry *    getNext()   { return next;   }
   inline PfxEntry *    getNextNE() { return nextne; }
@@ -55,7 +55,7 @@ class LIBHUNSPELL_DLL_EXPORTED PfxEntry : protected Af
   inline void   setNextNE(PfxEntry * ptr) { nextne = ptr; }
   inline void   setNextEQ(PfxEntry * ptr) { nexteq = ptr; }
   inline void   setFlgNxt(PfxEntry * ptr) { flgnxt = ptr; }
-  
+
   inline char * nextchar(char * p);
   inline int    test_condition(const char * st);
 };
@@ -74,7 +74,7 @@ class LIBHUNSPELL_DLL_EXPORTED SfxEntry : protected Af
        SfxEntry *   nexteq;
        SfxEntry *   nextne;
        SfxEntry *   flgnxt;
-           
+
        SfxEntry *   l_morph;
        SfxEntry *   r_morph;
        SfxEntry *   eq_morph;
@@ -85,32 +85,32 @@ class LIBHUNSPELL_DLL_EXPORTED SfxEntry : protected Af
   ~SfxEntry();
 
   inline bool          allowCross() { return ((opts & aeXPRODUCT) != 0); }
-  struct hentry *   checkword(const char * word, int len, int optflags, 
+  struct hentry *   checkword(const char * word, int len, int optflags,
                     PfxEntry* ppfx, char ** wlst, int maxSug, int * ns,
 //                    const FLAG cclass = FLAG_NULL, const FLAG needflag = FLAG_NULL, char in_compound=IN_CPD_NOT);
                     const FLAG cclass = FLAG_NULL, const FLAG needflag = FLAG_NULL, const FLAG badflag = 0);
 
-  struct hentry *   check_twosfx(const char * word, int len, int optflags, PfxEntry* ppfx, const FLAG needflag = NULL);
+  struct hentry *   check_twosfx(const char * word, int len, int optflags, PfxEntry* ppfx, const FLAG needflag = FLAG_NULL);
 
   char *      check_twosfx_morph(const char * word, int len, int optflags,
                  PfxEntry* ppfx, const FLAG needflag = FLAG_NULL);
   struct hentry * get_next_homonym(struct hentry * he);
-  struct hentry * get_next_homonym(struct hentry * word, int optflags, PfxEntry* ppfx, 
+  struct hentry * get_next_homonym(struct hentry * word, int optflags, PfxEntry* ppfx,
     const FLAG cclass, const FLAG needflag);
 
 
   inline FLAG getFlag()   { return aflag;   }
-  inline const char *  getKey()    { return rappnd; } 
+  inline const char *  getKey()    { return rappnd; }
   char *               add(const char * word, int len);
 
 
-  inline const char *  getMorph()    { return morphcode;  } 
+  inline const char *  getMorph()    { return morphcode;  }
 
-  inline const unsigned short * getCont()    { return contclass;  } 
-  inline short           getContLen()    { return contclasslen;  } 
-  inline const char *  getAffix()    { return appnd; } 
+  inline const unsigned short * getCont()    { return contclass;  }
+  inline short           getContLen()    { return contclasslen;  }
+  inline const char *  getAffix()    { return appnd; }
 
-  inline short getKeyLen() { return appndl; } 
+  inline short getKeyLen() { return appndl; }
 
   inline SfxEntry *    getNext()   { return next;   }
   inline SfxEntry *    getNextNE() { return nextne; }
@@ -132,5 +132,3 @@ class LIBHUNSPELL_DLL_EXPORTED SfxEntry : protected Af
 };
 
 #endif
-
-
