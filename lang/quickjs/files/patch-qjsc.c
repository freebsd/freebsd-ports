--- qjsc.c.orig	2025-10-18 10:04:12 UTC
+++ qjsc.c
@@ -498,7 +498,7 @@ static int output_executable(const char *out_filename,
     if (dynamic_export)
         *arg++ = "-rdynamic";
     *arg++ = cfilename;
-    snprintf(libjsname, sizeof(libjsname), "%s/libquickjs%s%s.a",
+    snprintf(libjsname, sizeof(libjsname), "%s/libquickjs%s%s.so",
              lib_dir, bn_suffix, lto_suffix);
     *arg++ = libjsname;
     *arg++ = "-lm";
