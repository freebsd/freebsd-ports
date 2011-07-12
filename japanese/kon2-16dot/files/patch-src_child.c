 --- src/child.c	30 Sep 2008 08:09:56 -0000	1.1.1.2
 +++ src/child.c	23 Oct 2008 09:24:33 -0000
 @@ -40,16 +40,18 @@
  #include	<version.h>
  #include	<vc.h>
  
 -static char *startupStr, *execProg;
 +static char *startupStr = NULL, *execProg = NULL;
  
  int	ConfigExecProg(const char *string)
  {
 +	SafeFree(execProg);
  	execProg = strdup(string);
  	return SUCCESS;
  }
  
  static int	ConfigStartup(const char *string)
  {
 +	SafeFree(startupStr);
  	startupStr = strdup(string);
  	return SUCCESS;
  }
 @@ -81,7 +83,8 @@
  
  void	ChildCleanup(void)
  {
 -	free(startupStr);
 +	SafeFree(startupStr);
 +	SafeFree(execProg);
  }
  
  void	ChildStart(FILE *errfp)
 @@ -105,46 +108,44 @@
  	win.ws_col = dInfo.txmax + 1;
  	win.ws_xpixel = win.ws_ypixel = 0;
  	ioctl(STDIN_FILENO, TIOCSWINSZ, &win);
 -	sprintf(buff,"TERM=vt100");
 -#endif
 +	strcpy(buff, "TERM=vt100-color");
 +#endif	/* __FreeBSD__ */
  
  	tcap = strdup(buff);
  	putenv(tcap);
  
 -	if (startupMessage)
 +	if (startupMessage) {
  	    printf("\rKON2 Kanji On Console " VERSION
 -		   " using VT number %c\r\n"
 +		   " using VT number %d\n"
  		   "%*s\r\n"
 -#if defined(__FreeBSD__)
 -		   "%*s\r\n", *(ttyname(fileno(errfp))+9),
 -#else   /* linux */
 -		   "%*s\r\n", *(ttyname(fileno(errfp))+8),
 -#endif
 +		   "%*s\r\n",
 +		   TermGetNumber(),
  		   dInfo.txmax,
  		   "Copyright (C) "
  		   "1993-1996  Takashi MANABE",
  		   dInfo.txmax,
  		   "1993, 1994 MAEDA Atusi   ");
  #if defined(__FreeBSD__)
 -	printf("\rKON for FreeBSD-2.x ver0.01 Takashi OGURA\r\n");
 +	    printf("\rKON for FreeBSD-2.x ver0.01 Takashi OGURA\r\n");
  #endif
 -
 +	}
  
  /*
 -	printf("KON using VT number %c.\n\n",
 -	       *(ttyname(fileno(errfp))+8));
 +	printf("KON using VT number %d.\n\n", TermGetNumber());
  */
  	fflush(stdout);
  
  	if (execProg)
  	    execlp(execProg, execProg, 0);
  	else {
 +	    char *ptr;
  	    if ((execProg = getenv("SHELL")) == NULL)
  		execProg = "/bin/sh";
  	    if ((tail = rindex(execProg, '/')) == NULL)
  		tail = " sh";
 -	    sprintf(buff, "-%s", tail + 1);
 -	    execl(execProg, buff, 0);
 +	    ptr = strdup(tail);
 +	    *ptr = '-';
 +	    execl(execProg, ptr, 0);
  	}
  	fprintf(errfp, "KON> couldn't exec shell\r\n");
  	fprintf(errfp, "%s: %s\r\n", execProg, strerror(errno));
