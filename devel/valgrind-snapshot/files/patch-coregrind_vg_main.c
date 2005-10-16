--- coregrind/vg_main.c.orig	Tue Sep 20 02:21:16 2005
+++ coregrind/vg_main.c	Tue Sep 20 02:22:29 2005
@@ -1286,6 +1286,7 @@
 
 static const char* find_executable(const char* exec)
 {
+   int found=0;
    vg_assert(NULL != exec);
    if (strchr(exec, '/') == NULL) {
       /* no '/' - we need to search the path */
@@ -1304,12 +1305,16 @@
          if (access(buf, R_OK|X_OK) == 0) {
             exec = strdup(buf);
             vg_assert(NULL != exec);
+	    found=1;
             return 1;
          }
          return 0;
       }
       scan_colsep(path, match_exe);
    }
+   if (!found)
+      return 0;
+
    return exec;
 }
 
