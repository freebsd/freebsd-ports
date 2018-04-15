Avoid looking for pthread by simply asserting that it is there.
Otherwise openmp can't be found because the pthread library
lives in /usr/lib and CMake 3.11 doesn't look there anymore
while looking for openmp. PR 223678.

--- Modules/FindOpenMP.cmake 2018-04-07 20:56:40.059488000 +0000
+++ Modules/FindOpenMP.cmake 2018-04-07 21:48:55.681077000 +0000
@@ -79,6 +79,8 @@
 cmake_policy(SET CMP0054 NEW) # if() quoted variables not dereferenced
 cmake_policy(SET CMP0057 NEW) # if IN_LIST
 
+set(OpenMP_pthread_LIBRARY -lpthread)
+
 function(_OPENMP_FLAG_CANDIDATES LANG)
   message(STATUS "FindOpenMP: flag-candidates ${LANG}")
   if(NOT OpenMP_${LANG}_FLAG)
