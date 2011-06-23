--- par2fileformat.h.orig	2011-06-23 08:31:37.639455018 +0200
+++ par2fileformat.h	2011-06-23 08:38:29.287362503 +0200
@@ -84,7 +84,7 @@
   PACKET_HEADER         header;
   // Body
   MD5Hash               fileid;     // MD5hash of file_hash_16k, file_length, file_name
-  FILEVERIFICATIONENTRY entries[];
+  FILEVERIFICATIONENTRY entries[0];
 } PACKED;
 
 // The file description packet is used to record the name of the file,
