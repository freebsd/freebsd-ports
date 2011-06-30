Index: src/intvects.h
===================================================================
RCS file: /sources/simulavr/simulavr/src/intvects.h,v
retrieving revision 1.8
diff -u -u -r1.8 intvects.h
--- src/intvects.h	16 Mar 2008 21:14:08 -0000	1.8
+++ src/intvects.h	29 Jun 2011 06:06:35 -0000
@@ -26,6 +26,8 @@
 #ifndef SIM_INTVECTS_H
 #define SIM_INTVECTS_H
 
+#include <stddef.h>
+
 enum _sleep_modes
 {
     SLEEP_MODE_IDLE,
@@ -83,7 +85,7 @@
    an index enumeration. */
 
 #define irq_vect_table_index(vect) \
-    ( ((unsigned int) (&( ((IntVectTable *)(0)) -> vect))) / sizeof(IntVect) )
+    ( offsetof(IntVectTable, vect) / sizeof(IntVect) )
 
 /* No device will have all of these vectors, but must define a structure which
    has a slot for each interrupt. If the device doesn't support the
