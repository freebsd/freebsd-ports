*** uftpd.c	Sun Feb 25 16:55:42 2007
--- uftpd.c	Wed Jun  4 14:05:20 2008
***************
*** 853,861 ****
    applog=stderr;
    nice(-20);
    for (c=1;c<=17;c++)
!     sigset(c,gotsig);
!   sigset(SIGPIPE,gotpipe);
!   sigset(SIGCHLD,SIG_IGN);
  #endif
    for (c=0;c<MAXLIST;c++)
      id_list[c].txID=0;
--- 853,861 ----
    applog=stderr;
    nice(-20);
    for (c=1;c<=17;c++)
!     signal(c,gotsig);
!   signal(SIGPIPE,gotpipe);
!   signal(SIGCHLD,SIG_IGN);
  #endif
    for (c=0;c<MAXLIST;c++)
      id_list[c].txID=0;
