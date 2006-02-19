--- src/ByteBuffer/SaveAsOperation.cs.orig	Sun Sep 11 12:22:16 2005
+++ src/ByteBuffer/SaveAsOperation.cs	Sat Feb 18 15:31:08 2006
@@ -63,8 +63,8 @@
 	{
 #if ENABLE_UNIX_SPECIFIC
 		// get info about the device the file will be saved on
-		Mono.Unix.Statvfs stat=new Mono.Unix.Statvfs();
-		Mono.Unix.Syscall.statvfs(Path.GetDirectoryName(fn), out stat);
+		Mono.Unix.Native.Statvfs stat=new Mono.Unix.Native.Statvfs();
+		Mono.Unix.Native.Syscall.statvfs(Path.GetDirectoryName(fn), out stat);
 			
 		long freeSpace=(long)(stat.f_bavail*stat.f_bsize);
 			
