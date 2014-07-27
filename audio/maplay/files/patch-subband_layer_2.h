*** subband_layer_2.h.orig	Thu Jun 23 21:14:40 1994
--- subband_layer_2.h	Thu Dec  9 05:32:19 1999
***************
*** 55,62 ****
    void		read_allocation (Ibitstream *, Header *, Crc16 *);
    virtual void	read_scalefactor_selection (Ibitstream *, Crc16 *);
    void		read_scalefactor (Ibitstream *, Header *);
!   bool		read_sampledata (Ibitstream *);
!   bool		put_next_sample (e_channels, SynthesisFilter *, SynthesisFilter * = NULL);
  };
  
  
--- 55,62 ----
    void		read_allocation (Ibitstream *, Header *, Crc16 *);
    virtual void	read_scalefactor_selection (Ibitstream *, Crc16 *);
    void		read_scalefactor (Ibitstream *, Header *);
!   boolean		read_sampledata (Ibitstream *);
!   boolean		put_next_sample (e_channels, SynthesisFilter *, SynthesisFilter * = NULL);
  };
  
  
***************
*** 75,85 ****
    }
    void read_scalefactor_selection (Ibitstream *, Crc16 *);
    void read_scalefactor (Ibitstream *, Header *);
!   bool read_sampledata (Ibitstream *stream)
    {
      return SubbandLayer2::read_sampledata (stream);
    }
!   bool put_next_sample (e_channels, SynthesisFilter *, SynthesisFilter *);
  };
  
  
--- 75,85 ----
    }
    void read_scalefactor_selection (Ibitstream *, Crc16 *);
    void read_scalefactor (Ibitstream *, Header *);
!   boolean read_sampledata (Ibitstream *stream)
    {
      return SubbandLayer2::read_sampledata (stream);
    }
!   boolean put_next_sample (e_channels, SynthesisFilter *, SynthesisFilter *);
  };
  
  
***************
*** 90,96 ****
    uint32 channel2_allocation;
    uint32 channel2_scfsi;
    real	 channel2_scalefactor1, channel2_scalefactor2, channel2_scalefactor3;
!   bool	 channel2_grouping;
    uint32 channel2_codelength;
    const real *channel2_groupingtable;
    real	 channel2_factor;
--- 90,96 ----
    uint32 channel2_allocation;
    uint32 channel2_scfsi;
    real	 channel2_scalefactor1, channel2_scalefactor2, channel2_scalefactor3;
!   boolean	 channel2_grouping;
    uint32 channel2_codelength;
    const real *channel2_groupingtable;
    real	 channel2_factor;
***************
*** 102,109 ****
    void read_allocation (Ibitstream *, Header *, Crc16 *);
    void read_scalefactor_selection (Ibitstream *, Crc16 *);
    void read_scalefactor (Ibitstream *, Header *);
!   bool read_sampledata (Ibitstream *);
!   bool put_next_sample (e_channels, SynthesisFilter *, SynthesisFilter *);
  };
  
  #endif
--- 102,109 ----
    void read_allocation (Ibitstream *, Header *, Crc16 *);
    void read_scalefactor_selection (Ibitstream *, Crc16 *);
    void read_scalefactor (Ibitstream *, Header *);
!   boolean read_sampledata (Ibitstream *);
!   boolean put_next_sample (e_channels, SynthesisFilter *, SynthesisFilter *);
  };
  
  #endif
