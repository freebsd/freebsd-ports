--- /dev/null	Mon Dec 16 17:18:27 2002
+++ hc.c	Mon Dec 16 17:21:15 2002
@@ -0,0 +1,51 @@
+#include "hercules.h"
+
+#include "opcode.h"
+
+#include "inline.h"
+
+static int hcd;
+
+DEF_INST(hconsole_get_char)
+{
+	char ch;
+
+	E(inst, execflag, regs);
+
+	if (hcd == 0)
+		hcd = open("/home/tzukanov/hercules/hc",
+			   O_RDWR | O_NONBLOCK | O_CREAT, 0);
+	if (read(hcd, &ch, 1) == 1)
+		regs->GR_LHLCL(1) = ch;
+	else
+		regs->GR_L(1) = -1;
+}
+
+DEF_INST(hconsole_put_char)
+{
+	char ch;
+
+	E(inst, execflag, regs);
+
+
+	if (hcd == 0)
+		hcd = open("/home/tzukanov/hercules/hc",
+			   O_RDWR | O_NONBLOCK | O_CREAT, 0);
+	ch = regs->GR_LHLCL(1);
+	write(hcd, &ch, 1);
+}
+
+#if !defined(_GEN_ARCH)
+
+#if defined(_ARCHMODE2)
+ #define  _GEN_ARCH _ARCHMODE2
+ #include "hc.c"
+#endif 
+
+#if defined(_ARCHMODE3)
+ #undef   _GEN_ARCH
+ #define  _GEN_ARCH _ARCHMODE3
+ #include "hc.c"
+#endif 
+
+#endif /*!defined(_GEN_ARCH)*/
