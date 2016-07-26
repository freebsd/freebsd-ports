--- src/recording/encodermp3.cpp.orig	2013-05-08 23:20:26 UTC
+++ src/recording/encodermp3.cpp
@@ -85,7 +85,7 @@ EncoderMp3::EncoderMp3(EngineAbstractRec
      */
     QStringList libnames;
     QString libname = "";
-#ifdef __LINUX__
+#if defined(__BSD__) || defined(__LINUX__)
        libnames << "mp3lame";
 #elif __WINDOWS__
     libnames << "lame_enc.dll";
@@ -108,7 +108,7 @@ EncoderMp3::EncoderMp3(EngineAbstractRec
         props->setType(DLG_WARNING);
         props->setTitle(tr("Encoder"));
         QString key = "";
-#ifdef __LINUX__
+#if defined(__BSD__) || defined(__LINUX__)
         key = tr("<html>Mixxx cannot record or stream in MP3 without the MP3 encoder &quot;lame&quot;. Due to licensing issues, we cannot include this with Mixxx. To record or stream in MP3, you must download <b>libmp3lame</b> and install it on your system. <p>See <a href='http://mixxx.org/wiki/doku.php/internet_broadcasting#linux'>Mixxx Wiki</a> for more information. </html>");
         props->setText(key);
 #elif __WINDOWS__
