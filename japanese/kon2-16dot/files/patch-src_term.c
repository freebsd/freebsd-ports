 --- src/term.c	30 Sep 2008 08:09:56 -0000	1.1.1.2
 +++ src/term.c	23 Oct 2008 09:24:33 -0000
 @@ -76,7 +76,7 @@
  
  int	masterPty;			 /* master pseudo-tty file descriptor */
  
 -#define	MAX_TTYNAME	10
 +#define	MAX_TTYNAME	20
  
  static int	childPid, sockFd, slavePty;
  static struct termio	oldTio;
 @@ -235,13 +235,16 @@
      }
      ConsoleInit(video);
      while (i < argc) {
 -	const char	*arg;
 +	const char	*arg = argv[i];
  
 -	if (argv[i][0] != '-') {
 -	    warn("bad arg `%s'; assumed `-%s'\r\n", argv[i]);
 -	    arg = (char *) argv[i];
 -	} else
 -	    arg = (char *) argv[i] + 1;
 +	if (*arg != '-')
 +	    warn("bad arg `%s'; assumed `-%s'\n", arg, arg);
 +	else
 +	    ++arg;
 +	if (!strcasecmp(arg, "help")) {
 +	    message("Usage: kon2 [video] [-option value] ...\n");
 +	    exit(EXIT_FAILURE);
 +	}
  	i++;
  	if (i >= argc) {
  	    error("no value for `%s'\r\n", arg);
 @@ -258,6 +261,25 @@
  static int	savedArgc;		 /* argc of startup time */
  static const char	**savedArgv;	 /* argv of startup time */
  
 +static int ttyNumber = 0;
 +
 +int
 +set_vt_number(void)
 +{
 +#if defined(__FreeBSD__)
 +    ttyNumber = strtol(ttyname(0) + 9, NULL, 16);
 +#elif defined(linux)
 +    ttyNumber = atoi(ttyname(0) + 8);
 +#endif	/* linux */
 +    return ttyNumber;
 +}
 +
 +int
 +TermGetNumber(void)
 +{
 +    return ttyNumber;
 +}
 +
  /* Do initialization before reading config file */
  void	TermInit(int argc, const char *argv[])
  {
 @@ -266,6 +288,7 @@
      init.display = init.utmp = init.socket = init.termio = FALSE;
      /* Initialize subsystems. */
      
 +    set_vt_number();
      CapInit();
      ChildInit();
      MouseInit();
 @@ -355,8 +378,8 @@
  	mouseFd = MouseStart();
      }
  
 -    chown("/dev/tty0", getuid(), getgid());
  #if defined(linux)
 +    chown("/dev/tty0", getuid(), getgid());
      sockFd = SocketInit(ttyname(0) + 8);
  #elif defined(__FreeBSD__)
      sockFd = SocketInit(ttyname(0) + 9);
 @@ -381,6 +404,7 @@
  
  	/* Signal Setting */
  	signal(SIGCHLD, ExitPty);
 +	signal(SIGPIPE, SIG_IGN);
  	signal(SIGHUP, ExitTerm);
  	signal(SIGTERM, ExitTerm);
  	signal(SIGSEGV, ExitTerm);
 @@ -458,18 +482,13 @@
  	PerrorExit("/dev/console");
      }
  #elif defined(__FreeBSD__)
 -#if __FreeBSD_version >= 501100
 -    cfd = open("/dev/ttyv0", O_WRONLY);
 -    if (cfd < 0 && (cfd = open("/dev/ttyv0", O_RDONLY)) < 0) {
 -	PerrorExit("/dev/ttyv0");
 -    }
 -#else
 -    cfd = open("/dev/vga", O_WRONLY);
 -    if (cfd < 0 && (cfd = open("/dev/vga", O_RDONLY)) < 0) {
 -	PerrorExit("/dev/vga");
 +    cfd = open("/dev/vga", O_RDONLY);
 +    if (cfd == -1) {
 +	cfd = open("/dev/console", O_RDONLY);
 +	if (cfd == -1)
 +	    PerrorExit("/dev/console");
      }
 -#endif
 -#endif
 +#endif	/* __FreeBSD__ */
      ioctl(cfd, VT_ACTIVATE, orgVtNum);
      close(cfd);
  }
 @@ -486,28 +505,36 @@
      cfd = open("/dev/console", O_WRONLY);
      if (cfd < 0 && (cfd = open("/dev/console", O_RDONLY)) < 0)
  	fatal("can't open /dev/console");
 -#elif defined(__FreeBSD__)
 -#if __FreeBSD_version >= 501100
 -    cfd = open("/dev/ttyv0", O_WRONLY);
 -    if (cfd < 0 && (cfd = open("/dev/ttyv0", O_RDONLY)) < 0)
 -	fatal("can't open /dev/ttyv0");
 -#else
 -    cfd = open("/dev/vga", O_WRONLY);
 -    if (cfd < 0 && (cfd = open("/dev/vga", O_RDONLY)) < 0)
 -	fatal("can't open /dev/vga");
 -#endif
 -#endif
 +
      ioctl(cfd, KDGETMODE, &mode);
      if (mode == KD_TEXT) {
  	close(cfd);
  	return;
      }
 -#if defined(linux)
      ioctl(cfd, VT_GETSTATE, &vts);
      orgVtNum = vts.v_active;
 -#endif
 -    ioctl(cfd, VT_OPENQRY, &vtNum);
 -    if (vtNum < 0)
 +
 +#elif defined(__FreeBSD__)
 +    /* check for syscons mode */
 +    if (ioctl(0, KDGETMODE, &mode) == -1)
 +        fatal("KON is require the syscons(4)");
 +    else if (mode != KD_TEXT)
 +	fatal("unknown terminal mode.");
 +    else if (strcmp(ttyname(0), "/dev/console") != 0)
 +	return;
 +
 +    cfd = open("/dev/vga", O_RDONLY);
 +    if (cfd == -1) {
 +	cfd = open("/dev/console", O_RDONLY);
 +	if (cfd == -1)
 +	    fatal("can't open /dev/console");
 +    }
 +    if (ioctl(cfd, VT_GETINDEX, &orgVtNum) == -1)
 +	fatal("ioctl(VT_GETINDEX)");
 +#endif /* __FreeBSD__ */
 +
 +    errno = 0;
 +    if (ioctl(cfd, VT_OPENQRY, &vtNum) == -1 || vtNum < 0)
  	fatal("can't get free VC");
      parent = getpid();
      if ((child = fork()) == -1)
 @@ -515,12 +542,13 @@
      if (child) {
  	signal(SIGHUP, ExitPty);
  	pause();
 +	fatal("internal error.");
      }
      setsid();
  #if defined(linux)
      sprintf(vtty, "/dev/tty%d", vtNum);
  #elif defined(__FreeBSD__)
 -    sprintf(vtty, "/dev/ttyv%d", vtNum);
 +    sprintf(vtty, "/dev/ttyv%d", vtNum - 1);
  #endif
      if ((vfd = open(vtty, O_RDWR)) < 0)
  	fatal("can't open %s", vtty);
 @@ -531,5 +559,6 @@
      dup2(vfd, 0);
      dup2(vfd, 1);
      dup2(vfd, 2);
 +    close(vfd);
      kill(parent, SIGHUP);
  }
