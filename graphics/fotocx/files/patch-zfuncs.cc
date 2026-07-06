--- zfuncs.cc.orig	2026-07-04 06:37:19 UTC
+++ zfuncs.cc
@@ -74,6 +74,8 @@
    samefolder              test if two files/folders have the same folder path
    parsefile               parse filespec into folder, file, extension
    renamez                 like rename() but works across file systems
+   get_nproc               get number of online CPUs in the system
+   get_prog_path           get our own executable program path
    check_create_dir        check if folder exists, ask to create if not
    cp_copy                 same, using shell "cp -f -p"
    diskspace               get available space on disk of given file, MB
@@ -503,6 +505,7 @@ int zmalloc_test(int64 cc)
 
 double realmemory()
 {
+#if defined(__linux__)
    FILE     *fid;
    ch       buff[100], *pp;
    double   rmem = 0;
@@ -521,15 +524,45 @@ double realmemory()
    }
 
    fclose(fid);
+#elif defined(__FreeBSD__)
+   long rmem;
+   rmem = sysconf(_SC_PAGESIZE) / 1024 * sysconf(_SC_PHYS_PAGES) / 1024;
+#endif
    return rmem;
 }
 
+#ifdef __FreeBSD__
+static int
+freeswap()	// return total free swap space in megabytes
+{
+   struct xswdev xsw;
+   size_t mibsize, size;
+   int mib[16], n, total;
 
+   mibsize = sizeof mib / sizeof mib[0];
+   if (sysctlnametomib("vm.swap_info", mib, &mibsize) == -1) {
+      perror("sysctlnametomib()");
+      return -1;
+   }
+
+   int pagesize = getpagesize() / 1024;
+   for (total = n = 0; ; ++n) {
+      mib[mibsize] = n;
+      size = sizeof xsw;
+      if (sysctl(mib, mibsize + 1, &xsw, &size, NULL, 0) == -1)
+         break;
+      total += pagesize * (xsw.xsw_nblks - xsw.xsw_used) / 1024;
+   }
+   return total;
+}
+#endif
+
 //  get available memory in MB units (includes swap space)
 //  typical < 0.1 milliseconds
 
 double availmemory()
 {
+#if defined(__linux__)
    FILE     *fid;
    ch       buff[100], *pp;
    double   avmem = 0;
@@ -554,6 +587,11 @@ double availmemory()
    }
 
    fclose(fid);
+#elif defined(__FreeBSD__)
+   double avmem;
+   avmem = realmemory();
+   avmem += freeswap();
+#endif
    return avmem;
 }
 
@@ -784,7 +822,7 @@ void zappcrash(ch *format, ... )
 
    uname(&unbuff);                                                                     //  get cpu arch. 32/64 bit
    arch = unbuff.machine;
