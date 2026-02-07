--- vdumper/dump-vtable.c.orig	2016-10-04 16:28:00 UTC
+++ vdumper/dump-vtable.c
@@ -355,11 +355,11 @@ void print_VTable(void *dlhndl, vtable_i
             {
                 if ((ptrdiff_t)vfuncp < 0)
                 {
-                    printf("(int (*)(...)) -%016p\n", (void*) -(ptrdiff_t)vfuncp);
+                    printf("(int (*)(...)) -%16p\n", (void*) -(ptrdiff_t)vfuncp);
                 }
                 else
                 {
-                    printf("(int (*)(...)) %016p\n", vfuncp);
+                    printf("(int (*)(...)) %16p\n", vfuncp);
                 }
             }
         }
