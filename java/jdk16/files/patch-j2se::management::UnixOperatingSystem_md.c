$FreeBSD$

--- ../../j2se/src/solaris/native/com/sun/management/UnixOperatingSystem_md.c.orig Sat Feb 19 12:50:03 2005
+++ ../../j2se/src/solaris/native/com/sun/management/UnixOperatingSystem_md.c    Fri Feb 18 20:26:04 2005
@@ -283,7 +283,7 @@
 
     mib[0] = CTL_HW;
     mib[1] = HW_PHYSMEM;
-    rlen = sizof(result);
+    rlen = sizeof(result);
     if (sysctl(mib, 2, &result, &rlen, NULL, 0) == -1)
        result = 256 * MB;

