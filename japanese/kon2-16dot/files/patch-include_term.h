 --- include/term.h	30 Sep 2008 08:02:59 -0000	1.1.1.1
 +++ include/term.h	23 Oct 2008 09:24:33 -0000
 @@ -36,5 +36,6 @@
  extern void	TermStart(void);	 /* start procesing */
  extern void	TermRestart(int fd);	 /* restart kon (args are read from fd) */
  extern int	masterPty;		 /* master pseudo-tty file descriptor */
 +extern int	TermGetNumber(void);
  
  #endif
