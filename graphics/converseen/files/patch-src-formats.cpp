--- src/formats.cpp.orig	2014-07-08 21:01:12.000000000 +0200
+++ src/formats.cpp	2014-07-08 21:01:34.000000000 +0200
@@ -36,7 +36,6 @@
 
 void Formats::loadFormats()
 {
-#ifdef Q_OS_LINUX
     list<CoderInfo> coderList;
     coderInfoList(&coderList,
                   CoderInfo::TrueMatch,
@@ -91,26 +90,6 @@
 
     s_readableFiltersString = readableFiltersList.join("");
     s_readableFiltersString.prepend(tr("All Supported Filters (%1)").arg(readableExts));
-#else
-    QFile data1(QDir::cleanPath("FileFormats/Readableformats.txt"));
-    if (data1.open(QFile::ReadOnly)) {
-        QTextStream in(&data1);
-
-        s_readableFilters = in.readLine().split(" ");
-        s_readableFiltersString = in.readLine();
-    }
-
-    QFile data2(QDir::cleanPath("FileFormats/WritableFormats.txt"));
-    if (data2.open(QFile::ReadOnly)) {
-        QTextStream in(&data2);
-        QString line;
-        do {
-            line = in.readLine();
-            s_writableFilters << line;
-        } while (!line.isNull());
-    }
-    s_writableFilters.removeLast();
-#endif
 
     s_writableFilters.prepend(tr("Don't change the format"));
 }
