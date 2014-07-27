*** ibitstream.h.orig	Thu Jun 23 21:14:40 1994
--- ibitstream.h	Thu Dec  9 05:32:18 1999
***************
*** 43,52 ****
  		~Ibitstream (void);
    int		filedescriptor (void) { return fd; };
  
!   bool		get_header (uint32 *);
  		// get next 32 bits from bitstream in an unsigned int,
  		// returned value False => end of stream
!   bool		read_frame (uint32 bytesize);
  		// fill buffer with data from bitstream, returned value False => end of stream
    uint32	get_bits (uint32 number_of_bits);
  		// read bits (1 <= number_of_bits <= 16) from buffer into the lower bits
--- 43,52 ----
  		~Ibitstream (void);
    int		filedescriptor (void) { return fd; };
  
!   boolean		get_header (uint32 *);
  		// get next 32 bits from bitstream in an unsigned int,
  		// returned value False => end of stream
!   boolean		read_frame (uint32 bytesize);
  		// fill buffer with data from bitstream, returned value False => end of stream
    uint32	get_bits (uint32 number_of_bits);
  		// read bits (1 <= number_of_bits <= 16) from buffer into the lower bits
