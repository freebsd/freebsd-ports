--- lib/qfile.hh.orig	Fri Feb 23 21:29:12 2001
+++ lib/qfile.hh	Fri Feb 13 19:17:38 2004
@@ -9,6 +9,7 @@
 # include <sys/stat.h>	// struct stat, fstat
 # include <sys/types.h>	// u_int32_t
 
+using namespace std;
 
 /*!
  * \brief class for mapped files.
