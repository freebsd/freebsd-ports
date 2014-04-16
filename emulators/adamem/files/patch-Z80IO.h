Index: Z80IO.h
@@ -11,7 +11,6 @@
 /****************************************************************************/
 
 #define INLINE_OP                     /* Inline Z80_RDOP()                  */
-#define INLINE_MEM                    /* Inline Z80_RDMEM() and Z80_WRMEM() */
 
 #ifdef __GNUC__
 #define FASTCALL        __attribute__ ((regparm(3)))
@@ -36,11 +35,11 @@
  /***************************************************************************/
  /* Read a byte from given memory location                                  */
  /***************************************************************************/
- unsigned Z80_RDMEM(dword a) FASTCALL;
+ unsigned Z80_RDMEM(dword a);
  /***************************************************************************/
  /* Write a byte to given memory location                                   */
  /***************************************************************************/
- void Z80_WRMEM(dword a,byte v) FASTCALL;
+ void Z80_WRMEM(dword a,byte v);
 #else
  extern byte *AddrTabl[256];
  extern byte *WriteAddrTabl[256];
