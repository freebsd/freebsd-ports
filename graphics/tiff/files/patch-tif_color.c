*** libtiff/tif_color.c.ref	Fri Nov  5 18:01:44 2004
--- libtiff/tif_color.c	Fri Nov  5 18:26:46 2004
***************
*** 170,176 ****
  #define	SHIFT			16
  #define	FIX(x)			((int32)((x) * (1L<<SHIFT) + 0.5))
  #define	ONE_HALF		((int32)(1<<(SHIFT-1)))
! #define	Code2V(c, RB, RW, CR)	((((c)-(int32)(RB))*(float)(CR))/(float)((RW)-(RB)))
  #define	CLAMP(f,min,max)	((f)<(min)?(min):(f)>(max)?(max):(f))
  
  void
--- 170,176 ----
  #define	SHIFT			16
  #define	FIX(x)			((int32)((x) * (1L<<SHIFT) + 0.5))
  #define	ONE_HALF		((int32)(1<<(SHIFT-1)))
! #define	Code2V(c, RB, RW, CR)	((((c)-(int32)(RB))*(float)(CR))/(float)(((RW)-(RB)) ? ((RW)-(RB)) : 1))
  #define	CLAMP(f,min,max)	((f)<(min)?(min):(f)>(max)?(max):(f))
  
  void
***************
*** 243,252 ****
         * constructing tables indexed by the raw pixel data.
         */
        for (i = 0, x = -128; i < 256; i++, x++) {
! 	    int32 Cr = (int32)Code2V(x, refBlackWhite[4] - 128.0F,
! 			    refBlackWhite[5] - 128.0F, 127);
! 	    int32 Cb = (int32)Code2V(x, refBlackWhite[2] - 128.0F,
! 			    refBlackWhite[3] - 128.0F, 127);
  
  	    ycbcr->Cr_r_tab[i] = (int32)((D1*Cr + ONE_HALF)>>SHIFT);
  	    ycbcr->Cb_b_tab[i] = (int32)((D3*Cb + ONE_HALF)>>SHIFT);
--- 243,252 ----
         * constructing tables indexed by the raw pixel data.
         */
        for (i = 0, x = -128; i < 256; i++, x++) {
! 	    int32 Cr = ((int32)Code2V(x, refBlackWhite[4] - 128.0F,
! 			    refBlackWhite[5] - 128.0F, 255)) - 128;
! 	    int32 Cb = ((int32)Code2V(x, refBlackWhite[2] - 128.0F,
! 			    refBlackWhite[3] - 128.0F, 255)) - 128;
  
  	    ycbcr->Cr_r_tab[i] = (int32)((D1*Cr + ONE_HALF)>>SHIFT);
  	    ycbcr->Cb_b_tab[i] = (int32)((D3*Cb + ONE_HALF)>>SHIFT);

