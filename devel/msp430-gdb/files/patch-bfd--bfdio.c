diff --git bfd/bfdio.c.orig b/bfd/bfdio.c
--- bfd/bfdio.c.orig
+++ bfd/bfdio.c
@@ -1,7 +1,7 @@
 /* Low-level I/O routines for BFDs.
 
    Copyright 1990, 1991, 1992, 1993, 1994, 1995, 1996, 1997, 1998,
-   1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009
+   1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2011
    Free Software Foundation, Inc.
 
    Written by Cygnus Support.
@@ -577,7 +577,7 @@ memory_bstat (bfd *abfd, struct stat *statbuf)
 {
   struct bfd_in_memory *bim = (struct bfd_in_memory *) abfd->iostream;
 
-  memset (statbuf, 0, sizeof (statbuf));
+  memset (statbuf, 0, sizeof (*statbuf));
   statbuf->st_size = bim->size;
 
   return 0;
-- 
1.7.1


