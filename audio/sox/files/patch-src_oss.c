$NetBSD: patch-src_oss.c,v 1.1 2015/05/25 19:06:24 bsiegert Exp $

Fix segfault when playing (PR pkg/49929).

http://gnats.netbsd.org/cgi-bin/query-pr-single.pl?number=49929

--- src/oss.c.orig	2014-10-06 02:02:30 UTC
+++ src/oss.c
@@ -369,7 +369,7 @@ static size_t osswrite(
         size_t cbStride;
         int cbWritten;
 
-        cStride = cInput;
+        cStride = cInputRemaining;
         if (cStride > pPriv->cOutput) {
             cStride = pPriv->cOutput;
         }
