*** include/config.h.orig	Sat Jul 22 03:13:51 2000
--- include/config.h	Sat Dec  9 13:31:34 2000
***************
*** 45,51 ****
  #define TTY_GRAPHICS	/* good old tty based graphics */
  /* #define X11_GRAPHICS */	/* X11 interface */
  /* #define QT_GRAPHICS */	/* Qt interface */
! /* #define GNOME_GRAPHICS */	/* Gnome interface */
  
  /*
   * Define the default window system.  This should be one that is compiled
--- 45,51 ----
  #define TTY_GRAPHICS	/* good old tty based graphics */
  /* #define X11_GRAPHICS */	/* X11 interface */
  /* #define QT_GRAPHICS */	/* Qt interface */
! #define GNOME_GRAPHICS 	/* Gnome interface */
  
  /*
   * Define the default window system.  This should be one that is compiled
***************
*** 151,161 ****
  
  #ifdef UNIX
  /* path and file name extension for compression program */
! #define COMPRESS "/usr/bin/compress"	/* Lempel-Ziv compression */
! #define COMPRESS_EXTENSION ".Z"		/* compress's extension */
  /* An example of one alternative you might want to use: */
! /* #define COMPRESS "/usr/local/bin/gzip" */	/* FSF gzip compression */
! /* #define COMPRESS_EXTENSION ".gz" */		/* normal gzip extension */
  #endif
  
  #ifndef COMPRESS
--- 151,161 ----
  
  #ifdef UNIX
  /* path and file name extension for compression program */
! /* #define COMPRESS "/usr/bin/compress" */	/* Lempel-Ziv compression */
! /* #define COMPRESS_EXTENSION ".Z" */		/* compress's extension */
  /* An example of one alternative you might want to use: */
! #define COMPRESS "/usr/bin/gzip"	/* FSF gzip compression */
! #define COMPRESS_EXTENSION ".gz"	/* normal gzip extension */
  #endif
  
  #ifndef COMPRESS
***************
*** 186,192 ****
   * otherwise it will be the current directory.
   */
  # ifndef HACKDIR
! #  define HACKDIR "/usr/games/lib/nethackdir"	/* nethack directory */
  # endif
  
  /*
--- 186,192 ----
   * otherwise it will be the current directory.
   */
  # ifndef HACKDIR
! #  define HACKDIR "/usr/local/share/nethack"	/* nethack directory */
  # endif
  
  /*
