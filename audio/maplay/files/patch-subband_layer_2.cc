*** subband_layer_2.cc.orig	Thu Jun 23 21:14:36 1994
--- subband_layer_2.cc	Thu Dec  9 05:32:19 1999
***************
*** 591,597 ****
  }
  
  
! bool SubbandLayer2::read_sampledata (Ibitstream *stream)
  {
    if (allocation)
      if (groupingtable)
--- 591,597 ----
  }
  
  
! boolean SubbandLayer2::read_sampledata (Ibitstream *stream)
  {
    if (allocation)
      if (groupingtable)
***************
*** 633,639 ****
  }
  
  
! bool SubbandLayer2::put_next_sample (e_channels channels,
  				     SynthesisFilter *filter1, SynthesisFilter *)
  {
  #ifdef DEBUG
--- 633,639 ----
  }
  
  
! boolean SubbandLayer2::put_next_sample (e_channels channels,
  				     SynthesisFilter *filter1, SynthesisFilter *)
  {
  #ifdef DEBUG
***************
*** 726,732 ****
  }
  
  
! bool SubbandLayer2IntensityStereo::put_next_sample (e_channels channels,
  	SynthesisFilter *filter1, SynthesisFilter *filter2)
  {
  #ifdef DEBUG
--- 726,732 ----
  }
  
  
! boolean SubbandLayer2IntensityStereo::put_next_sample (e_channels channels,
  	SynthesisFilter *filter1, SynthesisFilter *filter2)
  {
  #ifdef DEBUG
***************
*** 880,888 ****
  }
  
  
! bool SubbandLayer2Stereo::read_sampledata (Ibitstream *stream)
  {
!   bool returnvalue = SubbandLayer2::read_sampledata (stream);
  
    if (channel2_allocation)
      if (channel2_groupingtable)
--- 880,888 ----
  }
  
  
! boolean SubbandLayer2Stereo::read_sampledata (Ibitstream *stream)
  {
!   boolean returnvalue = SubbandLayer2::read_sampledata (stream);
  
    if (channel2_allocation)
      if (channel2_groupingtable)
***************
*** 919,928 ****
  }
  
  
! bool SubbandLayer2Stereo::put_next_sample (e_channels channels,
  					   SynthesisFilter *filter1, SynthesisFilter *filter2)
  {
!   bool returnvalue = SubbandLayer2::put_next_sample (channels, filter1, filter2);
    if (channel2_allocation && channels != left)
    {
      register real sample = channel2_samples[samplenumber - 1];
--- 919,928 ----
  }
  
  
! boolean SubbandLayer2Stereo::put_next_sample (e_channels channels,
  					   SynthesisFilter *filter1, SynthesisFilter *filter2)
  {
!   boolean returnvalue = SubbandLayer2::put_next_sample (channels, filter1, filter2);
    if (channel2_allocation && channels != left)
    {
      register real sample = channel2_samples[samplenumber - 1];
