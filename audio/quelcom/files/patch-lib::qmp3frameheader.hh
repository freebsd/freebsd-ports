--- lib/qmp3frameheader.hh.orig	Fri Feb 23 21:29:12 2001
+++ lib/qmp3frameheader.hh	Fri Feb 13 19:17:38 2004
@@ -7,6 +7,9 @@
 
 # include <sys/types.h>
 # include <string>
+# include <iostream>
+
+using namespace std;
 
 /*!
  * \brief class for mp3 frame headers
@@ -39,9 +42,9 @@
         mode_extension:2,	/*!< type of joint stereo coding */
         channel_mode:2;		/*!< mono or which type of stereo */
     };
-        
+
    //! pointer to the header (memory location where it is located)
-    struct header *header;
+  struct header header, *mappedheader;
 
   public:
 
@@ -101,6 +104,12 @@
     qmp3frameheader();
     qmp3frameheader(caddr_t p, u_int32_t bufsize = HEADERSIZE, u_int32_t signature=0);
  
+    // copy and endian-translate the frame header
+    static void copyHeader(struct header *header, caddr_t p);
+    static void copyHeader(caddr_t p, struct header &header);
+
+    void setHeader(caddr_t p);
+
    // direct access to the header
     u_int32_t get();
     void set(u_int32_t h);
