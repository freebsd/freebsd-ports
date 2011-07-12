 --- font/fontx2.c	30 Sep 2008 08:02:59 -0000	1.1.1.1
 +++ font/fontx2.c	23 Oct 2008 09:24:33 -0000
 @@ -37,6 +37,7 @@
  #include	<string.h>
  #include	<sys/socket.h>
  
 +#include	<defs.h>
  #include	<interface.h>
  #include	<fnld.h>
  
 @@ -170,7 +171,7 @@
  	    font = FontLoadSFontx(fp, header);
  	else exit(0);
      }
 -    free(header);
 +    SafeFree(header);
      return(font);
  }
  
