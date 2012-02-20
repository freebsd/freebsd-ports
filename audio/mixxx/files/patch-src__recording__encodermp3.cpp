--- src/recording/encodermp3.cpp.orig	2011-12-24 11:53:18.000000000 +0900
+++ src/recording/encodermp3.cpp	2012-01-16 06:10:09.000000000 +0900
@@ -85,7 +85,9 @@
      */
     QStringList libnames;
     QString libname = "";
-#ifdef __LINUX__
+#ifdef __BSD__
+    libnames << "%%LOCALBASE%%/lib/libmp3lame.so";
+#elif __LINUX__
     libnames << "/usr/lib/libmp3lame.so.0";
     libnames << "/usr/lib/libmp3lame.so";
 #elif __WINDOWS__
@@ -109,7 +111,7 @@
         props->setType(DLG_WARNING);
         props->setTitle(tr("Encoder"));
         QString key = "";
-#ifdef __LINUX__
+#if defined(__BSD__) || defined(__LINUX__)
         key = tr("<html>Mixxx cannot record or stream in MP3 without the MP3 encoder &quot;lame&quot;. Due to licensing issues, we cannot include this with Mixxx. To record or stream in MP3, you must download <b>libmp3lame</b> and install it on your system. <p>See <a href='http://mixxx.org/wiki/doku.php/internet_broadcasting#linux'>Mixxx Wiki</a> for more information. </html>");
         props->setText(key);
 #elif __WINDOWS__
