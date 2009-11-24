$FreeBSD$
--- lib/backends.h.orig	2009-11-24 21:46:47.000000000 +0100
+++ lib/backends.h	2009-11-24 21:46:47.000000000 +0100
@@ -109,6 +109,7 @@ typedef struct vorbis_info_residue0{
   /* first stage (lossless partitioning) */
   int    grouping;         /* group n vectors per partition */
   int    partitions;       /* possible codebooks for a partition */
+  int    partvals;         /* partitions ^ groupbook dim */
   int    groupbook;        /* huffbook for partitioning */
   int    secondstages[64]; /* expanded out to pointers in lookup */
   int    booklist[512];    /* list of second stage books */
