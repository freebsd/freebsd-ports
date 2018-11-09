# Revert some changes after following commit:
# https://github.com/pulseaudio/pulseaudio/commit/66885ad633db0f371693475c72133e91f1e09ee5

--- src/utils/padsp.c.orig	2018-05-11 11:43:31 UTC
+++ src/utils/padsp.c
@@ -2394,7 +2394,7 @@ fail:
     return ret;
 }
 
-#ifndef __GLIBC__
+#ifdef sun
 int ioctl(int fd, int request, ...) {
 #else
 int ioctl(int fd, unsigned long request, ...) {
