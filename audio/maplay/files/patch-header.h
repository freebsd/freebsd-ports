*** header.h.orig	Thu Jun 23 21:14:40 1994
--- header.h	Thu Dec  9 05:45:44 1999
***************
*** 39,45 ****
    e_mode		h_mode;
    e_sample_frequency	h_sample_frequency;
    uint32		h_number_of_subbands, h_intensity_stereo_bound;
!   bool			h_copyright, h_original;
    Crc16			*crc;
    uint16		checksum;
  
--- 39,45 ----
    e_mode		h_mode;
    e_sample_frequency	h_sample_frequency;
    uint32		h_number_of_subbands, h_intensity_stereo_bound;
!   boolean			h_copyright, h_original;
    Crc16			*crc;
    uint16		checksum;
  
***************
*** 48,54 ****
  public:
  			Header (void) { crc = (Crc16 *)0; }
  		       ~Header (void) { if (crc) delete crc; }
!   bool			read_header (Ibitstream *, Crc16 **);
  			// read a 32-bit header from the bitstream
  
    // functions to query header contents:
--- 48,54 ----
  public:
  			Header (void) { crc = (Crc16 *)0; }
  		       ~Header (void) { if (crc) delete crc; }
!   boolean			read_header (Ibitstream *, Crc16 **);
  			// read a 32-bit header from the bitstream
  
    // functions to query header contents:
***************
*** 58,68 ****
    uint32		frequency (void) { return frequencies[h_sample_frequency]; }
    static uint32	frequency (e_sample_frequency rate) { return frequencies[rate]; }
    e_mode		mode (void) { return h_mode; };
!   bool			checksums (void) { return !h_protection_bit; }
!   bool			copyright (void) { return h_copyright; }
!   bool			original (void) { return h_original; }
  
!   bool			checksum_ok (void) { return checksum == crc->checksum (); }
  			// compares computed checksum with stream checksum
  
    // functions which return header informations as strings:
--- 58,68 ----
    uint32		frequency (void) { return frequencies[h_sample_frequency]; }
    static uint32	frequency (e_sample_frequency rate) { return frequencies[rate]; }
    e_mode		mode (void) { return h_mode; };
!   boolean			checksums (void) { return !h_protection_bit; }
!   boolean			copyright (void) { return h_copyright; }
!   boolean			original (void) { return h_original; }
  
!   boolean			checksum_ok (void) { return checksum == crc->checksum (); }
  			// compares computed checksum with stream checksum
  
    // functions which return header informations as strings:
