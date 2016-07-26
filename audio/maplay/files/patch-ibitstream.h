--- ibitstream.h.orig	1994-06-23 12:14:40 UTC
+++ ibitstream.h
@@ -43,10 +43,10 @@ public:
 		~Ibitstream (void);
   int		filedescriptor (void) { return fd; };
 
-  bool		get_header (uint32 *);
+  boolean		get_header (uint32 *);
 		// get next 32 bits from bitstream in an unsigned int,
 		// returned value False => end of stream
-  bool		read_frame (uint32 bytesize);
+  boolean		read_frame (uint32 bytesize);
 		// fill buffer with data from bitstream, returned value False => end of stream
   uint32	get_bits (uint32 number_of_bits);
 		// read bits (1 <= number_of_bits <= 16) from buffer into the lower bits
