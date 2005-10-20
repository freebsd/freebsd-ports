--- coregrind/vg_main.c.orig	Sun May  9 13:00:57 2004
+++ coregrind/vg_main.c	Thu Oct 20 13:05:13 2005
@@ -1286,6 +1286,7 @@
 
 static const char* find_executable(const char* exec)
 {
+   int found=0;
    vg_assert(NULL != exec);
    if (strchr(exec, '/') == NULL) {
       /* no '/' - we need to search the path */
@@ -1304,12 +1305,18 @@
          if (access(buf, R_OK|X_OK) == 0) {
             exec = strdup(buf);
             vg_assert(NULL != exec);
+	    found=1;
             return 1;
          }
          return 0;
       }
       scan_colsep(path, match_exe);
+   } else if (access(exec, R_OK|X_OK) == 0) {
+      found = 1;
    }
+   if (!found)
+      return 0;
+
    return exec;
 }
 
