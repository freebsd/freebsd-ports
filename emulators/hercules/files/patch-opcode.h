diff -ur ./opcode.h ../../work__/hercules-2.16.5/opcode.h
--- ./opcode.h	Tue Dec 17 07:39:27 2002
+++ ../../work__/hercules-2.16.5/opcode.h	Tue Dec 17 07:33:01 2002
@@ -104,7 +104,7 @@
     }
 
 
-typedef ATTR_REGPARM(3) void (*zz_func) (BYTE inst[], int execflag, REGS *regs);
+typedef void (ATTR_REGPARM(3) *zz_func) (BYTE inst[], int execflag, REGS *regs);
 
 /* Gabor Hoffer (performance option) */
 extern zz_func s370_opcode_table[];
