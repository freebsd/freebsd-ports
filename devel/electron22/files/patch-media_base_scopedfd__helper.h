--- media/base/scopedfd_helper.h.orig	2022-02-28 16:54:41 UTC
+++ media/base/scopedfd_helper.h
@@ -15,7 +15,7 @@ namespace media {
 // but since the only current user is V4L2 we are limiting the scope to OS_LINUX
 // so the binary size does not inflate on non-using systems. Feel free to adapt
 // this and BUILD.gn as our needs evolve.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
 // Return a new vector containing duplicates of |fds|, or PCHECKs in case of an
 // error.
