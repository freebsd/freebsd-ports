--- tleap/unitio.c.orig	Sat Nov  9 18:37:02 2002
+++ tleap/unitio.c	Fri Feb 14 12:20:38 2003
@@ -5958,6 +5958,7 @@
  *TODO: Add CAP information
  */
 #define AMBERINDEX(i)   3*(i-1)
+#undef  INTFORMAT
 #define INTFORMAT       "%6d"
 #define DBLFORMAT       "%16.8lE"
 #define LBLFORMAT       "%-4s"
