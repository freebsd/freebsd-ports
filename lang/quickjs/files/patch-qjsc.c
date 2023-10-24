--- qjsc.c.orig	2023-10-23 23:25:39 UTC
+++ qjsc.c
@@ -446,7 +446,7 @@ static int output_executable(const char *out_filename,
     if (dynamic_export)
         *arg++ = "-rdynamic";
     *arg++ = cfilename;
-    snprintf(libjsname, sizeof(libjsname), "%s/libquickjs%s%s.a",
+    snprintf(libjsname, sizeof(libjsname), "%s/libquickjs%s%s.so",
              lib_dir, bn_suffix, lto_suffix);
     *arg++ = libjsname;
     *arg++ = "-lm";
