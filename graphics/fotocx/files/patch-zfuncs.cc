--- zfuncs.cc.orig	2025-11-18 09:44:35 UTC
+++ zfuncs.cc
@@ -490,6 +490,7 @@ int zmalloc_test(int64 cc)
 
 double realmemory()
 {
+#if defined(__linux__)
    FILE     *fid;
    ch       buff[100], *pp;
    double   rmem = 0;
@@ -508,15 +509,45 @@ double realmemory()
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
@@ -541,6 +572,11 @@ double availmemory()
    }
 
    fclose(fid);
+#elif defined(__FreeBSD__)
+   double avmem;
+   avmem = realmemory();
+   avmem += freeswap();
+#endif
    return avmem;
 }
 
@@ -793,7 +829,7 @@ void zappcrash(ch *format, ... )
 
    uname(&unbuff);                                                               //  get cpu arch. 32/64 bit
    arch = unbuff.machine;
-   fid1 = popen("lsb_release -d","r");                                           //  get Linux flavor and release
+   fid1 = popen("uname -nv","r");
    if (fid1) {
       ii = fscanf(fid1,"%s %s %s",OS1,OS2,OS3);
       pclose(fid1);
@@ -1049,13 +1085,13 @@ double get_seconds(int init)
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
@@ -1977,6 +2013,10 @@ int samefolder(ch *file1, ch *file2)
    return 0;
 }
 
+int get_nprocs()
+{
+   return sysconf(_SC_NPROCESSORS_ONLN);
+}
 
 /********************************************************************************/
 
@@ -2147,7 +2187,7 @@ uint diskspace(ch *file)
    FILE     *fid;
 
    pp = zescape_quotes(file);
-   snprintf(command,200,"df --output=avail \"%s\" ",pp);
+   snprintf(command,200,"df -k '%s' | awk '{print $4}'",pp);
    zfree(pp);
 
    fid = popen(command,"r");
@@ -3999,14 +4039,18 @@ ch * SearchWildCase(ch *wpath, int &uflag)
    flist and flist[*] are subjects for zfree().
 
    zfind() works for files containing quotes (")
-   dotfiles (/. and /..) are not included
+   dotfiles (/. and /..) are not included, if possible
 
 *********************************************************************************/
 
 int zfind(ch *pattern, ch **&flist, int &NF)
 {
    ch       **zfind_filelist = 0;                                                //  list of filespecs returned
+#ifdef GLOB_PERIOD
    int      globflags = GLOB_PERIOD;                                             //  include dotfiles
+#else
+   int      globflags = 0;
+#endif
    int      ii, jj, err, cc;
    glob_t   globdata;
    ch       *pp;
@@ -6033,9 +6077,16 @@ int zinitapp(ch *appvers, int argc, ch *argv[])       
    if (argc > 1 && strmatchV(argv[1],"-ver","-v",null)) exit(0);                 //  exit if nothing else wanted
 
    progexe = 0;
+#if defined(__linux__)
    cc = readlink("/proc/self/exe",buff,300);                                     //  get my executable program path
    if (cc <= 0) zexit(1,"readlink() /proc/self/exe) failed");
    buff[cc] = 0;                                                                 //  readlink() quirk
+#elif defined(__FreeBSD__)
+   const int mib[4] = { CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1 };
+   size_t len = sizeof(buff);
+   cc = sysctl(mib, 4, buff, &len, 0x0, 0);
+   if (cc == -1) zexit(1,"sysctl(KERN_PROC_PATHNAME) failed");
+#endif
    progexe = zstrdup(buff,"zinitapp");
 
    printf("program exe: %s \n",progexe);                                         //  executable path
