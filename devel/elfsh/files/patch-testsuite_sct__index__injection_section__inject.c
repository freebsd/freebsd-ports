--- testsuite/sct_index_injection/section_inject.c.orig	2003-08-21 01:11:03 UTC
+++ testsuite/sct_index_injection/section_inject.c
@@ -18,7 +18,7 @@ char sc[] = 
 "\x62\x69\x89\xe3\x52\x53\x89\xe1\x8D\x42\x0b"
 "\xcd\x80\x31\xC0\x40\xcd\x80";
 
-#elif defined(__NetBSD__) || defined(__OpenBSD__) || defined(__FreeBSD__)
+#elif defined(__NetBSD__) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__DragonFly__)
 
 char    sc[] = 
 "\xeb\x22"                      /* jmp end                      */
