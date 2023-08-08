There are two strerror_r impementations,

int strerror_r(int errnum, char *buf, size_t buflen); /* XSI-compliant */
char *strerror_r(int errnum, char *buf, size_t buflen); /* GNU-specific */

FreeBSD only uses the former, while Linux may use either depending
on compiler flags. I haven't figured out how to check for this
correctly, so just use right version on FreeBSD for now.

--- src/nomos/agent/nomos.c.orig	2022-11-15 10:13:05 UTC
+++ src/nomos/agent/nomos.c
@@ -309,16 +309,26 @@ int main(int argc, char **argv)
 
   if (putenv("LANG=C") < 0)
   {
+#if defined(__FreeBSD__)
+    strerror_r(errno, sErrorBuf, sizeof(sErrorBuf));
+    LOG_FATAL("Cannot set LANG=C in environment.  Error: %s", sErrorBuf)
+#else
     char * estr = strerror_r(errno, sErrorBuf, sizeof(sErrorBuf));
     LOG_FATAL("Cannot set LANG=C in environment.  Error: %s", estr)
+#endif
     Bail(-__LINE__);
   }
 
   /* Save the current directory */
   if (getcwd(gl.initwd, sizeof(gl.initwd)) == NULL_STR)
   {
+#if defined(__FreeBSD__)
+    strerror_r(errno, sErrorBuf, sizeof(sErrorBuf));
+    LOG_FATAL("Cannot obtain starting directory.  Error: %s", sErrorBuf)
+#else
     char *estr = strerror_r(errno, sErrorBuf, sizeof(sErrorBuf));
     LOG_FATAL("Cannot obtain starting directory.  Error: %s", estr)
+#endif
     Bail(-__LINE__);
   }
 
