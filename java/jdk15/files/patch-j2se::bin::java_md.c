--- ../../j2se/src/solaris/bin/java_md.c.orig	Thu May 24 19:15:46 2007
+++ ../../j2se/src/solaris/bin/java_md.c	Thu May 24 19:14:59 2007
@@ -1061,7 +1061,8 @@
 #if defined(_ALLBSD_SOURCE)
 
   uint64_t result;
-  int mib[2], rlen;
+  int mib[2];
+  size_t rlen;
 
   /* fetch sysctl(hw.physmem) value */
   mib[0] = CTL_HW;
@@ -1635,7 +1636,7 @@
     while (dp != NULL) {
 	cp = strchr(dp, (int)':');
 	if (cp != NULL)
-	    *cp = (char)NULL;
+	    *cp = '\0';
 	if ((target = ProcessDir(info, dp)) != NULL)
 	    break;
 	dp = cp;
