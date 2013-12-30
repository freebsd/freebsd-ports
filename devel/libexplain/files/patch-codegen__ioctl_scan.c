--- codegen/ioctl_scan.c.orig
+++ codegen/ioctl_scan.c
@@ -40,6 +40,10 @@
 #include <codegen/ioctl_scan.h>
 #include <codegen/wrapper.h>
 
+#ifndef FTW_ACTIONRETVAL
+#define FTW_CONTINUE 0
+#endif
+
 
 static void
 regcomp_or_die(regex_t *preg, const char *regex, int cflags)
@@ -306,6 +310,7 @@
 {
     (void)typeflag;
     (void)ftwbuf;
+#ifdef FTW_ACTIONRETVAL
     if (typeflag == FTW_D)
     {
        explain_output_error("walking %s\n", pathname);
@@ -314,6 +319,7 @@
        if (ends_with(pathname, "/.."))
            return FTW_SKIP_SUBTREE;
     }
+#endif
     if (S_ISREG(st->st_mode) && ends_with(pathname , ".h"))
         ioctl_scan_include(pathname);
     return FTW_CONTINUE;
