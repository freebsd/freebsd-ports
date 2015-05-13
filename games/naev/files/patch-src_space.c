# Origin: https://github.com/naev/naev/commit/173bad4a7bab85903575798a51259ff6f3dd42c8
# Subject: Memory leak fix

--- src/space.c.orig	2015-02-16 17:49:03 UTC
+++ src/space.c
@@ -2978,6 +2978,7 @@ void space_exit (void)
       free(pnt->land_func);
       free(pnt->land_msg);
       free(pnt->bribe_msg);
+      free(pnt->bribe_ack_msg);
 
       /* tech */
       if (pnt->tech != NULL)
