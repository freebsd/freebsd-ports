#iZ and CWS
o http://www.openoffice.org/issues/show_bug.cgi?id=27753
o vcl34

Description
The isnan() macro is a new feature of C99 and not yet part of C++.
Index: source/helper/strhelper.cxx
===================================================================
RCS file: /cvs/gsl/psprint/source/helper/strhelper.cxx,v
retrieving revision 1.6
diff -u -r1.6 strhelper.cxx
--- psprint/source/helper/strhelper.cxx	30 Mar 2004 13:48:06 -0000	1.6
+++ psprint/source/helper/strhelper.cxx	13 Apr 2004 22:26:11 -0000
@@ -67,6 +67,10 @@
 #include <cmath> // for isnan
 #include <cstring>
 
+#if defined (FREEBSD)
+using namespace __gnu_cxx;  //for isnan
+#endif
+
 namespace psp {
 
 inline int isSpace( char cChar )
