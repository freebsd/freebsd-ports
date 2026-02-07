--- 3rdparty/wxwidgets3.0/include/nogui/wx/setup.h.orig	2020-10-29 23:31:05 UTC
+++ 3rdparty/wxwidgets3.0/include/nogui/wx/setup.h
@@ -1108,7 +1108,7 @@
 #define HAVE_SYS_SELECT_H 1
 
 /* Define if you have abi::__forced_unwind in your <cxxabi.h>. */
-#define HAVE_ABI_FORCEDUNWIND 1
+/*#define HAVE_ABI_FORCEDUNWIND 1*/
 
 /* Define if fdopen is available.  */
 #define HAVE_FDOPEN 1
