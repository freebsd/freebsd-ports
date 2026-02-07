- disable GLIBC symbols specific to linux

--- src/xwin.c.orig	2022-07-15 23:09:11 UTC
+++ src/xwin.c
@@ -1,4 +1,4 @@
-#ifndef DARWIN
+#if !defined(DARWIN) && !defined(__FreeBSD__)
 __asm__(".symver memcpy,memcpy@GLIBC_2.2.5");
 __asm__(".symver memmove,memmove@GLIBC_2.2.5");
 __asm__(".symver log,log@GLIBC_2.2.5");
