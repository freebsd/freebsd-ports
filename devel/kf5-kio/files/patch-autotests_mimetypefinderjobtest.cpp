--- autotests/mimetypefinderjobtest.cpp.orig	2021-05-06 17:50:59 UTC
+++ autotests/mimetypefinderjobtest.cpp
@@ -48,6 +48,7 @@ void MimeTypeFinderJobTest::determineMimeType_data()
     QTest::newRow("text_file_no_extension") << "text/plain" << "srcfile";
     QTest::newRow("desktop_file") << "application/x-desktop" << "foo.desktop";
     QTest::newRow("script") << "application/x-shellscript" << "srcfile.sh";
+    QTest::newRow("directory") << "inode/directory" << "srcdir";
     /* clang-format on */
 }
 
@@ -60,12 +61,27 @@ void MimeTypeFinderJobTest::determineMimeType()
     QTemporaryDir tempDir;
     const QString srcDir = tempDir.path();
     const QString srcFile = srcDir + QLatin1Char('/') + fileName;
-    createSrcFile(srcFile);
+    if (mimeType == "inode/directory") {
+        QVERIFY(QDir(srcDir).mkdir(fileName));
+    } else {
+        createSrcFile(srcFile);
+    }
+
     QVERIFY(QFile::exists(srcFile));
     const QUrl url = QUrl::fromLocalFile(srcFile);
 
     // When running a MimeTypeFinderJob
     KIO::MimeTypeFinderJob *job = new KIO::MimeTypeFinderJob(url, this);
+    QVERIFY2(job->exec(), qPrintable(job->errorString()));
+    QCOMPARE(job->mimeType(), mimeType);
+
+    // Check that the result is the same when accessing the source
+    // file through a symbolic link (bug #436708)
+    const QString srcLink = srcDir + QLatin1String("/link_") + fileName;
+    QVERIFY(QFile::link(srcFile, srcLink));
+    const QUrl linkUrl = QUrl::fromLocalFile(srcLink);
+
+    job = new KIO::MimeTypeFinderJob(linkUrl, this);
     QVERIFY2(job->exec(), qPrintable(job->errorString()));
     QCOMPARE(job->mimeType(), mimeType);
 }
