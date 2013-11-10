From e0b5a0523e6ba75efc97d5fc0bc5299b5f3d3bca Mon Sep 17 00:00:00 2001
From: Raphael Kubo da Costa <rakuco@FreeBSD.org>
Date: Mon, 14 Oct 2013 23:35:05 +0300
Subject: [PATCH] KWSys: Include backtrace-related headers on FreeBSD.

This was probably broken for a long while, but the problem was not apparent
because the check for execinfo.h would fail by default because
-I/usr/local/include was not being passed to the compiler when making the
checks for the header's existence.

Now that very recent FreeBSD versions (ie. 10-CURRENT) have NetBSD's
libexecinfo in base (and it is thus installed into /usr), the
backtrace-related checks would pass, but the required headers were not being
included in SystemInformation.cxx.
---
 Source/kwsys/SystemInformation.cxx | 9 +++++++++
 1 file changed, 9 insertions(+)

diff --git a/Source/kwsys/SystemInformation.cxx b/Source/kwsys/SystemInformation.cxx
index 7c31f3a..2672730 100644
--- Source/kwsys/SystemInformation.cxx
+++ Source/kwsys/SystemInformation.cxx
@@ -88,6 +88,15 @@ typedef int siginfo_t;
 #  include <ifaddrs.h>
 #  define KWSYS_SYSTEMINFORMATION_IMPLEMENT_FQDN
 # endif
+# if defined(KWSYS_SYSTEMINFORMATION_HAS_BACKTRACE)
+#  include <execinfo.h>
+#  if defined(KWSYS_SYSTEMINFORMATION_HAS_CPP_DEMANGLE)
+#    include <cxxabi.h>
+#  endif
+#  if defined(KWSYS_SYSTEMINFORMATION_HAS_SYMBOL_LOOKUP)
+#    include <dlfcn.h>
+#  endif
+# endif
 #endif
 
 #if defined(__OpenBSD__) || defined(__NetBSD__)
-- 
1.8.4

