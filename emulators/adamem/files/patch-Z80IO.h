--- Z80IO.h.orig	1999-02-14 19:45:30 UTC
+++ Z80IO.h
@@ -11,9 +11,8 @@
 /****************************************************************************/
 
 #define INLINE_OP                     /* Inline Z80_RDOP()                  */
-#define INLINE_MEM                    /* Inline Z80_RDMEM() and Z80_WRMEM() */
 
-#ifdef __GNUC__
+#if defined(__GNUC__) && (defined(__amd64__) || defined(__i386__))
 #define FASTCALL        __attribute__ ((regparm(3)))
 #ifdef INLINE_MEM
 #define INLINE_MEM_GNU
@@ -36,11 +35,11 @@ void Z80_Out (unsigned Port,byte Value) FASTCALL;
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
