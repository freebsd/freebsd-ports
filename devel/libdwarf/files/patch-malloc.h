--- dwarf_alloc.c.orig	Mon Nov 22 19:20:35 2004
+++ dwarf_alloc.c	Fri Feb 11 22:22:22 2005
@@ -41,7 +41,6 @@
 
 #include <stdlib.h>
 #include <stdio.h>
-#include <malloc.h>
 
 /*
     These files are included to get the sizes
--- dwarf_init_finish.c.orig	Mon Nov 22 19:20:33 2004
+++ dwarf_init_finish.c	Fri Feb 11 22:22:30 2005
@@ -57,7 +57,6 @@
 #include <sys/types.h>
 #include <string.h>
 #include <stdlib.h>
-#include <malloc.h>
 
 #include "dwarf_incl.h"
 
--- dwarf_sort_line.c.orig	Mon Nov 22 19:20:35 2004
+++ dwarf_sort_line.c	Fri Feb 11 22:22:39 2005
@@ -43,7 +43,6 @@
 #ifdef HAVE_ALLOCA_H
 #include <alloca.h>
 #endif
-#include <malloc.h>
 
 #define MINIMUM_POSSIBLE_PROLOG_LEN 10  /* 10 is  based on */
 	/*  the definition of the DWARF2/3 line table prolog.
