--- ../nkf.c.orig	Mon Mar 27 21:46:58 2006
+++ ../nkf.c	Sun May  7 22:37:16 2006
@@ -3323,9 +3323,9 @@
     void (*f)PROTO((int c2,int c1));
     int c;
 {
+    int shift = 20;
     const char *hex = "0123456789ABCDEF";
     c &= 0x00FFFFFF;
-    int shift = 20;
     while(shift >= 0){
 	if(c >= 1<<shift){
 	    while(shift >= 0){
@@ -3417,6 +3417,7 @@
     c = unicode_subchar;
     (*oconv)((c>>8)&0xFF, c&0xFF);
     return;
+#if 0
     int shift = 16;
     while(shift >= 0){
 	if(c >= 1<<shift){
@@ -3429,10 +3430,13 @@
 	}
     }
     return;
+#endif
 }
 #endif
 
 #ifdef UTF8_OUTPUT_ENABLE
+extern const unsigned short *const x0212_to_utf8_2bytes[];
+
 int
 e2w_conv(c2, c1)
     int    c2, c1;
@@ -3449,7 +3453,6 @@
 	if(ms_ucs_map_f == UCS_MAP_ASCII&& c2 == 0x8F22 && c1 == 0x43){
 	    return 0xA6;
 	}
-        extern const unsigned short *const x0212_to_utf8_2bytes[];
         c2 = (c2&0x7f) - 0x21;
         if (0<=c2 && c2<sizeof_euc_to_utf8_2bytes)
 	    p = x0212_to_utf8_2bytes[c2];
