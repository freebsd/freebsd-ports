This patch by Julian Stacey <jhs@FreeBSD.Org>

*** bas6.c	Fri Aug 11 12:17:21 1995
--- bas6.c	Sun Aug 13 15:53:25 1995
***************
*** 162,168 ****
--- 162,179 ----
   *    written at the same time
   */
  
+ #ifndef __FreeBSD__
  long	lseek();
+ 	/* To phil C		phil@gmrs.isar.de
+ 	   From Julian S	jhs@freebsd.org
+ 	   Date 950813
+ 	FreeBSD current has 
+ 	off_t    lseek __P((int, off_t, int));
+ 	& reports
+ 	/usr/include/unistd.h:82: previous declaration of `lseek'
+ 	however you might want a more general ifndef BSD or similar perhaps ?
+ 	*/
+ #endif
  
  int
  bfopen()
