--- source/kanji.c.orig	Mon Dec  4 03:44:17 2000
+++ source/kanji.c	Mon Dec  4 03:44:17 2000
@@ -0,0 +1,133 @@
+/* kanji.c */
+#include "kanji.h"
+
+#ifndef TRUE
+#define TRUE 1
+#endif
+
+#ifndef FALSE
+#define FALSE 0
+#endif
+
+#define ESC  '\033'
+#define KI1  '$'
+#define KI21 'B'
+#define KI22 '@'
+#define KO1  '('
+#define KO21 'B'
+#define KO22 'J'
+#define KO23 'H'
+
+#define EUC2JIS(c) (unsigned char)((c) & 0x7f)
+#define JIS2EUC(c) (char)((c) | 0x80)
+
+/* proto types */
+static int ParseESC(char **jisstr);
+
+/* Euc2Jis : convert euc to jis.         */ 
+/*   eucstr : input string (euc)         */
+/*   jisstr : output string (jis)        */
+/*   limit  : output string limit length */
+int Euc2Jis(unsigned char *eucstr, char *jisstr, int limit)
+{
+  int length, shifted;
+
+  shifted = FALSE;
+  
+  while (*eucstr) {
+    length = 0;
+    if(ISKANJI(*eucstr)){
+      if(!shifted){
+	*jisstr++ = ESC;
+	*jisstr++ = KI1;
+	*jisstr++ = KI21;
+	shifted = TRUE;
+	length += 3;
+      }
+      *jisstr++ = EUC2JIS(*eucstr++);
+      *jisstr++ = EUC2JIS(*eucstr++);
+      length += 2;
+    }else{
+      if(shifted){
+	*jisstr++ = ESC;
+	*jisstr++ = KO1;
+	*jisstr++ = KO21;
+	length += 3;
+	shifted = FALSE;
+      }
+      *jisstr++ = *eucstr++;
+      length += 1;
+    }
+    
+    limit -= length;
+    if(limit < 4){
+      jisstr -= length;
+      break; /* goto _break_1; */
+    }
+  }
+ _break_1:
+  if (shifted) {
+    *jisstr++ = ESC;
+    *jisstr++ = KO1;
+    *jisstr++ = KO21;
+  }
+  *jisstr = '\0';
+  return 0;
+}
+
+
+/* Jis2Euc : convert jis to euc.         */ 
+/*   jisstr : input string (jis)         */
+/*   eucstr : output string (euc)        */
+void Jis2Euc(char *jisstr, unsigned char *eucstr)
+{
+  int shifted;
+  char c;
+  char* bg = eucstr;
+  
+  shifted = FALSE;
+  
+  while ((c = *jisstr++) != '\0') {
+    if (c == ESC) {
+      shifted = ParseESC(&jisstr);
+    }else{
+      if (shifted) {
+	if (*jisstr) {
+	  *eucstr++ = JIS2EUC(c);
+	  *eucstr++ = JIS2EUC(*jisstr);
+	  jisstr++;
+	}
+      }else{
+	*eucstr++ = c;
+      }
+    }
+  }
+  *eucstr = '\0';
+}
+
+
+/* ParseESC : parse escape code                                         */
+/*  input  : esc code                                                   */
+/*  output : ESC $ B / ESC $ @ / ESC $ @  : shifted and skip esc code   */
+/*           ESC ( B / ESC ( J / ESC ( H  : unshifted and skip esc code */
+int ParseESC(char **jisstr)
+{
+  char c1, c2;
+  int shifted;
+  char* pos = *jisstr;
+
+  shifted = FALSE;
+  c1 = *pos++; c2 = c1 ? *pos++ : '\0';
+  
+  if (c1 == KO1) {
+    if (c2 == KO21 || c2 == KO22 || c2 == KO23) {
+      *jisstr = pos;
+    }
+  } else if (c1 == KI1) {
+    if (c2 == KI21 || c2 == KI22) {
+      *jisstr = pos;
+      shifted = TRUE;
+    }
+  }
+  return shifted;
+}
