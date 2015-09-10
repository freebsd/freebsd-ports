--- tempstream/tempstream1.cc.orig	2013-10-01 16:50:32 UTC
+++ tempstream/tempstream1.cc
@@ -7,7 +7,11 @@ TempStream::TempStream(string const &bas
     strcpy(buf + base.length(), "XXXXXX");
     base.copy(buf, string::npos);
 
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+    int fd = mkstemp(buf);
+#else
     int fd = mkostemp(buf, O_RDWR);
+#endif
 
     if (fd == -1)
         throw Exception() << "TempStream: " << errnodescr;
