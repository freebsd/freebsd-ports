--- src/ByteBuffer/SaveOperation.cs.orig	Wed May 11 16:10:19 2005
+++ src/ByteBuffer/SaveOperation.cs	Sat Feb 18 15:41:21 2006
@@ -53,8 +53,8 @@
 		// get info about the device the file will be saved on
 		FileInfo fi=new FileInfo(bb.Filename);
 			
-		Mono.Unix.Statvfs stat=new Mono.Unix.Statvfs();
-		Mono.Unix.Syscall.statvfs(bb.Filename, out stat);
+		Mono.Unix.Native.Statvfs stat=new Mono.Unix.Native.Statvfs();
+		Mono.Unix.Native.Syscall.statvfs(bb.Filename, out stat);
 			
 		long freeSpace=(long)(stat.f_bavail*stat.f_bsize) + fi.Length;
 			
