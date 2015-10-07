--- vm/builtin/io.cpp.orig
+++ vm/builtin/io.cpp
@@ -165,7 +165,7 @@
 
         // 1024 is selec't limit. If we try to set a value higher, it corrupts
         // memory. YAY FD_SET!
-        if(descriptor >= FD_SETSIZE) return -2;
+        if(descriptor >= (int_fd_t)FD_SETSIZE) return -2;
         highest = descriptor > highest ? descriptor : highest;
 
         if(descriptor >= 0) FD_SET((int_fd_t)descriptor, set);
