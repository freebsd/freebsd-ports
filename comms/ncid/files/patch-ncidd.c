*** ncidd.c	Wed Nov 24 03:44:55 2004
--- ncidd.c	Fri Jun  3 17:24:58 2005
***************
*** 359,376 ****
  
      strcat(strncpy(buf, ptr, BUFSIZ - 2), CR);
      if (write(ttyfd, buf, strlen(buf)) < 0) return -1;
!     do
      {
!         if ((num = read(ttyfd, buf + size, BUFSIZ - size - 1)) < 0) return -1;
!         size += num;
!     }    while (num);
  
!     if (debug && size) write(STDOUT, buf, size);
!     buf[size] = 0;
!     if ((bufp = strrchr(buf, 'O')) != 0)
!         if (!strncmp(bufp, "OK", 2)) return 0;
!     if ((bufp = strrchr(buf, 'E')) != 0)
!         if (!strncmp(bufp, "ERROR", 5)) return 1;
  
      return 2;
  }
--- 359,381 ----
  
      strcat(strncpy(buf, ptr, BUFSIZ - 2), CR);
      if (write(ttyfd, buf, strlen(buf)) < 0) return -1;
! 
!     do 
      {
! 	do
! 	{
! 	    if ((num = read(ttyfd, buf + size, BUFSIZ - size - 1)) < 0) return -1;
! 	    size += num;
! 	}    while (num);
! 
! 	if (debug && size) write(STDOUT, buf, size);
! 	buf[size] = 0;
  
! 	if ((bufp = strrchr(buf, 'O')) != 0)
! 	    if (!strncmp(bufp, "OK", 2)) return 0;
! 	if ((bufp = strrchr(buf, 'E')) != 0)
! 	    if (!strncmp(bufp, "ERROR", 5)) return 1;
!     } while(1);
  
      return 2;
  }
