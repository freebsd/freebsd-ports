do not need <malloc.h> including stdlib.h is enough
http://qa.openoffice.org/issues/show_bug.cgi?id=27041

--- ../vcl/source/gdi/outdev3.cxx.old	Mon Mar 29 09:42:28 2004
+++ ../vcl/source/gdi/outdev3.cxx	Mon Mar 29 09:42:59 2004
@@ -176,7 +176,7 @@
 #if defined(SOLARIS) || defined(IRIX)
   #include <alloca.h>
 #else
-#ifndef MACOSX
+#if !(defined(MACOSX) || defined(FREEBSD))
   #include <malloc.h>
 #endif
 #endif
