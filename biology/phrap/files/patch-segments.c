--- ./segments.c.orig	2008-07-30 19:14:13.000000000 +0200
+++ ./segments.c	2014-08-02 12:39:30.000000000 +0200
@@ -112,6 +112,7 @@
   return head;
 }
 
+void
 print_segments(head, index, complement) 
      Segment *head;
      int index;
@@ -128,6 +129,7 @@
   } 
 }
 
+void
 old_print_segments(head, index1, index2, offset, rel_orient) 
      Segment *head;
      int index1, index2, offset;
