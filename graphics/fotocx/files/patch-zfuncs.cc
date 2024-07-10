--- zfuncs.cc.orig	2024-07-01 07:25:41 UTC
+++ zfuncs.cc
@@ -559,6 +559,7 @@ int zmalloc_test(int64 cc)
 
 double realmemory()
 {
+#if defined(__linux__)
    FILE     *fid;
    ch       buff[100], *pp;
    double   rmem = 0;
@@ -577,15 +578,45 @@ double realmemory()
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
@@ -610,6 +641,11 @@ double availmemory()
    }
 
    fclose(fid);
+#elif defined(__FreeBSD__)
+   double avmem;
+   avmem = realmemory();
+   avmem += freeswap();
+#endif
    return avmem;
 }
 
@@ -749,7 +785,7 @@ void zappcrash(ch *format, ... )
 
    uname(&unbuff);                                                               //  get cpu arch. 32/64 bit
    arch = unbuff.machine;
-   fid1 = popen("lsb_release -d","r");                                           //  get Linux flavor and release
+   fid1 = popen("uname -nv","r");
    if (fid1) {
       ii = fscanf(fid1,"%s %s %s",OS1,OS2,OS3);
       pclose(fid1);
@@ -1062,7 +1098,7 @@ double get_seconds()
    timespec    time1;
    double      secs;
 
-   clock_gettime(CLOCK_MONOTONIC_RAW,&time1);
+   clock_gettime(CLOCK_MONOTONIC,&time1);
    secs = time1.tv_sec;
    secs += time1.tv_nsec * 0.000000001;
    return secs;
@@ -1111,7 +1147,7 @@ void logtime_init(ch *text)
    using namespace logtime_names;
 
    printf("logtime init: %s\n",text);
-   clock_gettime(CLOCK_MONOTONIC_RAW,&time1);
+   clock_gettime(CLOCK_MONOTONIC,&time1);
    return;
 }
 
@@ -1119,7 +1155,7 @@ void logtime(ch *text)
 {
    using namespace logtime_names;
 
-   clock_gettime(CLOCK_MONOTONIC_RAW,&time2);
+   clock_gettime(CLOCK_MONOTONIC,&time2);
    elapsed = time2.tv_sec - time1.tv_sec;
    elapsed += 0.000000001 * (time2.tv_nsec - time1.tv_nsec);
    time1 = time2;
@@ -1808,6 +1844,10 @@ int wait_Jthread(pthread_t tid)
    return 0;
 }
 
+int get_nprocs()
+{
+   return sysconf(_SC_NPROCESSORS_ONLN);
+}
 
 /********************************************************************************/
 
@@ -1858,7 +1898,7 @@ void set_cpu_affinity(int cpu)
 {
    int         err;
    static int  ftf = 1, Nsmp;
-   cpu_set_t   cpuset;
+   cpuset_t    cpuset;
 
    if (ftf) {                                                                    //  first call
       ftf = 0;
@@ -1869,7 +1909,8 @@ void set_cpu_affinity(int cpu)
 
    CPU_ZERO(&cpuset);
    CPU_SET(cpu,&cpuset);
-   err = sched_setaffinity(0,sizeof(cpuset),&cpuset);
+   err = cpuset_setaffinity(CPU_LEVEL_WHICH,CPU_WHICH_PID,0,
+      sizeof(cpuset),&cpuset);
    if (err) Plog(2,"set_cpu_affinity() %s \n",strerror(errno));
    return;
 }
@@ -2182,7 +2223,7 @@ uint diskspace(ch *file)
    FILE     *fid;
 
    pp = zescape_quotes(file);
-   snprintf(command,200,"df --output=avail \"%s\" ",pp);
+   snprintf(command,200,"df -k '%s' | awk '{print $4}'",pp);
    zfree(pp);
 
    fid = popen(command,"r");
@@ -4050,14 +4091,18 @@ ch * SearchWildCase(ch *wpath, int &uflag)
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
+   int      globflags = 0;;
+#endif
    int      ii, jj, err, cc;
    glob_t   globdata;
    ch       *pp;
@@ -6028,9 +6073,16 @@ int zinitapp(ch *appvers, int argc, ch *argv[])       
    if (argc > 1 && strmatchV(argv[1],"-ver","-v",0)) exit(0);                    //  exit if nothing else wanted
 
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
 
    Plog(1,"program exe: %s \n",progexe);                                         //  executable path
