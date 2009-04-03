--- src/libxorsa/xorsa_download.cc.orig	2004-12-30 14:21:29.000000000 +0900
+++ src/libxorsa/xorsa_download.cc	2009-04-02 13:48:37.000000000 +0900
@@ -221,6 +221,21 @@
   
 }
 
+void XOrsaDownloadEntry::secure_download(const QUrlInfo &urlInfo)
+{
+  QUrl proto_url(le->text());
+  // download file if it appears in the file listing
+  if (proto_url.fileName() == urlInfo.name()) {
+    // abort the current QFtp::List and QFtp::Close commands
+    ftp->abort();
+    
+    if (urlInfo.isFile() && urlInfo.isReadable())
+      ftp->get(proto_url.fileName(),file);
+    
+    ftp->close();
+  }
+}
+
 void XOrsaDownloadEntry::download() {
   QUrl proto_url(le->text());
   ftp = 0;
@@ -235,7 +250,7 @@
     ftp->login("anonymous","orsa_user@orsa.sf.net");
     ftp->cd(proto_url.dirPath());
     //
-    ftp->get(proto_url.fileName(),file);
+    ftp->list();
     // WARNING: don't close the file HERE!!
     //
     ftp->close();
@@ -246,6 +261,8 @@
     
     connect(ftp,SIGNAL(done(bool)),this,SLOT(post_download(bool)));
     
+    connect(ftp,SIGNAL(listInfo(const QUrlInfo &)),this,SLOT(secure_download(const QUrlInfo &)));
+    
   } else if (proto_url.protocol() == "http") {
     
     http = new QHttp;
