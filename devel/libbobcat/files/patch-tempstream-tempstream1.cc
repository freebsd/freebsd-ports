--- tempstream/tempstream1.cc.orig	2012-05-07 16:35:29.000000000 +0200
+++ tempstream/tempstream1.cc	2012-12-02 00:49:06.000000000 +0100
@@ -7,7 +7,11 @@
     strcpy(buf + base.length(), "XXXXXX");
     base.copy(buf, string::npos);
 
+#ifdef __FreeBSD__
+    int fd = mkstemp(buf);
+#else
     int fd = mkostemp(buf, O_RDWR);
+#endif
 
     if (fd == -1)
         throw Errno("TempStream");
