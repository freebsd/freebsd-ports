--- runtime.c.orig	2018-09-02 13:30:07 UTC
+++ runtime.c
@@ -12577,7 +12577,7 @@ C_word C_random_bytes(C_word buf, C_word size)
   int r = 0;
   int off = 0;
 
-#ifdef __OpenBSD__
+#if defined(__OpenBSD__) || defined(__FreeBSD__)
   arc4random_buf(C_data_pointer(buf), count);
 #elif defined(SYS_getrandom) && defined(__NR_getrandom)
   static int use_urandom = 0;
