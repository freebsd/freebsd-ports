*** gumps/gump_utils.h~	Mon Feb 18 12:30:14 2002
--- gumps/gump_utils.h	Mon Feb 18 12:28:58 2002
***************
*** 27,32 ****
--- 27,36 ----
  #include <sys/types.h>
  #endif
  
+ #ifdef __FreeBSD__
+ #include <string.h>
+ #endif
+ 
  #include <unistd.h>
  #include "mouse.h"
