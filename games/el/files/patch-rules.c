*** rules.c.orig	Mon Jan 17 23:00:20 2005
--- rules.c	Wed Jan 26 08:59:17 2005
***************
*** 3,9 ****
  #include <libxml/parser.h>
  #include <libxml/tree.h>
  #include <string.h>
! #include <malloc.h>
  
  #define TITLE 	0
  #define RULE	1
--- 3,9 ----
  #include <libxml/parser.h>
  #include <libxml/tree.h>
  #include <string.h>
! #include <stdlib.h>
  
  #define TITLE 	0
  #define RULE	1
