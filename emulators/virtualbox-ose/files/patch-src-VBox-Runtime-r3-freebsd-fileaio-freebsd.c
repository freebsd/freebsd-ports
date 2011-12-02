Runtime/fileaio-freebsd: Fix error check for aio_error

Obtained-from:	https://www.virtualbox.org/changeset/38332

--- src/VBox/Runtime/r3/freebsd/fileaio-freebsd.cpp.orig	2011-07-15 17:34:34.000000000 +0200
+++ src/VBox/Runtime/r3/freebsd/fileaio-freebsd.cpp	2011-11-21 09:33:26.155092865 +0100
@@ -416,7 +416,8 @@
                 {
                     pReqInt = pahReqs[i];
                     rcBSD = aio_error(&pReqInt->AioCB);
-                    if (rcBSD == EINVAL || rcBSD == EAGAIN)
+                    if (  rcBSD == -1
+                        && errno == EINVAL)
                     {
                         /* Was not submitted. */
                         RTFILEAIOREQ_SET_STATE(pReqInt, PREPARED);
