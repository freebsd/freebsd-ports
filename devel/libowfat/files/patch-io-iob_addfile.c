Index: io/iob_addfile.c
===================================================================
RCS file: /cvs/libowfat/io/iob_addfile.c,v
retrieving revision 1.2
retrieving revision 1.3
diff -u -r1.2 -r1.3
--- io/iob_addfile.c	26 Sep 2003 15:55:44 -0000	1.2
+++ io/iob_addfile.c	7 Apr 2004 08:38:41 -0000	1.3
@@ -1,7 +1,9 @@
 #include "iob_internal.h"
 
 int iob_addfile(io_batch* b,int64 fd,uint64 off,uint64 n) {
-  iob_entry* e=array_allocate(&b->b,sizeof(iob_entry),
+  iob_entry* e;
+  if (n==0) return 1;
+  e=array_allocate(&b->b,sizeof(iob_entry),
 			     array_length(&b->b,sizeof(iob_entry)));
   if (!e) return 0;
   e->type=FROMFILE;
