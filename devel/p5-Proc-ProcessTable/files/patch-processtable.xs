$FreeBSD$

--- ProcessTable.xs.orig	Sat May 31 13:05:56 2003
+++ ProcessTable.xs	Sat Dec 20 20:16:41 2003
@@ -32,7 +32,6 @@
 #include <stdarg.h>

 /* prototypes to make the compiler shut up */
-void ppt_warn(const char*, ...);
 void ppt_die(const char*, ...);
 void store_ttydev(HV*, unsigned long);
 void bless_into_proc(char* , char**, ...);
@@ -56,22 +55,7 @@
  * croak() in perl 5.8?? warn and croak exist in 5.6, but don't
  * seem to accept format args.
  */
-void ppt_warn(const char *pat, ...) {
-    dTHX;
-    va_list args;
-    va_start(args, pat);
-    vwarn(pat, &args);
-    va_end(args);
-}

-/* same with croak */
-void ppt_croak(const char *pat, ...) {
-    dTHX;
-    va_list args;
-    va_start(args, pat);
-    vcroak(pat, &args);
-    va_end(args);
-}

 /* Look up the tty device, given the ttynum and store it */
 void store_ttydev( HV* myhash, unsigned long ttynum ){
