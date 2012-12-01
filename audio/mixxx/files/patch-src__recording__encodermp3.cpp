--- src/recording/encodermp3.cpp.orig	2012-06-26 05:23:37.000000000 +0900
+++ src/recording/encodermp3.cpp	2012-08-09 09:06:21.000000000 +0900
@@ -85,7 +85,7 @@
      */
     QStringList libnames;
     QString libname = "";
-#ifdef __LINUX__
+#if defined(__BSD__) || defined(__LINUX__)
        libnames << "mp3lame";
 #elif __WINDOWS__
     libnames << "lame_enc.dll";
@@ -108,7 +108,7 @@
         props->setType(DLG_WARNING);
         props->setTitle(tr("Encoder"));
         QString key = "";
-#ifdef __LINUX__
+#if defined(__BSD__) || defined(__LINUX__)
         key = tr("<html>Mixxx cannot record or stream in MP3 without the MP3 encoder &quot;lame&quot;. Due to licensing issues, we cannot include this with Mixxx. To record or stream in MP3, you must download <b>libmp3lame</b> and install it on your system. <p>See <a href='http://mixxx.org/wiki/doku.php/internet_broadcasting#linux'>Mixxx Wiki</a> for more information. </html>");
         props->setText(key);
 #elif __WINDOWS__
