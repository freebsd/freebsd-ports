--- test/eh/gcc-freebsd.mak.orig	Tue Mar  5 08:57:04 2002
+++ test/eh/gcc-freebsd.mak	Tue Mar  5 08:57:34 2002
@@ -40,9 +40,9 @@
 # dwa 12/22/99 -- had to turn off -ansi flag so we could use SGI IOSTREAMS
 # also, test_slist won't compile with -O3/-O2 when targeting PPC. It fails 
 # in the assembler with 'invalid relocation type'
-CXXFLAGS = -Wall -g -O ${STL_INCL} -I. ${CXX_EXTRA_FLAGS} -DEH_VECTOR_OPERATOR_NEW
+CXXFLAGS = -Wall -g ${STL_INCL} -I. ${CXX_EXTRA_FLAGS} -DEH_VECTOR_OPERATOR_NEW
 
-D_CXXFLAGS = -Wall -g -O ${STL_INCL} -I. ${CXX_EXTRA_FLAGS} -DEH_VECTOR_OPERATOR_NEW -D_STLP_DEBUG -D_STLP_USE_STATIC_LIB
+D_CXXFLAGS = -Wall -g ${STL_INCL} -I. ${CXX_EXTRA_FLAGS} -DEH_VECTOR_OPERATOR_NEW -D_STLP_DEBUG -D_STLP_USE_STATIC_LIB
 NOSGI_CXXFLAGS = -Wall -g -O2 ${STL_INCL} -I. ${CXX_EXTRA_FLAGS} -D_STLP_NO_OWN_IOSTREAMS -D_STLP_DEBUG_UNINITIALIZED -DEH_VECTOR_OPERATOR_NEW
 
 check: $(TEST)
