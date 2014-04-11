Index: Z80IO.h
@@ -11,7 +11,6 @@
 /****************************************************************************/
 
 #define INLINE_OP                     /* Inline Z80_RDOP()                  */
-#define INLINE_MEM                    /* Inline Z80_RDMEM() and Z80_WRMEM() */
 
 #ifdef __GNUC__
 #define FASTCALL        __attribute__ ((regparm(3)))
