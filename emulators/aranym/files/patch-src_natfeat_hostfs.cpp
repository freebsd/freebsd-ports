- backport of patch to fix https://github.com/aranym/aranym/issues/77

--- src/natfeat/hostfs.cpp.orig	2019-04-14 14:11:29 UTC
+++ src/natfeat/hostfs.cpp
@@ -2872,7 +2872,22 @@ int32 HostFs::xfs_native_init( int16 devnum, memptr mo
 	 * for drivers that are not running under mint,
 	 * report our current timezone (in the filesys.res1 field)
 	 */
+#if defined(__FreeBSD__) || 1
+	/*
+	 * FreeBSD does not have that global variable.
+	 * Maybe others, too.
+	 */
+	{
+		time_t t;
+		int32_t offset;
+		
+		t = time(0);
+		offset = -gmtoff(t);
+		WriteInt32(filesys + 136, offset);
+	}
+#else
 	WriteInt32(filesys + 136, timezone);
+#endif
 
 	int16 dnum = -1;
 	size_t len = strlen( fmountPoint );
