$FreeBSD$

--- ../../j2se/src/solaris/native/sun/awt/awt_Component.c.orig	27 Oct 2003 12:16:41 -0000	1.4
+++ ../../j2se/src/solaris/native/sun/awt/awt_Component.c	1 Mar 2004 21:36:45 -0000	1.5
@@ -1179,7 +1179,7 @@
             }
             XtVaSetValues(to, XmNtraversalOn, True, NULL);
         }
-    } else if (from != NULL) {
+    } else if (from != NULL && to != NULL) {
         // disable the tree starting from uncommon part to 'from'
         if (parents_from[index] == parents_to[index]) {
             if (index == count_from - 1) {
