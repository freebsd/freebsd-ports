diff -rc aftp/aftp.c aftp-1.01a/aftp.c
*** aftp.c	Mon Jan  6 22:19:13 1997
--- aftp.c	Tue Jan 21 00:49:56 1997
***************
*** 283,299 ****
  
  static	void	print_help(void)
  {
! 	printf("Command:\n");
! 	printf("  aftp [options] {input_disk_files}\n");
  	printf("Options:\n");
  	printf("  -p  use a (P)rodos filesystem.\n");
  	printf("  -o  use a prodos (O)rdered image.\n");
  	printf("  -i  use an xgs image file.\n");
! 	printf("  -d  Load images as read-only.\n");
  	printf("  -?  Display aftp help.\n");
- 	printf("Summary:\n");
- 	printf("  Ftp like interface to dsk, do, po, and img files.\n");
- 	printf("  Defaults to Dos 3.3 filesystem on a dsk disk.\n");
  	exit(1);
  }
  
--- 283,296 ----
  
  static	void	print_help(void)
  {
! 	printf("useage:\n");
! 	printf("  aftp [options] <input_disk_files>\n");
  	printf("Options:\n");
  	printf("  -p  use a (P)rodos filesystem.\n");
  	printf("  -o  use a prodos (O)rdered image.\n");
  	printf("  -i  use an xgs image file.\n");
! 	printf("  -r  Load images as read-only.\n");
  	printf("  -?  Display aftp help.\n");
  	exit(1);
  }
  
***************
*** 327,332 ****
--- 324,330 ----
  				read_only = !read_only;
  				break;
  			case '?':
+ 			case 'h':
  				print_help();
  				break;
  			default:
***************
*** 373,378 ****
--- 371,377 ----
  					;
  				*p = '\0';
  				system(cmd + 1);
+ 				printf("\n") ;
  				continue;
  			}
  			for (; *p && !isspace(*p); p++)
***************
*** 386,392 ****
  			*p = '\0';
  			if (!*cmd)
  				continue;
! 			if (!strcmp(cmd, "dir"))
  			{
  				strcpy(remot, arg);
  				(*d->os->name)(remot, sizeof(remot));
--- 385,391 ----
  			*p = '\0';
  			if (!*cmd)
  				continue;
! 			if (!strcmp(cmd, "dir") || !strcmp(cmd, "ls"))
  			{
  				strcpy(remot, arg);
  				(*d->os->name)(remot, sizeof(remot));
***************
*** 503,508 ****
--- 502,508 ----
  			else if (!strcmp(cmd, "help") || !strcmp(cmd, "?"))
  			{
  				printf("dir           Display disk image directory.\n");
+ 				printf("ls            Alias for the dir command.\n");
  				printf("get [file]    Get a file from disk image.\n");
  				printf("put [file]    Put a file on disk image.\n");
  				printf("del [file]    Delete a file from disk image.\n");
***************
*** 511,520 ****
  				printf("mkdir [dir]   Create a disk image directory.\n");
  				printf("rmdir [dir]   Remove a disk image directory.\n");
  			#endif
  				printf("text          Set text mode.\n");
  				printf("binary        Set binary mode.\n");
  				printf("help          Display help.\n");
! 				printf("!dos command  Execute a dos command.\n");
  				printf("quit          Quit Program.\n");
  			}
  			else
--- 511,521 ----
  				printf("mkdir [dir]   Create a disk image directory.\n");
  				printf("rmdir [dir]   Remove a disk image directory.\n");
  			#endif
+ 				printf("dump          Display a hex dump of the disk image.\n") ;
  				printf("text          Set text mode.\n");
  				printf("binary        Set binary mode.\n");
  				printf("help          Display help.\n");
! 				printf("!command      Shell escape.\n");
  				printf("quit          Quit Program.\n");
  			}
  			else
