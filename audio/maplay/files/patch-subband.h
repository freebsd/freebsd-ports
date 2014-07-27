*** subband.h.orig	Thu Jun 23 21:14:40 1994
--- subband.h	Thu Dec  9 05:45:45 1999
***************
*** 35,42 ****
  public:
    virtual void read_allocation (Ibitstream *, Header *, Crc16 *) = 0;
    virtual void read_scalefactor (Ibitstream *, Header *) = 0;
!   virtual bool read_sampledata (Ibitstream *) = 0;
!   virtual bool put_next_sample (e_channels, SynthesisFilter *, SynthesisFilter *) = 0;
  };
  
  #endif
--- 35,42 ----
  public:
    virtual void read_allocation (Ibitstream *, Header *, Crc16 *) = 0;
    virtual void read_scalefactor (Ibitstream *, Header *) = 0;
!   virtual boolean read_sampledata (Ibitstream *) = 0;
!   virtual boolean put_next_sample (e_channels, SynthesisFilter *, SynthesisFilter *) = 0;
  };
  
  #endif
