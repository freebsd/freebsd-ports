 --- lib/mem.c	30 Sep 2008 08:09:56 -0000	1.1.1.2
 +++ lib/mem.c	23 Oct 2008 09:24:33 -0000
 @@ -79,10 +79,3 @@
  }
  #endif
  
 -void	SafeFree(void **p)
 -{
 -	if (*p) {
 -		free(*p);
 -		*p = NULL;
 -	}
 -}
