*** ./src/VBox/Runtime/r0drv/freebsd/thread-r0drv-freebsd.c~	Wed Dec  1 12:09:43 2010
--- ./src/VBox/Runtime/r0drv/freebsd/thread-r0drv-freebsd.c	Wed Feb  9 13:44:28 2011
***************
*** 101,107 ****
--- 101,111 ----
  
  RTDECL(bool) RTThreadYield(void)
  {
+ #if (__FreeBSD_version >= 900032)
+     kern_yield(curthread->td_user_pri);
+ #else
      uio_yield();
+ #endif
      return false; /** @todo figure this one ... */
  }
  
