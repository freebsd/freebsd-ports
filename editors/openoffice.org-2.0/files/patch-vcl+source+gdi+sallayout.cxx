malloc.h is deprecated
http://qa.openoffice.org/issues/show_bug.cgi?id=27041

--- ../vcl/source/gdi/sallayout.cxx.org	Mon Mar 29 10:02:17 2004
+++ ../vcl/source/gdi/sallayout.cxx	Mon Mar 29 10:02:43 2004
@@ -67,7 +67,7 @@
 #if defined(SOLARIS) || defined(IRIX)
   #include <alloca.h>
 #else
-#ifndef MACOSX
+#if !(defined(MACOSX) || defined(FREEBSD))
   #include <malloc.h>
 #endif
 #endif
