Index: dlls/ntdll/tape.c
===================================================================
RCS file: /home/wine/wine/dlls/ntdll/tape.c,v
retrieving revision 1.3
diff -u -3 -p -r1.3 tape.c
--- tape.c	31 Jan 2006 12:08:47 -0000	1.3
+++ tape.c	3 Feb 2006 17:30:28 -0000
@@ -34,6 +34,10 @@
 #if !defined(MTCOMPRESSION) && defined(MTCOMP)
 #define MTCOMPRESSION MTCOMP
 #endif
+/* FreeBSD, for example, has MTSETBSIZ instead of MTSETBLK. */
+#if !defined(MTSETBLK) && defined(MTSETBSIZ)
+#define MTSETBLK MTSETBSIZ
+#endif
 
 #define NONAMELESSUNION
 #define NONAMELESSSTRUCT
@@ -177,7 +181,11 @@ static NTSTATUS TAPE_GetDriveParams( int
     data->Compression = FALSE;
     data->DataPadding = FALSE;
     data->ReportSetmarks = FALSE;
+#ifdef __FreeBSD__
+    data->DefaultBlockSize = get.mt_blksiz;
+#else
     data->DefaultBlockSize = get.mt_dsreg & MT_ST_BLKSIZE_MASK;
+#endif
     data->MaximumBlockSize = data->DefaultBlockSize;
     data->MinimumBlockSize = data->DefaultBlockSize;
     data->MaximumPartitionCount = 1;
@@ -208,9 +216,17 @@ static NTSTATUS TAPE_GetMediaParams( int
 
     data->Capacity.u.LowPart = 1024 * 1024 * 1024;
     data->Remaining.u.LowPart = 1024 * 1024 * 1024;
+#ifdef __FreeBSD__
+    data->BlockSize = get.mt_blksiz;
+#else
     data->BlockSize = get.mt_dsreg & MT_ST_BLKSIZE_MASK;
+#endif
     data->PartitionCount = 1;
+#ifdef __FreeBSD__
+    data->WriteProtected = 0;
+#else
     data->WriteProtected = GMT_WR_PROT(get.mt_gstat);
+#endif
 
     return status;
 #else
@@ -226,7 +242,9 @@ static NTSTATUS TAPE_GetPosition( int fd
 {
 #ifdef HAVE_SYS_MTIO_H
     struct mtget get;
+#ifndef __FreeBSD__
     struct mtpos pos;
+#endif
     NTSTATUS status;
 
     TRACE( "fd: %d type: 0x%08lx\n", fd, type );
@@ -237,16 +255,22 @@ static NTSTATUS TAPE_GetPosition( int fd
     if (status != STATUS_SUCCESS)
         return status;
 
+#ifndef __FreeBSD__
     status = TAPE_GetStatus( ioctl( fd, MTIOCPOS, &pos ) );
     if (status != STATUS_SUCCESS)
         return status;
+#endif
 
     switch (type)
     {
     case TAPE_ABSOLUTE_BLOCK:
         data->Type = type;
         data->Partition = get.mt_resid;
+#ifndef __FreeBSD__
         data->OffsetLow = pos.mt_blkno;
+#else
+        data->OffsetLow = get.mt_blkno;
+#endif
         break;
     case TAPE_LOGICAL_BLOCK:
     case TAPE_PSEUDO_LOGICAL_BLOCK:
