commit 8c64e00460a173141d69624cb36fca19801405b4
Author: Raphael Kubo da Costa <rakuco@FreeBSD.org>
Date:   Sun May 4 23:33:29 2014 +0300

    Stop needlessly calling KDirWatch::stopScan().
    
    Not only should the call be unnecessary, but it also causes an infinite
    loop when KDirWatch is set to use QFileSystemWatcher: the
    KDirWatch::stopScan()/addDir()/startScan() combination makes the slot
    where they're called end up being infinitely triggered.
    
    Discussed with dfaure.
    
    REVIEW:		117993

--- grantleetheme/grantleethememanager.cpp
+++ grantleetheme/grantleethememanager.cpp
@@ -95,7 +95,6 @@ public:
     void updateThemesPath()
     {
         if ( !themesDirectories.isEmpty() ) {
-            watch->stopScan();
             Q_FOREACH (const QString &directory, themesDirectories) {
                 watch->removeDir( directory );
             }
