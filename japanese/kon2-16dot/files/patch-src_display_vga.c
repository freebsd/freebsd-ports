 --- src/display/vga.c	30 Sep 2008 08:09:56 -0000	1.1.1.2
 +++ src/display/vga.c	23 Oct 2008 09:24:33 -0000
 @@ -56,7 +56,6 @@
  #endif
  vm_size_t page_size;
  #endif
 -#undef free
  #include	<stdlib.h>
  
  #include	<mem.h>
 @@ -691,10 +690,9 @@
  
      munmap(gramMem, dInfo.gsize);
      
 -    SafeFree((void **)&gramMem);
 -    SafeFree((void **)&fontBuff1);
 +    SafeFree(fontBuff1);
      if (savePlane3)
 -	SafeFree((void **)&fontBuff2);
 +	SafeFree(fontBuff2);
  }
  
  /* Configure */
 

