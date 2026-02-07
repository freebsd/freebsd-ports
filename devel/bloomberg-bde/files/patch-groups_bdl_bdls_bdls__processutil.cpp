--- groups/bdl/bdls/bdls_processutil.cpp.orig	2023-08-03 21:58:43 UTC
+++ groups/bdl/bdls/bdls_processutil.cpp
@@ -48,6 +48,7 @@ BSLS_IDENT_RCSID(bdls_processutil_cpp,"$Id$ $CSID$")
 #   include <errno.h>            // ::program_invocation_name
 # elif defined BSLS_PLATFORM_OS_SOLARIS
 #   include <bsl_fstream.h>
+# elif defined(BSLS_PLATFORM_OS_FREEBSD)
 # else
 #   error Unrecognized Platform
 # endif
@@ -114,7 +115,8 @@ bool isExecutable(const char *path)
     const int executableBits = S_IXUSR | S_IXGRP | S_IXOTH;
 
 # if defined(BSLS_PLATFORM_OS_CYGWIN) || \
-    (defined(BSLS_PLATFORM_OS_DARWIN) && defined(_DARWIN_FEATURE_64_BIT_INODE))
+    (defined(BSLS_PLATFORM_OS_DARWIN) && defined(_DARWIN_FEATURE_64_BIT_INODE)) || \
+    defined(BSLS_PLATFORM_OS_FREEBSD)
     struct stat s;
     int rc = ::stat(path, &s);
 # else
@@ -245,14 +247,17 @@ int ProcessUtil::getProcessName(bsl::string *result)
     result->assign(pidPathBuf.c_str(), numChars);
     return 0;
 
-#elif defined BSLS_PLATFORM_OS_LINUX
+#elif defined BSLS_PLATFORM_OS_LINUX || defined(BSLS_PLATFORM_OS_FREEBSD)
 
     // We read '::program_invocation_name', which will just yield 'argv[0]',
     // which may or may not be a relative path.  Note that this will still
     // correctly handle the case where the path of the executable contains
     // spaces.
-
+#if defined(BSLS_PLATFORM_OS_FREEBSD)
+    const char *argv0 = getprogname();
+#else
     const char *argv0 = ::program_invocation_name;
+#endif
     if (!argv0 || !*argv0) {
         U_LOG_ERROR_ONCE("bdls::ProcessUtil: ::program_invocation_name"
                                                                 " failed.  %s",
