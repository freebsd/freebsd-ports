--- src/ixlib_base.hh.orig	Fri Nov 28 11:48:47 2003
+++ src/ixlib_base.hh	Fri Nov 28 12:45:22 2003
@@ -44,11 +44,15 @@
 
 /* STL Helper macro -----------------------------------------------------------
 */
+#define FOREACH_T(VAR,LIST,LISTTYPE) \
+  for (typename LISTTYPE::iterator VAR = (LIST).begin(),last = (LIST).end();VAR != last;VAR++) 
+#define FOREACH_CONST_T(VAR,LIST,LISTTYPE) \
+  for (typename LISTTYPE::const_iterator VAR = (LIST).begin(),last = (LIST).end();VAR != last;VAR++) 
+
 #define FOREACH(VAR,LIST,LISTTYPE) \
   for (LISTTYPE::iterator VAR = (LIST).begin(),last = (LIST).end();VAR != last;VAR++) 
 #define FOREACH_CONST(VAR,LIST,LISTTYPE) \
   for (LISTTYPE::const_iterator VAR = (LIST).begin(),last = (LIST).end();VAR != last;VAR++) 
-
 
 
 
