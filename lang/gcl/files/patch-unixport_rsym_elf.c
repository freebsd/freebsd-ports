--- ./unixport/rsym_elf.c.orig	Thu Jul 25 22:49:47 2002
+++ ./unixport/rsym_elf.c	Sat Sep 13 23:52:25 2003
@@ -34,9 +34,6 @@
 int text_index,data_index,bss_index,sbss_index;
 #undef SYM_NAME
 #undef EXT_and_TEXT_BSS_DAT
-#define mjoin(a,b) a ## b
-#define Mjoin(a,b) mjoin(a,b)
-#define ELFW(a) Mjoin(ELF,Mjoin(__ELF_NATIVE_CLASS,Mjoin(_,a)))
 
 int nsyms;
 char *my_string_table;
@@ -136,7 +133,6 @@
 	unsigned int i;
 	FILE *fp;
 	int symsize;
-	extern char *malloc();
 	
         
 	fp = fopen(filename, RDONLY);
