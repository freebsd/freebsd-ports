*** gcc/config/fp-bit.h.orig	Thu Oct 18 22:57:05 2001
--- gcc/config/fp-bit.h	Thu Oct 18 22:58:46 2001
***************
*** 164,169 ****
--- 164,170 ----
  #		define divide 		fpdiv
  #		define compare 		fpcmp
  #		define si_to_float 	sitofp
+ #		define usi_to_float	uitofp
  #		define float_to_si 	fptosi
  #		define float_to_usi 	fptoui
  #		define negate 		__negsf2
***************
*** 176,181 ****
--- 177,183 ----
  #		define divide 		dpdiv
  #		define compare 		dpcmp
  #		define si_to_float 	litodp
+ #		define usi_to_float	ultodp
  #		define float_to_si 	dptoli
  #		define float_to_usi 	dptoul
  #		define negate 		__negdf2
