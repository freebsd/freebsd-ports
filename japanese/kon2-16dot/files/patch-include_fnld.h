 --- include/fnld.h	30 Sep 2008 08:02:59 -0000	1.1.1.1
 +++ include/fnld.h	23 Oct 2008 09:24:33 -0000
 @@ -51,6 +51,10 @@
  #define	FR_ATTACH	1
  #define	FR_PROXY	2
  
 +#if defined(__FreeBSD__)
 +#define	ftok(p, n) (5000 + ((n) & 0x7F))
 +#endif
 +
  extern struct fontRegs fSRegs[], fDRegs[];
  extern struct fontRegs *sbFReg, *dbFReg;
  
