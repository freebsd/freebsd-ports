 --- src/display/j31sx.c	30 Sep 2008 08:02:59 -0000	1.1.1.1
 +++ src/display/j31sx.c	23 Oct 2008 09:24:33 -0000
 @@ -49,7 +49,6 @@
  #include	<sys/mman.h>
  #include	<linux/mm.h>
  #include	<sys/kd.h>
 -#undef free
  #include	<stdlib.h>
  
  #include	<mem.h>
 @@ -365,8 +364,6 @@
  	ioperm(CGA_COLOR, 1, 0);
  
  	munmap(gram, GRAPH_SIZE);
 -
 -	SafeFree((void **)&gram);
  }
  
  static struct videoInfo J31SXInfo =
