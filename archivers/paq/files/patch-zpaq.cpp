--- zpaq.cpp.orig	2016-07-26 12:11:37 UTC
+++ zpaq.cpp
@@ -1236,24 +1236,7 @@ int numberOfProcessors() {
   int rc=0;  // result
 #ifdef unix
 
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
+  rc=(int)sysconf(_SC_NPROCESSORS_ONLN);
 #else
 
   // In Windows return %NUMBER_OF_PROCESSORS%
