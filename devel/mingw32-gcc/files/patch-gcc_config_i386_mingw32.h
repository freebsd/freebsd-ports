--- gcc/config/i386/mingw32.h.orig	2018-07-10 04:38:04 UTC
+++ gcc/config/i386/mingw32.h
@@ -137,7 +137,7 @@ along with GCC; see the file COPYING3.  
 #undef REAL_LIBGCC_SPEC
 #define REAL_LIBGCC_SPEC \
   "%{mthreads:-lmingwthrd} -lmingw32 \
-   "SHARED_LIBGCC_SPEC" \
+   " SHARED_LIBGCC_SPEC " \
    -lmoldname -lmingwex -lmsvcrt"
 
 #undef STARTFILE_SPEC
