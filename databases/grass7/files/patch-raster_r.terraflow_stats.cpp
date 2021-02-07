--- raster/r.terraflow/stats.cpp.orig	2020-12-21 18:40:15 UTC
+++ raster/r.terraflow/stats.cpp
@@ -126,44 +126,7 @@ statsRecorder::statsRecorder(char *fname) : ofstream(n
   //ofstream that takes an fd; wrote another noclobber() function that
   //closes fd and returns the name;
   rt_start(tm);
-#ifndef __MINGW32__
-  bss = sbrk(0);
-#endif
-  char buf[BUFSIZ];
-  *this << freeMem(buf) << endl;
 }
-
-/* ********************************************************************** */
-
-long 
-statsRecorder::freeMem() {
-#ifdef __MINGW32__
-  return -1;
-#else
-  struct rlimit rlim;
-  if (getrlimit(RLIMIT_DATA, &rlim) == -1) {
-	perror("getrlimit: ");
-	return -1;
-  } 	
-  /* printf("getrlimit returns: %d \n", rlim.rlim_cur); */
-  if (rlim.rlim_cur == RLIM_INFINITY) {
-	/* printf("rlim is infinity\n"); */
-	/* should fix this */
-	return -1; 
-  } 
-  long freeMem = rlim.rlim_cur - ((char*)sbrk(0)-(char*)bss);
-  return freeMem;
-#endif /* __MINGW32__ */
-}
-
-char *
-statsRecorder::freeMem(char *buf) {
-  char buf2[BUFSIZ];
-  sprintf(buf, "Free Memory=%s", formatNumber(buf2, freeMem()));
-  return buf;
-}
-
-
 
 /* ********************************************************************** */
 
