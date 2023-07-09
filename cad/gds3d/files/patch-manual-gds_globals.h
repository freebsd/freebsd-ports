- workaround for error: reference to 'byte' is ambiguous, see https://github.com/trilomix/GDS3D/issues/23

--- ../libgdsto3d/gds_globals.h.orig	2023-07-09 01:42:32.116154000 -0700
+++ ../libgdsto3d/gds_globals.h	2023-07-09 01:42:59.001193000 -0700
@@ -116,9 +116,9 @@
 
 typedef struct gds_header{
 	short RecordLength;
-	byte RecordType;
-	byte DataType;
-	byte *Data;
+	::byte RecordType;
+	::byte DataType;
+	::byte *Data;
 }gds_header;
 
 /* A word consists of 16 bits, numbered from 0 to 15, left to right. */
