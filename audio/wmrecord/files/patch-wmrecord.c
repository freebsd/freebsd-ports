*** wmrecord.c.orig	Mon Apr  2 03:48:28 2001
--- wmrecord.c	Mon Apr  2 03:49:58 2001
***************
*** 320,326 ****
--- 320,330 ----
    sprintf(q, "%s%s%02d.wav",pd->pw_dir, BASEFILE, tracknum);
    /* Open the source file, where the recording has been stored. */
    p = (char *)malloc(sizeof(char)*4);
+ #ifdef __FreeBSD__
+   if ((fd=open(q, O_RDONLY))==-1)
+ #else
    if ((fd=open(q, O_RDONLY|O_SYNC))==-1)
+ #endif
      sprintf(p, "000");
    else {
      datalen = wmGetWavSettings(fd);
***************
*** 755,761 ****
--- 759,769 ----
    pw = getpwuid(uid);
    fres=(char *)malloc(sizeof(char)*(strlen(pw->pw_dir)+strlen(BASEFILE)+7));
    sprintf(fres, "%s%s%02d.wav",pw->pw_dir, BASEFILE, tracknum);
+ #ifdef __FreeBSD__
+   if ((fd=open(fres,O_RDONLY))==-1) {
+ #else
    if ((fd=open(fres,O_RDONLY|O_SYNC))==-1) {
+ #endif
      fprintf(stderr, "WMRECORD: Could not open source file.\n");
      free(fres);
      copyXPMArea (btn[2].x, btn[2].y, btn[2].w, btn[2].h,
