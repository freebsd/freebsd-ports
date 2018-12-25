--- similar/main/inferno.cpp.orig	2018-11-21 18:29:50 UTC
+++ similar/main/inferno.cpp
@@ -679,7 +679,7 @@ static int main(int argc, char *argv[])
 int main(int argc, char *argv[])
 {
 	mem_init();
-#if defined(__linux__) || defined(__OpenBSD__)
+#if defined(__linux__) || defined(__OpenBSD__) || defined(__FreeBSD__)
 #if DXX_WORDS_NEED_ALIGNMENT
 	prctl(PR_SET_UNALIGN, PR_UNALIGN_NOPRINT, 0, 0, 0);
 #endif
