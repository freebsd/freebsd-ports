--- src/qt/qtbase/src/corelib/io/qstorageinfo_unix.cpp.orig	2015-12-12 12:58:05 UTC
+++ src/qt/qtbase/src/corelib/io/qstorageinfo_unix.cpp
@@ -506,9 +506,15 @@ void QStorageInfoPrivate::retrieveVolume
         valid = true;
         ready = true;
 
+#if defined(Q_OS_FREEBSD)
+	bytesTotal = statfs_buf.f_blocks * statfs_buf.f_bsize;
+	bytesFree = statfs_buf.f_bfree * statfs_buf.f_bsize;
+	bytesAvailable = statfs_buf.f_bavail * statfs_buf.f_bsize;
+#else
         bytesTotal = statfs_buf.f_blocks * statfs_buf.f_frsize;
         bytesFree = statfs_buf.f_bfree * statfs_buf.f_frsize;
         bytesAvailable = statfs_buf.f_bavail * statfs_buf.f_frsize;
+#endif
 #if defined(Q_OS_ANDROID) || defined (Q_OS_BSD4)
 #if defined(_STATFS_F_FLAGS)
         readOnly = (statfs_buf.f_flags & ST_RDONLY) != 0;
