--- zpaq.cpp.orig	2013-03-20 11:24:18.000000000 +0800
+++ zpaq.cpp	2013-03-20 11:26:23.000000000 +0800
@@ -147,7 +147,7 @@
 The default is to detect the number of processor cores and use that value
 or the limit according to -method, whichever is less. The number of cores
 is detected from the environment variable %NUMBER_OF_PROCESSORS% in
-Windows or /proc/cpuinfo in Linux.
+Windows or via sysconf(_SC_NPROCESSORS_ONLN) in Unix.
 
   -method M[n|e][C[N1][,N2]...]...
 
@@ -1090,25 +1090,7 @@
 int numberOfProcessors() {
   int rc=0;  // result
 #ifdef unix
-
-  // Count lines of the form "processor\t: %d\n" in /proc/cpuinfo
-  // where %d is 0, 1, 2,..., rc-1
-  FILE *in=fopen("/proc/cpuinfo", "r");
-  if (!in) return 1;
-  std::string s;
-  int c;
-  while ((c=getc(in))!=EOF) {
-    if (c>='A' && c<='Z') c+='a'-'A';  // convert to lowercase
-    if (c>' ') s+=c;  // remove white space
-    if (c=='\n') {  // end of line?
-      if (size(s)>10 && s.substr(0, 10)=="processor:") {
-        c=atoi(s.c_str()+10);
-        if (c==rc) ++rc;
-      }
-      s="";
-    }
-  }
-  fclose(in);
+  rc = sysconf(_SC_NPROCESSORS_ONLN);
 #else
 
   // In Windows return %NUMBER_OF_PROCESSORS%
