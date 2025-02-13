--- qjsc.c.orig	2024-07-27 21:40:48 UTC
+++ qjsc.c
@@ -445,7 +445,7 @@ static int output_executable(const char *out_filename,
     if (dynamic_export)
         *arg++ = "-rdynamic";
     *arg++ = cfilename;
-    snprintf(libjsname, sizeof(libjsname), "%s/libquickjs%s%s.a",
+    snprintf(libjsname, sizeof(libjsname), "%s/libquickjs%s%s.so",
              lib_dir, bn_suffix, lto_suffix);
     *arg++ = libjsname;
     *arg++ = "-lm";
