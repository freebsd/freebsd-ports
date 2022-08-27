Obtained from:	https://github.com/Cyan4973/xxHash/commit/6189ecd3d44a693460f86280ccf49d33cb4b18e1

--- xxhash.h.orig	2022-08-13 18:58:45.930785000 +0200
+++ xxhash.h	2022-08-13 18:59:08.416809000 +0200
@@ -1546,8 +1546,7 @@
 /* note: use after variable declarations */
 #ifndef XXH_STATIC_ASSERT
 #  if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L)    /* C11 */
-#    include <assert.h>
-#    define XXH_STATIC_ASSERT_WITH_MESSAGE(c,m) do { static_assert((c),m); } while(0)
+#    define XXH_STATIC_ASSERT_WITH_MESSAGE(c,m) do { _Static_assert((c),m); } while(0)
 #  elif defined(__cplusplus) && (__cplusplus >= 201103L)            /* C++11 */
 #    define XXH_STATIC_ASSERT_WITH_MESSAGE(c,m) do { static_assert((c),m); } while(0)
 #  else
