--- opcodes/rl78-dis.c.orig	2013-11-20 14:18:22.940364966 +0100
+++ opcodes/rl78-dis.c	2013-11-20 15:25:32.745367278 +0100
@@ -217,7 +217,7 @@
 
 	    case '0':
 	    case '1':
-	      oper = opcode.op + *s - '0';
+	      oper = *s == '0' ? &opcode.op[0] : &opcode.op[1];
 	    if (do_es)
 	      {
 		if (oper->use_es && indirect_type (oper->type))
