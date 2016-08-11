--- gus.h.orig	1995-10-21 20:06:38 UTC
+++ gus.h
@@ -41,7 +41,7 @@ void sync_time(void);
 
 extern unsigned char _seqbuf[];
 extern int _seqbuflen, _seqbufptr;
-unsigned short base_freq_table[];
+unsigned short base_freq_table[16];
 extern unsigned int gus_total_mem;
 
 int gus_mem_free(int dev);
