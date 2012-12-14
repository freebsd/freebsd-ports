--- cmn/streams.h.orig	2012-05-27 06:52:31.000000000 +0900
+++ cmn/streams.h	2012-05-27 06:53:11.000000000 +0900
@@ -97,7 +97,7 @@
 public:
   OutStream(Boolean ownSock) : GenericStream(ownSock) {}
 
-  virtual Boolean write(void *buf,int size) = 0;
+  virtual Boolean write(const void *buf,int size) = 0;
   /* EFFECTS: Write size number of bytes into buf.  Return True if
      successful. */
 
@@ -171,7 +171,7 @@
 
   virtual Boolean alive();
   
-  virtual Boolean write(void *buf,int size);
+  virtual Boolean write(const void *buf,int size);
 
   virtual void write_char(u_char);
 
@@ -253,7 +253,7 @@
 
   virtual void done_packet();
 
-  virtual Boolean write(void *buf,int size);
+  virtual Boolean write(const void *buf,int size);
 
   void flush();
 
