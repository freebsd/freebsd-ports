#iZ and CWS
o http://www.openoffice.org/issues/show_bug.cgi?id=40184
o http://eis.services.openoffice.org/EIS2/servlet/cws.ShowCWS?Id=2030&Path=SRC680%2Fpj16
o pj16

Description
FreeBSD doesn't have alloca.h

Index: source/xmlparse.cxx
===================================================================
RCS file: /cvs/l10n/transex3/source/xmlparse.cxx,v
retrieving revision 1.5
diff -u -r1.5 xmlparse.cxx
--- transex3/source/xmlparse.cxx	18 Nov 2004 08:17:50 -0000	1.5
+++ transex3/source/xmlparse.cxx	8 Jan 2005 02:56:14 -0000
@@ -67,7 +67,7 @@
 #ifdef WIN32
 #include <malloc.h>
 #else
-#ifndef MACOSX
+#if !(defined(MACOSX) || defined(FREEBSD))
 #include <alloca.h>
 #endif
 #endif
