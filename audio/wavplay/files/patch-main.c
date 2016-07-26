--- main.c.orig	1999-12-04 00:06:42 UTC
+++ main.c
@@ -56,7 +56,9 @@ static const char rcsid[] = "@(#)main.c 
 #include <unistd.h>
 #include <stdarg.h>
 #include <string.h>
+#ifndef FREEBSD
 #include <getopt.h>
+#endif
 #include <fcntl.h>
 #include <sys/types.h>
 #include <sys/ipc.h>
@@ -82,7 +84,11 @@ usage(const char *cmd,OprMode opr_mode) 
 	else	printf("Usage:\t%s [options] [files...]\n\n",cmd);
 
 	puts("Options:");
+#ifndef FREEBSD
 	printf("\t-%c\tThis info (or use --help)\n",OPF_HELP);
+#else
+	printf("\t-%c\tThis info\n",OPF_HELP);
+#endif
 	printf("\t-%c\tQuiet mode (no messages)\n",OPF_QUIET);
 	printf("\t-%c rate\tSampling rate\n",OPF_SAMPRATE);
 	printf("\t-%c\tDebug mode\n",OPF_DEBUG);
@@ -105,7 +111,11 @@ usage(const char *cmd,OprMode opr_mode) 
 	if ( opr_mode != OprRecord )
 		printf("\t-%c\tDisplay info about wav file(s) only\n",OPF_INFO);
 
+#ifndef FREEBSD
 	printf("\n\t-%c\tDisplay version and Copyright info (or use --version)\n\n",OPF_VERSION);
+#else
+	printf("\n\t-%c\tDisplay version and Copyright info\n\n",OPF_VERSION);
+#endif
 
 	puts("\nWAV parameters are normally taken from the input file(s),\n"
 		"but command line options can override them if required.");
@@ -208,6 +218,8 @@ main(int argc,char **argv) {
 	int rc;					/* Return code */
 	int fd;					/* Temporary file descriptor */
 	double d;				/* Temporary double value */
+	char *cp;				/* Used for env var */
+	uid_t uid;				
 	static char cmdopts[] = {
 		OPF_INFO, OPF_HELP, OPF_QUIET, OPF_SAMPRATE,':', OPF_STEREO, OPF_MONO,
 		OPF_TIME,':', OPF_DATABITS,':', OPF_IPCKEY,':', OPF_RESET,
