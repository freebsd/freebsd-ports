
$FreeBSD$

--- disasm.h.orig
+++ disasm.h
@@ -11,8 +11,8 @@
 
 #define INSN_MAX 32	/* one instruction can't be longer than this */
 
-long disasm (unsigned char *data, char *output, int segsize, long offset,
-	     int autosync, unsigned long prefer);
-long eatbyte (unsigned char *data, char *output);
+long disasm (unsigned char *data, char *output, int outbufsize, int segsize, 
+	     long offset, int autosync, unsigned long prefer);
+long eatbyte (unsigned char *data, char *output, int outbufsize);
 
 #endif
