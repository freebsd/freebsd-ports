
$FreeBSD$

--- unace.c.orig
+++ unace.c
@@ -240,6 +240,7 @@
 INT  open_archive(INT print_err)        // opens archive (or volume)
 {
    CHAR av_str[80];
+   unsigned int copylen;
 
    archan = open(aname, O_RDONLY | O_BINARY);   // open file
 
@@ -263,8 +264,11 @@
       sprintf(av_str, "\ncreated on %d.%d.%d by ",
               ts_day(adat.time_cr), ts_month(adat.time_cr), ts_year(adat.time_cr));
       printf(av_str);
-      strncpy(av_str, mhead.AV, mhead.AV_SIZE);
-      av_str[mhead.AV_SIZE] = 0;
+      copylen = mhead.AV_SIZE;
+      if (copylen > 79)
+        copylen = 79;
+      strncpy(av_str, mhead.AV, copylen);
+      av_str[copylen] = 0;
       printf("%s\n\n", av_str);
    }
    comment_out("Main comment:");        // print main comment
@@ -300,7 +304,7 @@
 INT  proc_vol(void)                     // opens volume
 {
    INT  i;
-   CHAR s[80];
+   CHAR s[PATH_MAX + 80];
 
    // if f_allvol_pr is 2 we have -y and should never ask
    if ((!fileexists_insense(aname) && f_allvol_pr != 2) || !f_allvol_pr)
@@ -428,7 +432,7 @@
       if (head.HEAD_TYPE == FILE_BLK)
       {
          comment_out("File comment:");   // show file comment
-         ace_fname(file, &head, nopath); // get file name
+         ace_fname(file, &head, nopath, sizeof(file)); // get file name
          printf("\n%s", file);
          flush;
          dcpr_init_file();               // initialize decompression of file
@@ -496,7 +500,7 @@
       if (head.HEAD_TYPE == FILE_BLK)
       {
          ULONG ti=fhead.FTIME;
-         ace_fname(file, &head, verbose ? 0 : 1); // get file name
+         ace_fname(file, &head, verbose ? 0 : 1, sizeof(file)); // get file name
 
          size  += fhead.SIZE;
          psize +=
@@ -588,7 +592,8 @@
 
       init_unace();                              // initialize unace
 
-      strcpy(aname, argv[arg_cnt]);              // get archive name
+      strncpy(aname, argv[arg_cnt], sizeof(aname) - 4);  // get archive name
+      aname[sizeof(aname) - 5] = '\0';
       if (!(s = (CHAR *) strrchr(aname, DIRSEP)))
          s = aname;
       if (!strrchr(s, '.'))
