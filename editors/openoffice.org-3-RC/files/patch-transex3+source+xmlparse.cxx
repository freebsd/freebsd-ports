#iZ XXXX

FreeBSD doesn't have alloca.h, and
builtin alloca is defined at stdlib.h.

Index: transex3/source/xmlparse.cxx
===================================================================
RCS file: /cvs/l10n/transex3/source/xmlparse.cxx,v
retrieving revision 1.2
diff -u -r1.2 xmlparse.cxx
--- transex3/source/xmlparse.cxx	30 Aug 2004 17:31:58 -0000	1.2
+++ transex3/source/xmlparse.cxx	3 Oct 2004 08:41:45 -0000
@@ -64,11 +64,12 @@
 
 
 #include <stdio.h>
-#ifdef WIN32
-#include <malloc.h>
+
+#if defined(SOLARIS) || defined(IRIX)
+  #include <alloca.h>
 #else
-#ifndef MACOSX
-#include <alloca.h>
+#if !(defined(MACOSX) || defined(FREEBSD))
+  #include <malloc.h>
 #endif
 #endif
 
