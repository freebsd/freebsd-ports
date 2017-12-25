--- src/cl_program.c.orig	2017-09-22 08:59:52 UTC
+++ src/cl_program.c
@@ -861,9 +861,8 @@ cl_program_compile(cl_program            p,
     p->opaque = compiler_program_compile_from_source(p->ctx->devices[0]->device_id, p->source, temp_header_path,
         p->build_log_max_sz, options, p->build_log, &p->build_log_sz);
 
-    char rm_path[255]="rm ";
+    char rm_path[255]="rm -rf ";
     strncat(rm_path, temp_header_path, strlen(temp_header_path));
-    strncat(rm_path, " -rf", 4);
     int temp = system(rm_path);
 
     if(temp){
