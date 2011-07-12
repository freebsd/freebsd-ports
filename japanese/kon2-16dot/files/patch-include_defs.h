 --- include/defs.h	30 Sep 2008 08:02:59 -0000	1.1.1.1
 +++ include/defs.h	23 Oct 2008 09:27:32 -0000
 @@ -37,4 +37,6 @@
  #define	FAILURE	(-1)
  #define SUCCESS	(0)
  
 +#define SafeFree(x)   do { if ((x) != NULL) free(x), (x) = NULL; } while (0)
 +
  #endif
