*** lib/database/include/machine.h.orig	Mon Aug 18 18:36:50 2003
--- lib/database/include/machine.h	Mon Aug 18 18:48:17 2003
***************
*** 152,157 ****
--- 152,169 ----
  
  
  /*
+  * Alpha under FreeBSD
+  */
+ 
+ #if __alpha__ && __FreeBSD__
+ 
+ #define MACHINE_WORD_FORMAT	DGL_LITTLE_ENDIAN
+ #define MACHINE_FLOAT_FORMAT	DGL_NON_IEEE
+ 
+ #endif /* __alpha__ && __FreeBSD__ */
+ 
+ 
+ /*
   * Apple Darwin (Mac OS X) machine dependent setup
   */
  
