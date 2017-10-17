--- src/encoder/encodermp3.cpp  2017-09-24 22:09:28.258505000 -0500
+++ src/encoder/encodermp3.cpp  2017-09-24 22:12:09.197474000 -0500
@@ -76,7 +76,7 @@
      */
     QStringList libnames;
     QString libname = "";
-#ifdef __LINUX__
+#if defined(__LINUX__) || defined(__FreeBSD__)
     libnames << "mp3lame";
 #elif __WINDOWS__
     libnames << "lame_enc.dll";
