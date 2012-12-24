--- opcodes/i386-dis.c.orig	2012-07-16 14:58:29.000000000 +0200
+++ opcodes/i386-dis.c	2012-12-18 15:22:10.000000000 +0100
@@ -11991,7 +11991,7 @@
 static void
 OP_ST (int bytemode ATTRIBUTE_UNUSED, int sizeflag ATTRIBUTE_UNUSED)
 {
-  oappend ("%st" + intel_syntax);
+  oappend (&"%st"[(short)intel_syntax]);
 }
 
 static void
@@ -12520,32 +12520,32 @@
   if (prefixes & PREFIX_CS)
     {
       used_prefixes |= PREFIX_CS;
-      oappend ("%cs:" + intel_syntax);
+      oappend (&"%cs:"[(short)intel_syntax]);
     }
   if (prefixes & PREFIX_DS)
     {
       used_prefixes |= PREFIX_DS;
-      oappend ("%ds:" + intel_syntax);
+      oappend (&"%ds:"[(short)intel_syntax]);
     }
   if (prefixes & PREFIX_SS)
     {
       used_prefixes |= PREFIX_SS;
-      oappend ("%ss:" + intel_syntax);
+      oappend (&"%ss:"[(short)intel_syntax]);
     }
   if (prefixes & PREFIX_ES)
     {
       used_prefixes |= PREFIX_ES;
-      oappend ("%es:" + intel_syntax);
+      oappend (&"%es:"[(short)intel_syntax]);
     }
   if (prefixes & PREFIX_FS)
     {
       used_prefixes |= PREFIX_FS;
-      oappend ("%fs:" + intel_syntax);
+      oappend (&"%fs:"[(short)intel_syntax]);
     }
   if (prefixes & PREFIX_GS)
     {
       used_prefixes |= PREFIX_GS;
-      oappend ("%gs:" + intel_syntax);
+      oappend (&"%gs:"[(short)intel_syntax]);
     }
 }
 
@@ -13876,7 +13876,7 @@
 	  intel_operand_size (b_mode, sizeflag);
 	}
     }
-  oappend ("%es:" + intel_syntax);
+  oappend (&"%es:"[(short)intel_syntax]);
   ptr_reg (code, sizeflag);
 }
