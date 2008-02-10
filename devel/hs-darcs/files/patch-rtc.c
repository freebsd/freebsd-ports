--- rts.c.orig 2007-10-26 09:32:02.000000000 +0200
+++ rts.c      2007-10-26 09:28:14.000000000 +0200
@@ -6,7 +6,7 @@
 void defaultsHook (void) {  
   RtsFlags.GcFlags.maxStkSize  =  8*1000002 / sizeof(W_); /* 8M */

-#ifdef _SC_PHYS_PAGES
+#if defined(_SC_PHYS_PAGES) && defined(_SC_AVPHYS_PAGES)
   /* Try to set reasonable values for when to start compacting the heap to
      avoid massive swapping. */
  {
