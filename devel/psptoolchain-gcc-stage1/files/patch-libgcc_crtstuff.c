--- libgcc/crtstuff.c.orig	2014-03-10 18:31:20 UTC
+++ libgcc/crtstuff.c
@@ -47,7 +47,7 @@ see the files COPYING3 and COPYING.RUNTIME respectivel
 
 /* Target machine header files require this define. */
 #define IN_LIBGCC2
-
+#define USED_FOR_TARGET
 /* FIXME: Including auto-host is incorrect, but until we have
    identified the set of defines that need to go into auto-target.h,
    this will have to do.  */