-   fid1 = popen("lsb_release -d","r");                                                 //  get Linux flavor and release
+   fid1 = popen("uname -nv","r");
    if (fid1) {
       ii = fscanf(fid1,"%s %s %s",OS1,OS2,OS3);
       pclose(fid1);
@@ -817,9 +855,8 @@ void zappcrash(ch *format, ... )
    fprintf(fid2,"*** please send this crash report to mkornelix@gmail.com *** \n"
                 "*** if possible, please explain how to repeat this problem *** \n");
 
-   cc = readlink("/proc/self/exe",progexe,300);                                        //  get own program path
-   if (cc > 0) progexe[cc] = 0;                                                        //  readlink() quirk
-   else {
+   cc = get_prog_path(progexe, sizeof progexe);
+   if (cc == -1) {
       fprintf(fid2,"progexe not available \n");
       Flinenos = 0;
    }
@@ -1040,13 +1077,13 @@ double get_seconds(int init)
    static double  secs1 = 0, secs2, secs3;
 
    if (init == 0) {
-      clock_gettime(CLOCK_MONOTONIC_RAW,&time1);
+      clock_gettime(CLOCK_MONOTONIC,&time1);
       secs1 = time1.tv_sec;
       secs1 += time1.tv_nsec * 0.000000001;
       return secs1;
    }
    else {
-      clock_gettime(CLOCK_MONOTONIC_RAW,&time1);
+      clock_gettime(CLOCK_MONOTONIC,&time1);
       secs2 = time1.tv_sec;
       secs2 += time1.tv_nsec * 0.000000001;
       secs3 = secs2 - secs1;
@@ -1121,6 +1158,7 @@ double CPUtime()
 
 int memused()
 {
+#if defined(__linux__)
    ch       buff1[100], buff2[1000];
    ch       *pp = 0;
    FILE     *fid;
@@ -1147,6 +1185,10 @@ int memused()
    }
 
    return MB;
+#elif defined(__FreeBSD__)
+   struct rusage ru;
+   return getrusage(RUSAGE_SELF, &ru) ? 0 : (ru.ru_maxrss + 1023) / 1024;
+#endif
 }
 
 
@@ -2033,7 +2075,17 @@ int renamez(ch *file1, ch *file2)
    return err;
 }
 
+int get_nprocs()
+{
+   return sysconf(_SC_NPROCESSORS_ONLN);
+}
 
+int get_prog_path(char *buf, size_t len)
+{
+   const int mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1 };
+   return sysctl(mib, sizeof mib / sizeof mib[0], buf, &len, 0x0, 0);
+}
+
 /**************************************************************************************/
 
 //  Check if a folder exists. If not, ask user if it should be created.
@@ -2111,7 +2163,7 @@ uint diskspace(ch *file)
    FILE     *fid;
 
    pp = zescape_quotes(file);
-   snprintf(command,200,"df --output=avail \"%s\" ",pp);
+   snprintf(command,200,"df -k '%s' | awk '{print $4}'",pp);
    zfree(pp);
 
    fid = popen(command,"r");
@@ -3979,14 +4031,18 @@ ch * SearchWildCase(ch *wpath, int &uflag)
    flist and flist[*] are subjects for zfree().
 
    zfind() works for files containing quotes (")
-   dotfiles (/. and /..) are not included
+   dotfiles (/. and /..) are not included, if possible
 
 ***************************************************************************************/
 
 int zfind(ch *pattern, ch **&flist, int &NF)
 {
    ch       **zfind_filelist = 0;                                                      //  list of filespecs returned
+#ifdef GLOB_PERIOD
    int      globflags = GLOB_PERIOD;                                                   //  include dotfiles
+#else
+   int      globflags = 0;
+#endif
    int      ii, jj, err, cc;
    glob_t   globdata;
    ch       *pp;
@@ -6014,9 +6070,8 @@ int zinitapp(ch *appvers, int argc, ch *argv[])       
    if (argc > 1 && strmatchV(argv[1],"-ver","-v",null)) exit(0);                       //  exit if nothing else wanted
 
    progexe = 0;
-   cc = readlink("/proc/self/exe",buff,300);                                           //  get my executable program path
-   if (cc <= 0) zexit(1,"readlink() /proc/self/exe) failed");
-   buff[cc] = 0;                                                                       //  readlink() quirk
+   cc = get_prog_path(buff, sizeof buff);
+   if (cc == -1) zexit(1, "could not obtain program path");
    progexe = zstrdup(buff,"zinitapp");
 
    printf("program exe: %s \n",progexe);                                               //  executable path
@@ -8054,8 +8109,7 @@ GtkWidget * add_toolbar_button(GtkWidget *wtbar, ch *b
       strncatv(iconpath,199,zimagedir,"/",icon,null);
       err = stat(iconpath,&statB);
       if (err) {                                                                       //  alternative path
-         cc = readlink("/proc/self/exe",iconpath,300);                                 //  get own program path
-         if (cc > 0) iconpath[cc] = 0;                                                 //  readlink() quirk
+         (void)get_prog_path(iconpath, sizeof iconpath);
          pp = strrchr(iconpath,'/');                                                   //  folder of program
          if (pp) *pp = 0;
          strncatv(iconpath,300,"/icons/",icon,null);                                   //  .../icons/iconfile.png
