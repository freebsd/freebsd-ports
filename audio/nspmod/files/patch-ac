*** nspmod.c.orig	Wed Sep  3 14:58:19 1997
--- nspmod.c	Wed Sep  3 14:55:06 1997
***************
*** 1,4 ****
--- 1,5 ----
  #include <stdio.h>	/*(perror)*/
+ #include <sys/types.h>
  #include <sys/mman.h>	/*PROT_READ,MAP_xxx*/
  #include <fcntl.h>	/*O_RDONLY*/
  #include <sys/stat.h>	/*stat*/
***************
*** 35,40 ****
--- 36,42 ----
      printf("NSPmod version " LIT(VERSION_MAJOR) "." LIT(VERSION_MINOR) "\n");
      printf("Usage: %s [options] modfile\n", argv0);
      printf("Options:\n");
+     printf(" -b #  number of bits to output (8 or 16)\n");
      printf(" -c #  play only the channel\n");
      printf(" -e    show events\n");
      printf(" -f #  output sample rate\n");
***************
*** 62,69 ****
      oi.outRate = DEF_OUTRATE;
      oi.ovsFreq = -1;
      /*oi.repLimit = 1;*/
!     while ((optChar = getopt(argc, argv, "c:ef:il:mo:rs:v:")) > 0) {
  	switch (optChar) {
  	case 'c': oi.onlyCh = (i15x)strtol(optarg, NULL, 0) | 0x100; break;
  	case 'e': oi.showEvents++; break;
  	case 'f': oi.outRate = (u16x)strtol(optarg, NULL, 0); break;
--- 64,72 ----
      oi.outRate = DEF_OUTRATE;
      oi.ovsFreq = -1;
      /*oi.repLimit = 1;*/
!     while ((optChar = getopt(argc, argv, "b:c:ef:il:mo:rs:v:")) > 0) {
  	switch (optChar) {
+ 	case 'b': oi.bits = (i15x)strtol(optarg, NULL, 0); break;
  	case 'c': oi.onlyCh = (i15x)strtol(optarg, NULL, 0) | 0x100; break;
  	case 'e': oi.showEvents++; break;
  	case 'f': oi.outRate = (u16x)strtol(optarg, NULL, 0); break;
***************
*** 116,121 ****
--- 119,125 ----
  
      lookOverFile(p, statbuf.st_size);
      dacioInit();
+     dci.bits = oi.bits;
      dci.speed = oi.outRate;
      dci.stereo = !oi.mono;
      dacioConf(&dci);
