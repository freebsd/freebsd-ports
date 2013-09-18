--- dcmtk/ofstd/include/ofthread.h.orig	2006-03-08 10:25:25.000000000 +0100
+++ dcmtk/ofstd/include/ofthread.h	2013-09-18 17:55:34.000000000 +0200
@@ -38,6 +38,7 @@
 #ifndef OFTHREAD_H
 #define OFTHREAD_H
 
+#include <pthread.h>
 #include "osconfig.h"
 #include "oftypes.h"  /* for class OFBool */
 #include "ofstring.h" /* for class OFString */
@@ -118,14 +119,14 @@
    *  provided in this class.
    *  @return thread ID of target thread if started, 0 otherwise.
    */
-  unsigned long threadID();
+  pthread_t threadID();
 
   /** checks if the given thread ID matches the thread ID of the thread
    *  referenced by this object.
    *  @param tID thread ID to be compared
    *  @return OFTrue if equal, OFFalse otherwise.
    */
-  OFBool equal(unsigned long tID);
+  OFBool equal(pthread_t tID);
 
   /** converts any of the error codes returned by the methods of this class
    *  into a textual description, which is written into the string object.
@@ -158,7 +159,7 @@
    *  provided in this class.
    *  @return thread ID of the calling thread.
    */
-  static unsigned long self();
+  static pthread_t self();
 
 private:
 
@@ -177,7 +178,7 @@
 #endif
 
   /** thread identifier */
-  unsigned long theThread;
+  pthread_t theThread;
 
   /** unimplemented private copy constructor */
   OFThread(const OFThread& arg);
