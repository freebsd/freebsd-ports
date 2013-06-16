--- ./qztest/testquagzipfile.cpp.orig	2013-06-15 14:53:18.000000000 +0200
+++ ./qztest/testquagzipfile.cpp	2013-06-15 14:51:57.000000000 +0200
@@ -8,7 +8,7 @@
 {
     QDir curDir;
     curDir.mkpath("tmp");
-    voidp gzFile = gzopen("tmp/test.gz", "wb");
+    gzFile_s* /*voidp*/ gzFile = gzopen("tmp/test.gz", "wb");
     gzwrite(gzFile, "test", 4);
     gzclose(gzFile);
     QuaGzipFile testFile("tmp/test.gz");
@@ -32,7 +32,7 @@
     QCOMPARE(testFile.write("test", 4), static_cast<qint64>(4));
     testFile.close();
     QVERIFY(!testFile.isOpen());
-    voidp gzFile = gzopen("tmp/test.gz", "rb");
+    gzFile_s* /*voidp*/ gzFile = gzopen("tmp/test.gz", "rb");
     char buf[5];
     buf[4] = '\0';
     QCOMPARE(gzread(gzFile, buf, 5), 4);
