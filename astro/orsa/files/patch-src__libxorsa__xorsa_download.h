--- src/libxorsa/xorsa_download.h.orig	2004-12-30 14:21:29.000000000 +0900
+++ src/libxorsa/xorsa_download.h	2009-04-02 13:48:37.000000000 +0900
@@ -91,6 +91,7 @@
   void pb_clicked();  
   void post_download(bool);
   void download();
+  void secure_download(const QUrlInfo &);
 };
 
 
