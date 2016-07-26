--- header.h.orig	1994-06-23 12:14:40 UTC
+++ header.h
@@ -39,7 +39,7 @@ class Header
   e_mode		h_mode;
   e_sample_frequency	h_sample_frequency;
   uint32		h_number_of_subbands, h_intensity_stereo_bound;
-  bool			h_copyright, h_original;
+  boolean			h_copyright, h_original;
   Crc16			*crc;
   uint16		checksum;
 
@@ -48,7 +48,7 @@ class Header
 public:
 			Header (void) { crc = (Crc16 *)0; }
 		       ~Header (void) { if (crc) delete crc; }
-  bool			read_header (Ibitstream *, Crc16 **);
+  boolean			read_header (Ibitstream *, Crc16 **);
 			// read a 32-bit header from the bitstream
 
   // functions to query header contents:
@@ -58,11 +58,11 @@ public:
   uint32		frequency (void) { return frequencies[h_sample_frequency]; }
   static uint32	frequency (e_sample_frequency rate) { return frequencies[rate]; }
   e_mode		mode (void) { return h_mode; };
-  bool			checksums (void) { return !h_protection_bit; }
-  bool			copyright (void) { return h_copyright; }
-  bool			original (void) { return h_original; }
+  boolean			checksums (void) { return !h_protection_bit; }
+  boolean			copyright (void) { return h_copyright; }
+  boolean			original (void) { return h_original; }
 
-  bool			checksum_ok (void) { return checksum == crc->checksum (); }
+  boolean			checksum_ok (void) { return checksum == crc->checksum (); }
 			// compares computed checksum with stream checksum
 
   // functions which return header informations as strings:
