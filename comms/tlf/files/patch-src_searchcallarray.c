*** src/searchcallarray.c.orig	Fri Nov 12 15:40:59 2004
--- src/searchcallarray.c	Fri Nov 12 15:41:45 2004
***************
*** 25,31 ****

   	int searchcallarray  (char  *hiscall)
   	{
-  	extern char hiscall[];
   	extern int callarray_nr;
   	extern char callarray[MAX_CALLS][20];

--- 25,30 ----
