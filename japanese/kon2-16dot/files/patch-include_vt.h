 --- include/vt.h	30 Sep 2008 08:09:55 -0000	1.1.1.2
 +++ include/vt.h	23 Oct 2008 09:24:33 -0000
 @@ -59,12 +59,10 @@
  	ins,
  	active,
  	wrap,
 -#if defined(__FreeBSD__)
 -	text_mode,
 -	cursor_key_mode;
 -#else
  	text_mode;
 -#endif
 +#if defined(__FreeBSD__)
 +    bool cursor_key_mode;
 +#endif	/* __FreeBSD__ */
  };
  
  extern struct	_con_info con;
