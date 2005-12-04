--- ../pr/src/misc/prsystem.c.orig	Fri May  6 20:35:58 2005
+++ ../pr/src/misc/prsystem.c	Sun Dec  4 22:09:51 2005
@@ -352,6 +352,19 @@ PR_IMPLEMENT(PRUint64) PR_GetPhysicalMem
         odm_terminate();
     }
 
+#elif defined(__FreeBSD__)
+
+    int mib[2];
+    unsigned long physmem;
+    size_t len;
+    
+    mib[0] = CTL_HW;
+    mib[1] = HW_PHYSMEM;
+    len = sizeof(physmem);
+    if(sysctl(mib, 2, &physmem, &len, NULL, 0) == 0
+        && len == sizeof(physmem))
+      bytes = physmem;
+
 #else
 
     PR_SetError(PR_NOT_IMPLEMENTED_ERROR, 0);
