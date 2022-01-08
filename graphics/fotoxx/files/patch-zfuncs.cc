--- zfuncs.cc.orig	2021-10-17 20:02:26 UTC
+++ zfuncs.cc
@@ -551,6 +551,7 @@ int zmalloc_test(int64 cc)
 
 double realmemory()                                                              //  21.55
 {
+#if defined(__linux__)
    FILE     *fid;
    char     buff[100], *pp;
    double   rmem = 0;
@@ -569,15 +570,45 @@ double realmemory()                                   
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
 //  get available memory in MB units
 //  typical < 0.1 milliseconds
 
 double availmemory()
 {
+#if defined(__linux__)
    FILE     *fid;
    char     buff[100], *pp;
    double   avmem = 0;
@@ -602,6 +633,11 @@ double availmemory()
    }
 
    fclose(fid);
+#elif defined(__FreeBSD__)
+   double avmem;
+   avmem = realmemory();
+   avmem += freeswap();
+#endif
    return avmem;
 }
 
@@ -996,7 +1032,7 @@ double get_seconds()
    timespec    time1;
    double      time2;
    
-   clock_gettime(CLOCK_MONOTONIC_RAW,&time1);
+   clock_gettime(CLOCK_MONOTONIC,&time1);
    time2 = time1.tv_sec;
    time2 += time1.tv_nsec * 0.000000001;
    return time2;
@@ -1020,7 +1056,7 @@ void logtime_init(cchar *text)
    using namespace logtime_names;
 
    printf("logtime init: %s\n",text);
-   clock_gettime(CLOCK_MONOTONIC_RAW,&time1);
+   clock_gettime(CLOCK_MONOTONIC,&time1);
    return;
 }
 
@@ -1028,7 +1064,7 @@ void logtime(cchar *text)
 {
    using namespace logtime_names;
 
-   clock_gettime(CLOCK_MONOTONIC_RAW,&time2);
+   clock_gettime(CLOCK_MONOTONIC,&time2);
    elapsed = time2.tv_sec - time1.tv_sec;
    elapsed += 0.000000001 * (time2.tv_nsec - time1.tv_nsec);
    time1 = time2;
@@ -1649,6 +1685,10 @@ int main_thread()                                     
    return 0;
 }
 
+int get_nprocs()
+{
+   return sysconf(_SC_NPROCESSORS_ONLN);
+}
 
 /********************************************************************************/
 
@@ -1659,7 +1699,7 @@ void set_cpu_affinity(int cpu)
 {
    int         err;
    static int  ftf = 1, Nsmp;
-   cpu_set_t   cpuset;
+   cpuset_t    cpuset;
 
    if (ftf) {                                                                    //  first call
       ftf = 0;
@@ -1670,7 +1710,8 @@ void set_cpu_affinity(int cpu)
 
    CPU_ZERO(&cpuset);
    CPU_SET(cpu,&cpuset);
-   err = sched_setaffinity(0,sizeof(cpuset),&cpuset);
+   err = cpuset_setaffinity(CPU_LEVEL_WHICH,CPU_WHICH_PID,0,
+      sizeof(cpuset),&cpuset);
    if (err) Plog(1,"set_cpu_affinity() %s \n",strerror(errno));
    return;
 }
@@ -2234,7 +2275,7 @@ int diskspace(cchar *file)                            
    int      avail;
    FILE     *fid;
 
-   snprintf(command,200,"df --output=avail \"%s\" ",file);
+   snprintf(command,200,"df -k '%s' | awk '{print $4}'",file);
    pp = strchr(command,'/');
    if (! pp) return 0;
    
@@ -4115,14 +4156,18 @@ cchar * SearchWildCase(cchar *wpath, int &uflag) 
    flist and flist[*] are subjects for zfree().
 
    zfind() works for files containing quotes (")
-   dotfiles (/. and /..) are not included
+   dotfiles (/. and /..) are not included, if possible
 
 *********************************************************************************/
 
 int zfind(cchar *pattern, char **&flist, int &NF)
 {
    char     **zfind_filelist = 0;                                                //  list of filespecs returned
+#ifdef GLOB_PERIOD
    int      globflags = GLOB_PERIOD;                                             //  include dotfiles
+#else
+   int      globflags = 0;;
+#endif
    int      ii, jj, err, cc;
    glob_t   globdata;
    char     *pp;
@@ -5805,9 +5850,16 @@ int zinitapp(cchar *appvers, int argc, char *argv[])  
    if (argc > 1 && strmatchV(argv[1],"-ver","-v",0)) exit(0);                    //  exit if nothing else wanted
 
    progexe = 0;   
+#if defined(__linux__)
    cc = readlink("/proc/self/exe",buff,300);                                     //  get my executable program path
    if (cc <= 0) zexit("readlink() /proc/self/exe) failed");
    buff[cc] = 0;                                                                 //  readlink() quirk
+#elif defined(__FreeBSD__)
+   const int mib[4] = { CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1 };
+   size_t len = sizeof(buff);
+   cc = sysctl(mib, 4, buff, &len, 0x0, 0);
+   if (cc == -1) zexit("sysctl(KERN_PROC_PATHNAME) failed");
+#endif
    progexe = zstrdup(buff,"zinitapp");
 
    err = appimage_install(zappname);                                             //  if appimage, menu integration
