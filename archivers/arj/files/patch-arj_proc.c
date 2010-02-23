--- arj_proc.c	2005-11-24 02:50:19.000000000 +0200
+++ arj_proc.c	2005-11-24 02:50:31.000000000 +0200
@@ -585,7 +585,7 @@
 /* Returns the exact amount of data that could be safely written to the
    destination volume */
 
-unsigned long get_volfree(unsigned int increment)
+unsigned long get_volfree(unsigned long increment)
 {
  unsigned long pvol;
  unsigned int arjsec_overhead;
@@ -605,7 +605,7 @@
  remain=volume_limit-ftell(aostream)-pvol-(long)arjsec_overhead-
         (long)out_bytes-(long)cpos-(long)ext_voldata-
         MULTIVOLUME_RESERVE-t_volume_offset;
- return((unsigned long)min(remain, (unsigned long)increment));
+ return((unsigned long)min(remain, increment));
 }
 
 /* Performs various checks when multivolume data is packed to predict an
@@ -2466,14 +2466,14 @@
     *tsptr='\0';
   endptr=tsptr;
   tsptr=sptr;
-  while((unsigned int)tsptr<(unsigned int)endptr&&patterns<SEARCH_STR_MAX)
+  while((intptr_t)tsptr<(intptr_t)endptr&&patterns<SEARCH_STR_MAX)
   {
    while(*tsptr=='\0')
     tsptr++;
-   if((unsigned int)tsptr<(unsigned int)endptr)
+   if((intptr_t)tsptr<(intptr_t)endptr)
    {
     search_str[patterns++]=tsptr;
-    while(*tsptr!='\0'&&(unsigned int)tsptr<(unsigned int)endptr)
+    while(*tsptr!='\0'&&(intptr_t)tsptr<(intptr_t)endptr)
      tsptr++;
    }
   }
@@ -2901,9 +2901,9 @@
 #if (defined(WORDS_BIGENDIAN) || defined(ALIGN_POINTERS)) && !defined(ARJDISP) && !defined(REGISTER)
 /* Model-independent routine to get 2 bytes from far RAM */
 
-unsigned int mget_word(char FAR *p)
+uint16_t mget_word(char FAR *p)
 {
- unsigned int b0, b1;
+ uint16_t b0, b1;
 
  b0=mget_byte(p);
  b1=mget_byte(p+1);
@@ -2912,9 +2912,9 @@
 
 /* Model-independent routine to get 4 bytes from far RAM */
 
-unsigned long mget_dword(char FAR *p)
+uint32_t mget_dword(char FAR *p)
 {
- unsigned long w0, w1;
+ uint32_t w0, w1;
 
  w0=mget_word(p);
  w1=mget_word(p+2);
@@ -2923,7 +2923,7 @@
 
 /* Model-independent routine to store 2 bytes in far RAM */
 
-void mput_word(unsigned int w, char FAR *p)
+void mput_word(uint16_t w, char FAR *p)
 {
  mput_byte(w&0xFF, p);
  mput_byte(w>>8  , p+1);
@@ -2931,7 +2931,7 @@
 
 /* Model-independent routine to store 4 bytes in far RAM */
 
-void mput_dword(unsigned long d, char FAR *p)
+void mput_dword(uint32_t d, char FAR *p)
 {
  mput_word(d&0xFFFF, p);
  mput_word(d>>16   , p+2);
