--- src/VBox/Runtime/r3/posix/utf8-posix.cpp.orig	2015-04-14 15:41:38.000000000 -0400
+++ src/VBox/Runtime/r3/posix/utf8-posix.cpp	2015-04-15 12:50:21.401092000 -0400
@@ -194,7 +194,7 @@
             const void *pvInputLeft = pvInput;
             void       *pvOutputLeft = pvOutput;
             size_t      cchNonRev;
-#if defined(RT_OS_LINUX) || defined(RT_OS_HAIKU) || defined(RT_OS_SOLARIS) || (defined(RT_OS_DARWIN) && defined(_DARWIN_FEATURE_UNIX_CONFORMANCE)) /* there are different opinions about the constness of the input buffer. */
+#if defined(RT_OS_LINUX) || defined(RT_OS_HAIKU) || defined(RT_OS_FREEBSD) || defined(RT_OS_DRAGONFLY) || defined(RT_OS_SOLARIS) || (defined(RT_OS_DARWIN) && defined(_DARWIN_FEATURE_UNIX_CONFORMANCE)) /* there are different opinions about the constness of the input buffer. */
             cchNonRev = iconv(hIconv, (char **)&pvInputLeft, &cbInLeft, (char **)&pvOutputLeft, &cbOutLeft);
 #else
             cchNonRev = iconv(hIconv, (const char **)&pvInputLeft, &cbInLeft, (char **)&pvOutputLeft, &cbOutLeft);
@@ -324,7 +324,7 @@
             const void *pvInputLeft = pvInput;
             void       *pvOutputLeft = pvOutput;
             size_t      cchNonRev;
-#if defined(RT_OS_LINUX) || defined(RT_OS_HAIKU) || defined(RT_OS_SOLARIS) || (defined(RT_OS_DARWIN) && defined(_DARWIN_FEATURE_UNIX_CONFORMANCE)) /* there are different opinions about the constness of the input buffer. */
+#if defined(RT_OS_LINUX) || defined(RT_OS_HAIKU) || defined(RT_OS_FREEBSD) || defined(RT_OS_DRAGONFLY) || defined(RT_OS_SOLARIS) || (defined(RT_OS_DARWIN) && defined(_DARWIN_FEATURE_UNIX_CONFORMANCE)) /* there are different opinions about the constness of the input buffer. */
             cchNonRev = iconv(icHandle, (char **)&pvInputLeft, &cbInLeft, (char **)&pvOutputLeft, &cbOutLeft);
 #else
             cchNonRev = iconv(icHandle, (const char **)&pvInputLeft, &cbInLeft, (char **)&pvOutputLeft, &cbOutLeft);
