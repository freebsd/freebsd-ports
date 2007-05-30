--- ../../j2se/src/solaris/bin/java_md.c.orig	Fri May 25 21:49:14 2007
+++ ../../j2se/src/solaris/bin/java_md.c	Wed May 30 17:00:23 2007
@@ -1060,8 +1060,9 @@
 
 #if defined(_ALLBSD_SOURCE)
 
-  uint64_t result;
-  int mib[2], rlen;
+  unsigned long result;
+  int mib[2];
+  size_t rlen;
 
   /* fetch sysctl(hw.physmem) value */
   mib[0] = CTL_HW;
@@ -1342,10 +1343,11 @@
 
 #if defined(_ALLBSD_SOURCE)
 
-  unsigned long result, sys_processors;
-  int mib[2], rlen;
+  unsigned long sys_processors;
+  int mib[2], result;
+  size_t rlen;
 
-  /* fetch sysctl(hw.physmem) value */
+  /* fetch sysctl(hw.ncpu) value */
   mib[0] = CTL_HW;
   mib[1] = HW_NCPU;
   rlen = sizeof(result);
@@ -1354,7 +1356,7 @@
 	result = 1;
 
   if (_launcher_debug) {
-    printf("sysctl(hw.ncpu): %lu\n", result);
+    printf("sysctl(hw.ncpu): %d\n", result);
   }
 
   sys_processors = result;
@@ -1635,7 +1637,7 @@
     while (dp != NULL) {
 	cp = strchr(dp, (int)':');
 	if (cp != NULL)
-	    *cp = (char)NULL;
+	    *cp = '\0';
 	if ((target = ProcessDir(info, dp)) != NULL)
 	    break;
 	dp = cp;
