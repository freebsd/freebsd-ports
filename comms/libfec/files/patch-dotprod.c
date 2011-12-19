*** dotprod.c	2006-10-12 21:10:53.000000000 -0400
--- ../../foowork/fec-3.0.1/dotprod.c	2011-12-14 20:43:00.132752233 -0500
***************
*** 54,59 ****
--- 54,60 ----
    switch(Cpu_mode){
    case PORT:
    default:
+     return feedp_port(p); 
  #ifdef __i386__
    case MMX:
    case SSE:
