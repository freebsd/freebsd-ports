--- test/eh/gcc-freebsd.mak.orig	Sat May 26 05:06:16 2001
+++ test/eh/gcc-freebsd.mak	Fri Jun  7 11:25:25 2002
@@ -34,20 +34,17 @@
 D_TEST = ./eh_test_d.out
 NOSGI_TEST = ./eh_test_nosgi.out
 
-CC = c++ -pthread
-CXX = $(CC)
-
 # dwa 12/22/99 -- had to turn off -ansi flag so we could use SGI IOSTREAMS
 # also, test_slist won't compile with -O3/-O2 when targeting PPC. It fails 
 # in the assembler with 'invalid relocation type'
-CXXFLAGS = -Wall -g -O ${STL_INCL} -I. ${CXX_EXTRA_FLAGS} -DEH_VECTOR_OPERATOR_NEW
+CXXFLAGS= $(PTHREAD_CFLAGS) -D_REENTRANT -Wall -g -O ${STL_INCL} -I. ${CXX_EXTRA_FLAGS} -DEH_VECTOR_OPERATOR_NEW -DEH_DELETE_HAS_THROW_SPEC
 
-D_CXXFLAGS = -Wall -g -O ${STL_INCL} -I. ${CXX_EXTRA_FLAGS} -DEH_VECTOR_OPERATOR_NEW -D_STLP_DEBUG -D_STLP_USE_STATIC_LIB
-NOSGI_CXXFLAGS = -Wall -g -O2 ${STL_INCL} -I. ${CXX_EXTRA_FLAGS} -D_STLP_NO_OWN_IOSTREAMS -D_STLP_DEBUG_UNINITIALIZED -DEH_VECTOR_OPERATOR_NEW
+D_CXXFLAGS = $(PTHREAD_CFLAGS) -D_REENTRANT -Wall -g -O ${STL_INCL} -I. ${CXX_EXTRA_FLAGS} -DEH_VECTOR_OPERATOR_NEW -DEH_DELETE_HAS_THROW_SPEC -D_STLP_DEBUG -D_STLP_USE_STATIC_LIB
+NOSGI_CXXFLAGS = $(PTHREAD_CFLAGS) -D_REENTRANT -Wall -g -O2 ${STL_INCL} -I. ${CXX_EXTRA_FLAGS} -D_STLP_NO_OWN_IOSTREAMS -D_STLP_DEBUG_UNINITIALIZED -DEH_VECTOR_OPERATOR_NEW -DEH_DELETE_HAS_THROW_SPEC
 
 check: $(TEST)
 
-LIBS = -lm 
+LIBS = -lm $(PTHREAD_LIBS)
 D_LIBSTLPORT = -L../../lib -lstlport_gcc_stldebug
 LIBSTLPORT = -L../../lib -lstlport_gcc
 
