--- arj_arcv.c	2005-06-21 22:53:12.000000000 +0300
+++ arj_arcv.c	2005-11-24 02:50:31.000000000 +0200
@@ -59,27 +59,27 @@
 #define setup_hput(ptr) (tmp_hptr=(ptr))
 
 #define hget_byte() (*(tmp_hptr++)&0xFF)
-#define hput_byte(c) (*(tmp_hptr++)=(char) (c))
+#define hput_byte(c) (*(tmp_hptr++)=(uint8_t) (c))
 
 /* Reads two bytes from the header, incrementing the pointer */
 
-static unsigned int hget_word()
+static uint16_t hget_word()
 {
- unsigned int result;
+ uint16_t result;
 
  result=mget_word(tmp_hptr);
- tmp_hptr+=sizeof(short);
+ tmp_hptr+=sizeof(uint16_t);
  return result;
 }
 
 /* Reads four bytes from the header, incrementing the pointer */
 
-static unsigned long hget_longword()
+static uint32_t hget_longword()
 {
- unsigned long result;
+ uint32_t result;
 
  result=mget_dword(tmp_hptr);
- tmp_hptr+=sizeof(unsigned long);
+ tmp_hptr+=sizeof(uint32_t);
  return result;
 }
 
@@ -87,18 +87,18 @@
 
 /* Writes two bytes to the header, incrementing the pointer */
 
-static void hput_word(unsigned int w)
+static void hput_word(uint16_t w)
 {
  mput_word(w,tmp_hptr); 
- tmp_hptr+=sizeof(unsigned short);
+ tmp_hptr+=sizeof(uint16_t);
 }
 
 /* Writes four bytes to the header, incrementing the pointer */
 
-static void hput_longword(unsigned long l)
+static void hput_longword(uint32_t l)
 {
  mput_dword(l,tmp_hptr);
- tmp_hptr+=sizeof(unsigned long);
+ tmp_hptr+=sizeof(uint32_t);
 }
 
 /* Calculates and stores the basic header size */
diff -Naur -x .svn -x CVS arj-3.10.22.orig/arj_proc.c arj-3.10.22/arj_proc.c
