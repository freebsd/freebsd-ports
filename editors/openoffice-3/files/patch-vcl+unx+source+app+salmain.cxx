--- ../vcl/unx/source/app/salmain.cxx	1 Aug 2003 03:34:39 -0000	1.8.4.1
+++ ../vcl/unx/source/app/salmain.cxx	7 Aug 2003 22:43:19 -0000
@@ -62,7 +62,7 @@
 #define _SV_SALMAIN_CXX
 
 // -=-= #includes =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
-#ifdef MACOSX
+#if defined(MACOSX) || defined(FREEBSD)
 // rlimit needs sys/types.h
 #include <sys/types.h>
 #include <sys/time.h>
