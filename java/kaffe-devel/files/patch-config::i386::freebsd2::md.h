 --- config/i386/freebsd2/md.h.orig	Sat Sep  6 01:38:48 2003
 +++ config/i386/freebsd2/md.h	Sat Sep  6 01:38:52 2003
 @@ -39,8 +39,8 @@
  	asm("frstor %0": :"m"(*fdata))
  
  /* Define signal context macros for xprofiling */
 -#define SIGNAL_ARGS(sig, sc) int sig, int __code, struct sigcontext *##sc
 -#define SIGNAL_CONTEXT_POINTER(scp) struct sigcontext *##scp
 +#define SIGNAL_ARGS(sig, sc) int sig, int __code, struct sigcontext *sc
 +#define SIGNAL_CONTEXT_POINTER(scp) struct sigcontext *scp
  #define GET_SIGNAL_CONTEXT_POINTER(sc) (sc)
  #define SIGNAL_PC(scp) (scp)->sc_pc
