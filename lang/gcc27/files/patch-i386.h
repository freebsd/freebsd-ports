--- config/i386/i386.h.orig	Fri Sep 22 15:42:57 1995
+++ config/i386/i386.h	Mon Mar 20 13:29:12 2000
@@ -1286,6 +1286,22 @@
   }									\
 while (0)
 
+/* Define this macro if a SYMBOL_REF representing a non-global
+   address must be marked specially.  This is called for
+   compiler-generated local symbols, such as "__EXCEPTION_TABLE__".
+
+   On i386, if using PIC, we use this to set the rtx's
+   SYMBOL_REF_FLAG, so that we may access it directly as
+   an offset from the GOT register. */
+
+#define MARK_LOCAL_ADDRESS(X)						\
+do									\
+  {									\
+    if (flag_pic && GET_CODE (X) == SYMBOL_REF)				\
+      SYMBOL_REF_FLAG (X) = 1;						\
+  }									\
+while (0)
+
 /* Initialize data used by insn expanders.  This is called from
    init_emit, once for each function, before code is generated.
    For 386, clear stack slot assignments remembered from previous
@@ -1621,7 +1637,7 @@
 do { long l[2];								\
      REAL_VALUE_TO_TARGET_DOUBLE (VALUE, l);				\
      if (sizeof (int) == sizeof (long))					\
-       fprintf (FILE, "%s 0x%x,0x%x\n", ASM_LONG, l[0], l[1]);		\
+       fprintf (FILE, "%s 0x%x,0x%x\n", ASM_LONG, (int) l[0], (int) l[1]); \
      else								\
        fprintf (FILE, "%s 0x%lx,0x%lx\n", ASM_LONG, l[0], l[1]);	\
    } while (0)
@@ -1633,7 +1649,8 @@
 do { long l[3];						\
      REAL_VALUE_TO_TARGET_LONG_DOUBLE (VALUE, l);	\
      if (sizeof (int) == sizeof (long))			\
-       fprintf (FILE, "%s 0x%x,0x%x,0x%x\n", ASM_LONG, l[0], l[1], l[2]); \
+       fprintf (FILE, "%s 0x%x,0x%x,0x%x\n", ASM_LONG,	\
+		(int) l[0], (int) l[1], (int) l[2]);	\
      else						\
        fprintf (FILE, "%s 0x%lx,0x%lx,0x%lx\n", ASM_LONG, l[0], l[1], l[2]); \
    } while (0)
@@ -1644,7 +1661,7 @@
 do { long l;						\
      REAL_VALUE_TO_TARGET_SINGLE (VALUE, l);		\
      if (sizeof (int) == sizeof (long))			\
-       fprintf ((FILE), "%s 0x%x\n", ASM_LONG, l);	\
+       fprintf ((FILE), "%s 0x%x\n", ASM_LONG, (int) l); \
      else						\
        fprintf ((FILE), "%s 0x%lx\n", ASM_LONG, l);	\
    } while (0)
