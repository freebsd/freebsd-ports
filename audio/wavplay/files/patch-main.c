*** main.c.orig	Sat Jan 15 12:51:14 2000
--- main.c	Sat Jan 15 14:14:54 2000
***************
*** 56,62 ****
--- 56,64 ----
  #include <unistd.h>
  #include <stdarg.h>
  #include <string.h>
+ #ifndef FREEBSD
  #include <getopt.h>
+ #endif
  #include <fcntl.h>
  #include <sys/types.h>
  #include <sys/ipc.h>
***************
*** 82,88 ****
--- 84,94 ----
  	else	printf("Usage:\t%s [options] [files...]\n\n",cmd);
  
  	puts("Options:");
+ #ifndef FREEBSD
  	printf("\t-%c\tThis info (or use --help)\n",OPF_HELP);
+ #else
+ 	printf("\t-%c\tThis info\n",OPF_HELP);
+ #endif
  	printf("\t-%c\tQuiet mode (no messages)\n",OPF_QUIET);
  	printf("\t-%c rate\tSampling rate\n",OPF_SAMPRATE);
  	printf("\t-%c\tDebug mode\n",OPF_DEBUG);
***************
*** 105,111 ****
--- 111,121 ----
  	if ( opr_mode != OprRecord )
  		printf("\t-%c\tDisplay info about wav file(s) only\n",OPF_INFO);
  
+ #ifndef FREEBSD
  	printf("\n\t-%c\tDisplay version and Copyright info (or use --version)\n\n",OPF_VERSION);
+ #else
+ 	printf("\n\t-%c\tDisplay version and Copyright info\n\n",OPF_VERSION);
+ #endif
  
  	puts("\nWAV parameters are normally taken from the input file(s),\n"
  		"but command line options can override them if required.");
***************
*** 208,213 ****
--- 218,225 ----
  	int rc;					/* Return code */
  	int fd;					/* Temporary file descriptor */
  	double d;				/* Temporary double value */
+ 	char *cp;				/* Used for env var */
+ 	uid_t uid;				
  	static char cmdopts[] = {
  		OPF_INFO, OPF_HELP, OPF_QUIET, OPF_SAMPRATE,':', OPF_STEREO, OPF_MONO,
  		OPF_TIME,':', OPF_DATABITS,':', OPF_IPCKEY,':', OPF_RESET,
