Index: defines.h
===================================================================
RCS file: /src/ruby/defines.h,v
retrieving revision 1.12.2.2
retrieving revision 1.12.2.3
diff -u -r1.12.2.2 -r1.12.2.3
--- defines.h	4 Jan 2002 14:19:47 -0000	1.12.2.2
+++ defines.h	31 Dec 2002 10:30:41 -0000	1.12.2.3
@@ -2,8 +2,8 @@
 
   defines.h -
 
-  $Author: matz $
-  $Date: 2002/01/04 14:19:47 $
+  $Author: knu $
+  $Date: 2002/12/31 10:30:41 $
   created at: Wed May 18 00:21:44 JST 1994
 
 ************************************************/
@@ -52,7 +52,9 @@
 #if defined(sparc) || defined(__sparc__)
 # if defined(linux) || defined(__linux__)
 #define FLUSH_REGISTER_WINDOWS  asm("ta  0x83")
-# else /* Solaris, not sparc linux */
+# elif defined(__FreeBSD__) && defined(__sparc64__)
+#define FLUSH_REGISTER_WINDOWS  asm volatile("flushw" : :)
+# else /* Solaris, OpenBSD, NetBSD, etc. */
 #define FLUSH_REGISTER_WINDOWS  asm("ta  0x03")
 # endif /* trap always to flush register windows if we are on a Sparc system */
 #else /* Not a sparc, so */
