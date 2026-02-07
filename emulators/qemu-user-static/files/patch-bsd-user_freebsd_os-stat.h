--- bsd-user/freebsd/os-stat.h.orig
+++ bsd-user/freebsd/os-stat.h
@@ -702,7 +702,7 @@
         return -TARGET_EFAULT;
     }
 
-    ret = get_errno(__realpathat(arg1, p, b, arg4, arg5));
+    ret = get_errno(__sys___realpathat(arg1, p, b, arg4, arg5));
     UNLOCK_PATH(p, arg2);
     unlock_user(b, arg3, ret);
 
