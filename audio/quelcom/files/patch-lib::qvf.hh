--- lib/qvf.hh.orig	Fri Feb 23 21:29:12 2001
+++ lib/qvf.hh	Fri Feb 13 19:17:38 2004
@@ -5,9 +5,10 @@
 # ifndef _qvf_hh_
 # define _qvf_hh_
 
-# include <fstream.h>	// ostream
+# include <fstream>	// ostream
 # include <sys/types.h>
 
+using namespace std;
 
 /*! \class qvf
  * \brief class for value-format pairs.
@@ -89,7 +90,7 @@
     * \param v the value
     * \param f the format
     */
-    void set (unsigned int v, enum format f=SPECIFIC);
+    void set (unsigned int v, enum format f);
 
    /*! \fn void print (ostream *os) 
     * \brief print the vf characteristics on the given output stream
