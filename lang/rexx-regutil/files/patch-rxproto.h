--- rxproto.h.orig	2003-05-23 11:05:50 UTC
+++ rxproto.h
@@ -53,7 +53,7 @@
  * to something else, and a pointer to the result string.
  * It returns 0 for success, and some other value for failure */
 
-#define rxfunc(x) APIRET APIENTRY x(PUCHAR fname, ULONG argc, PRXSTRING argv, PSZ pSomething, PRXSTRING result)
+#define rxfunc(x) APIRET APIENTRY x(PCSZ fname, ULONG argc, PRXSTRING argv, PCSZ pSomething, PRXSTRING result)
 
 /* return codes. 22 is rc for invalid call */
 #define NOMEMORY 5
