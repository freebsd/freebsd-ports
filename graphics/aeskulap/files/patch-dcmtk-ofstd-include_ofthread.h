--- dcmtk/ofstd/include/ofthread.h.orig	2010-08-23 16:28:30.000000000 +0200
+++ dcmtk/ofstd/include/ofthread.h	2010-08-23 16:33:06.000000000 +0200
@@ -118,14 +118,14 @@
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
@@ -158,7 +158,7 @@
    *  provided in this class.
    *  @return thread ID of the calling thread.
    */
-  static unsigned long self();
+  static pthread_t self();
 
 private:
 
@@ -177,7 +177,7 @@
 #endif
 
   /** thread identifier */
-  unsigned long theThread;
+  pthread_t theThread;
 
   /** unimplemented private copy constructor */
   OFThread(const OFThread& arg);
