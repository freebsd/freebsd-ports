*** lib-src/movemail.c.orig	Sun May  2 18:25:15 1999
--- lib-src/movemail.c	Thu Feb 10 21:38:32 2005
***************
*** 765,771 ****
        mbx_delimit_begin (mbf);
        if (pop_retr (server, i, mbf) != OK)
  	{
! 	  error (Errmsg);
  	  close (mbfi);
  	  return (1);
  	}
--- 765,771 ----
        mbx_delimit_begin (mbf);
        if (pop_retr (server, i, mbf) != OK)
  	{
! 	  error ("%s", Errmsg);
  	  close (mbfi);
  	  return (1);
  	}
