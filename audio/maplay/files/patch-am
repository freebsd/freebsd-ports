*** subband_layer_1.h.orig	Thu Jun 23 21:14:40 1994
--- subband_layer_1.h	Thu Dec  9 05:32:19 1999
***************
*** 42,49 ****
         SubbandLayer1 (uint32 subbandnumber);
    void read_allocation (Ibitstream *, Header *, Crc16 *);
    void read_scalefactor (Ibitstream *, Header *);
!   bool read_sampledata (Ibitstream *);
!   bool put_next_sample (e_channels, SynthesisFilter *, SynthesisFilter *);
  };
  
  
--- 42,49 ----
         SubbandLayer1 (uint32 subbandnumber);
    void read_allocation (Ibitstream *, Header *, Crc16 *);
    void read_scalefactor (Ibitstream *, Header *);
!   boolean read_sampledata (Ibitstream *);
!   boolean put_next_sample (e_channels, SynthesisFilter *, SynthesisFilter *);
  };
  
  
***************
*** 60,70 ****
      SubbandLayer1::read_allocation (stream, header, crc);
    }
    void read_scalefactor (Ibitstream *, Header *);
!   bool read_sampledata (Ibitstream *stream)
    {
      return SubbandLayer1::read_sampledata (stream);
    }
!   bool put_next_sample (e_channels, SynthesisFilter *, SynthesisFilter *);
  };
  
  
--- 60,70 ----
      SubbandLayer1::read_allocation (stream, header, crc);
    }
    void read_scalefactor (Ibitstream *, Header *);
!   boolean read_sampledata (Ibitstream *stream)
    {
      return SubbandLayer1::read_sampledata (stream);
    }
!   boolean put_next_sample (e_channels, SynthesisFilter *, SynthesisFilter *);
  };
  
  
***************
*** 82,89 ****
         SubbandLayer1Stereo (uint32 subbandnumber);
    void read_allocation (Ibitstream *, Header *, Crc16 *);
    void read_scalefactor (Ibitstream *, Header *);
!   bool read_sampledata (Ibitstream *);
!   bool put_next_sample (e_channels, SynthesisFilter *, SynthesisFilter *);
  };
  
  #endif
--- 82,89 ----
         SubbandLayer1Stereo (uint32 subbandnumber);
    void read_allocation (Ibitstream *, Header *, Crc16 *);
    void read_scalefactor (Ibitstream *, Header *);
!   boolean read_sampledata (Ibitstream *);
!   boolean put_next_sample (e_channels, SynthesisFilter *, SynthesisFilter *);
  };
  
  #endif
