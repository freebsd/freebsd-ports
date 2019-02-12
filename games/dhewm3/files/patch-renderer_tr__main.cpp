https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=235668:

On powerpc* platforms vecLib/vecLib.h is included by default. This
header is only available on Mac OS X, so remove it. It doesn't seem
to be actually needed to compile this port

--- renderer/tr_main.cpp.orig	2019-02-11 12:39:53 UTC
+++ renderer/tr_main.cpp
@@ -26,7 +26,7 @@ If you have questions concerning this license or the a
 ===========================================================================
 */
 
-#ifdef __ppc__
+#if defined(__ppc__) && defined(__APPLE__)
 #include <vecLib/vecLib.h>
 #endif
 #if defined(__GNUC__) && defined(__SSE2__)
