--- lib/qvf.cc.orig	Fri Feb 23 21:29:12 2001
+++ lib/qvf.cc	Fri Feb 13 19:17:38 2004
@@ -4,6 +4,8 @@
 
 # include <stdio.h>	// sscanf
 
+using namespace std;
+
 #ifdef NLS
   # include <locale.h>
   # include <libintl.h>
@@ -54,7 +56,7 @@
 } 
 
 
-qvf::qvf(u_int32_t v, enum format f=SPECIFIC):value(v),format(f) { }
+qvf::qvf(u_int32_t v, enum format f):value(v),format(f) { }
 
 
 qvf::qvf(char *s) {
