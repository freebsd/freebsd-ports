malloc.h is deprecated
http://qa.openoffice.org/issues/show_bug.cgi?id=27041

--- ../vcl/source/glyphs/gcach_layout.cxx~	Tue Mar  9 21:15:32 2004
+++ ../vcl/source/glyphs/gcach_layout.cxx	Mon Mar 29 09:44:52 2004
@@ -74,7 +74,7 @@
 #if defined(SOLARIS) || defined(IRIX)
   #include <alloca.h>
 #else
-#ifndef MACOSX
+#if !(defined(MACOSX) || defined(FREEBSD))
   #include <malloc.h>
 #endif
 #endif
