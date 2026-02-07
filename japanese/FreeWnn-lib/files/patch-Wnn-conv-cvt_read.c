Index: Wnn/conv/cvt_read.c
===================================================================
RCS file: /home/cvs/private/hrs/freewnn/Wnn/conv/cvt_read.c,v
retrieving revision 1.1.1.1
retrieving revision 1.2
diff -u -p -r1.1.1.1 -r1.2
--- Wnn/conv/cvt_read.c	20 Dec 2008 07:13:30 -0000	1.1.1.1
+++ Wnn/conv/cvt_read.c	20 Dec 2008 15:22:37 -0000	1.2
@@ -67,8 +67,8 @@
 /*
 #define NOFILE_NOT_ABORT
 */
- /* ¤³¤ì¤òdefine¤·¤Æ¤ª¤¯¤È¡¢ÊÑ´¹É½¤¬open¤Ç¤­¤Ê¤¤»þ¤Ë¥¨¥é¡¼½ªÎ»¤»¤º¡¢
-    Ã±¤ËÊÑ´¹´Ø¿ô¤¬¹±Åù´Ø¿ô¤Ë¤Ê¤ë¡£ */
+/* ¤³¤ì¤òdefine¤·¤Æ¤ª¤¯¤È¡¢ÊÑ´¹É½¤¬open¤Ç¤­¤Ê¤¤»þ¤Ë¥¨¥é¡¼½ªÎ»¤»¤º¡¢
+   Ã±¤ËÊÑ´¹´Ø¿ô¤¬¹±Åù´Ø¿ô¤Ë¤Ê¤ë¡£ */
 
 #define is_digit(x) (isascii(x) && isdigit(x))
 #define is_xdigit(x) (isascii(x) && isxdigit(x))
@@ -82,14 +82,13 @@
 
 #define ESCCHR  '\033'
 
- /*     convert_key ÍÑÊÑ´¹É½¤Î¥Õ¥¡¥¤¥ëÌ¾¤Î¥Ç¥Õ¥©¥ë¥È¤ò¥»¥Ã¥È¡£
-    ÊÑ´¹É½¤ÎÌ¾¤¬ÌÀ¼¨Åª¤Ë»ØÄê¤µ¤ì¤¿¤é¡¢¤½¤ì¤¬¤³¤ÎÊÑ¿ô¤ÎÃÍ¤Ë¤Ê¤ë¡£ */
+/*     convert_key ÍÑÊÑ´¹É½¤Î¥Õ¥¡¥¤¥ëÌ¾¤Î¥Ç¥Õ¥©¥ë¥È¤ò¥»¥Ã¥È¡£
+       ÊÑ´¹É½¤ÎÌ¾¤¬ÌÀ¼¨Åª¤Ë»ØÄê¤µ¤ì¤¿¤é¡¢¤½¤ì¤¬¤³¤ÎÊÑ¿ô¤ÎÃÍ¤Ë¤Ê¤ë¡£ */
 static char *convert_filename;
 static char default_cvt_fn[128];
 
 static FILE *convert_hyo;
 
-
  /** ¥¨¥é¡¼¥á¥Ã¥»¡¼¥¸¤òÉ½¼¨ */
 #define errdsp1(mes, conv_fnm)                                          \
         fprintf(stderr, "%s: %s.\r\n%s = %s\r\n\n",                     \
@@ -132,11 +131,10 @@ static FILE *convert_hyo;
 
  /** ¥³¡¼¥Éc¤òÌÜ¤Ë¸«¤¨¤ë·Á¤Ç°õ»ú */
 static void
-printcode (f, c)
-     FILE *f;
-     int c;
+printcode(FILE *f,
+	  int c)
 {
-  fprintf (f, (' ' <= c && c < '\177') ? "'%c'" : ((c & ~0xff) ? "0x%X" : "'\\%03o'"), c);
+	fprintf(f, (' ' <= c && c < '\177') ? "'%c'" : ((c & ~0xff) ? "0x%X" : "'\\%03o'"), c);
 }
 
 /*
@@ -145,58 +143,58 @@ char    **pterp;
 {ÇÑ»ß}
 */
 
- /**    8¡¦10¡¦16¿Ê¥³¡¼¥ÉÍÑ¤Î¥­¥ã¥é¥¯¥¿¤ò¼ÂºÝ¤Î¥³¡¼¥É¤ËÄ¾¤¹¡£ÆþÎÏ¤Î¥Á¥§¥Ã¥¯¤Ï
-        ¤·¤Ê¤¤¡ÊÆþÎÏ¤Ï±Ñ¿ô»ú¤È²¾Äê¤·¤Æ¤¤¤ë¡Ë¡£*/
+/**    8¡¦10¡¦16¿Ê¥³¡¼¥ÉÍÑ¤Î¥­¥ã¥é¥¯¥¿¤ò¼ÂºÝ¤Î¥³¡¼¥É¤ËÄ¾¤¹¡£ÆþÎÏ¤Î¥Á¥§¥Ã¥¯¤Ï
+       ¤·¤Ê¤¤¡ÊÆþÎÏ¤Ï±Ñ¿ô»ú¤È²¾Äê¤·¤Æ¤¤¤ë¡Ë¡£*/
 static int
-charvalue (c)
-     char c;
+charvalue (char c)
 {
-  if (isupper (c))
-    return (c - 'A' + 10);
-  if (islower (c))
-    return (c - 'a' + 10);
-  return (c - '0');
-}
+	if (isupper(c))
+		return (c - 'A' + 10);
 
+	if (islower(c))
+		return (c - 'a' + 10);
+
+	return (c - '0');
+}
 
 #ifdef TERMCAP
 char *cvttbl_entry[] = {
-  "k0", "k1", "k2", "k3", "k4", "k5", "k6", "k7", "k8", "k9",
+	"k0", "k1", "k2", "k3", "k4", "k5", "k6", "k7", "k8", "k9",
 #ifdef SUPPORT_TWODIGIT_FUNCTIONS
-  "k;",
-  "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "FA",
-  "FB", "FC", "FD", "FE", "FF", "FG", "FH", "FI", "FJ", "FK",
-  "FL", "FM", "FN", "FO", "FP", "FQ", "FR", "FS", "FT", "FU",
-  "FV", "FW", "FX", "FY", "FZ", "Fa", "Fb", "Fc", "Fd", "Fe",
-  "Ff", "Fg", "Fh", "Fi", "Fj", "Fk", "Fl", "Fm", "Fn", "Fo",
-  "Fp", "Fq", "Fr",
+	"k;",
+	"F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "FA",
+	"FB", "FC", "FD", "FE", "FF", "FG", "FH", "FI", "FJ", "FK",
+	"FL", "FM", "FN", "FO", "FP", "FQ", "FR", "FS", "FT", "FU",
+	"FV", "FW", "FX", "FY", "FZ", "Fa", "Fb", "Fc", "Fd", "Fe",
+	"Ff", "Fg", "Fh", "Fi", "Fj", "Fk", "Fl", "Fm", "Fn", "Fo",
+	"Fp", "Fq", "Fr",
 #endif                          /* SUPPORT_TWODIGIT_FUNCTIONS */
-  "ku", "kr", "kl", "kd", "kh",
-  "up", "ri", "le", "do", "ho",
-  "kb",
-  "!del",                       /* »ÃÄê */
+	"ku", "kr", "kl", "kd", "kh",
+	"up", "ri", "le", "do", "ho",
+	"kb",
+	"!del",                       /* »ÃÄê */
 };
 #endif /* TERMCAP */
 #ifdef TERMINFO
 char *cvttbl_entry[] = {
-  "kf0", "kf1", "kf2", "kf3", "kf4", "kf5", "kf6", "kf7",
-  "kf8", "kf9", "kf10",
+	"kf0", "kf1", "kf2", "kf3", "kf4", "kf5", "kf6", "kf7",
+	"kf8", "kf9", "kf10",
 #ifdef SUPPORT_TWODIGIT_FUNCTIONS
-  "kf11", "kf12", "kf13", "kf14", "kf15", "kf16", "kf17",
-  "kf18", "kf19", "kf20", "kf21", "kf22", "kf23", "kf24",
-  "kf25", "kf26", "kf27", "kf28", "kf29", "kf30", "kf31",
+	"kf11", "kf12", "kf13", "kf14", "kf15", "kf16", "kf17",
+	"kf18", "kf19", "kf20", "kf21", "kf22", "kf23", "kf24",
+	"kf25", "kf26", "kf27", "kf28", "kf29", "kf30", "kf31",
 #ifndef uniosu
-  "kf32", "kf33", "kf34", "kf35", "kf36", "kf37", "kf38",
-  "kf39", "kf40", "kf41", "kf42", "kf43", "kf44", "kf45",
-  "kf46", "kf47", "kf48", "kf49", "kf50", "kf51", "kf52",
-  "kf53", "kf54", "kf55", "kf56", "kf57", "kf58", "kf59",
-  "kf60", "kf61", "kf62", "kf63",
+	"kf32", "kf33", "kf34", "kf35", "kf36", "kf37", "kf38",
+	"kf39", "kf40", "kf41", "kf42", "kf43", "kf44", "kf45",
+	"kf46", "kf47", "kf48", "kf49", "kf50", "kf51", "kf52",
+	"kf53", "kf54", "kf55", "kf56", "kf57", "kf58", "kf59",
+	"kf60", "kf61", "kf62", "kf63",
 #endif
 #endif                          /* SUPPORT_TWODIGIT_FUNCTIONS */
-  "kcuu1", "kcuf1", "kcub1", "kcud1", "khome",
-  "kbs", "ktbc", "kclr", "kctab", "kdch1", "kdl1",
-  "krmir", "kel", "ked", "kich1", "kil1",
-  "kll", "knp", "kpp", "kind", "kri", "khts",
+	"kcuu1", "kcuf1", "kcub1", "kcud1", "khome",
+	"kbs", "ktbc", "kclr", "kctab", "kdch1", "kdl1",
+	"krmir", "kel", "ked", "kich1", "kil1",
+	"kll", "knp", "kpp", "kind", "kri", "khts",
 };
 #endif /* TERMINFO */
 
@@ -208,494 +206,496 @@ char tdataarea[AREASIZE];       /* ¥Ç¡¼¥
 
 struct CONVCODE tbl[CVTTBLSIZ];
 int cnv_tbl_cnt;                /* convert table count */
- /* ¤³¤ì¤é¤Ï¸µ¤Ï convert_key.cÃæ¤ÎstaticÊÑ¿ô¤À¤Ã¤¿ */
+/* ¤³¤ì¤é¤Ï¸µ¤Ï convert_key.cÃæ¤ÎstaticÊÑ¿ô¤À¤Ã¤¿ */
 
- /** ¥³¥ó¥Ð¡¼¥ÈÉ½¤Î¥¨¥ó¥È¥êÉôÊ¬¤ò¤È¤ë¡£µö¤µ¤ì¤ëºÇÂçÄ¹¤òÄ¶¤¨¤¿¤é0¤òÊÖ¤¹ */
+/** ¥³¥ó¥Ð¡¼¥ÈÉ½¤Î¥¨¥ó¥È¥êÉôÊ¬¤ò¤È¤ë¡£µö¤µ¤ì¤ëºÇÂçÄ¹¤òÄ¶¤¨¤¿¤é0¤òÊÖ¤¹ */
 static int
-get_entrynm (buf)
-     char *buf;
+get_entrynm(char *buf)
 {
-  int i, c;
+	int i, c;
 
-  for (i = 0; i <= ENTRY_LEN; i++)
-    {
-      c = getc (convert_hyo);
-      if (is_eofsp (c))
-        {
-          ungetc (c, convert_hyo);
-          *buf = '\0';
-          return (1);
-        }
-      else
-        *buf++ = c;
-    }
-  return (0);
+	for (i = 0; i <= ENTRY_LEN; i++) {
+		c = getc(convert_hyo);
+
+		if (is_eofsp(c)) {
+			ungetc(c, convert_hyo);
+			*buf = '\0';
+			return (1);
+		} else
+			*buf++ = c;
+	}
+
+	return (0);
 }
 
  /** ¶õÇò¡Ê²þ¹ÔÊ¸»ú¤ò½ü¤¯¡Ë¤ò¤È¤Ð¤·¤Æ¼¡¤ÎÊ¸»ú¤òÊÖ¤¹ */
 static int
-blank_ign_getc (f)
-     FILE *f;
+blank_ign_getc(FILE *f)
 {
-  int c;
+	int c;
+
+	while (c = getc(f),
+	       is_space(c) && c != '\n');
 
-  while (c = getc (f), is_space (c) && c != '\n');
-  return (c);
+	return (c);
 }
 
- /** ¹ÔËö¡ÊËô¤ÏEOF¡Ë¤Þ¤ÇÈô¤Ð¤¹¡£¤½¤Î´Ö¤ËÈó¶õÇòÊ¸»ú¤¬¤¢¤Ã¤¿¤éÈó0¤òÊÖ¤¹¡£*/
+/** ¹ÔËö¡ÊËô¤ÏEOF¡Ë¤Þ¤ÇÈô¤Ð¤¹¡£¤½¤Î´Ö¤ËÈó¶õÇòÊ¸»ú¤¬¤¢¤Ã¤¿¤éÈó0¤òÊÖ¤¹¡£*/
 static int
-linepass (f)
-     FILE *f;
+linepass(FILE *f)
 {
-  int c, flg = 0;
+	int c, flg = 0;
 
-  while (c = getc (f), !is_eofnl (c))
-    flg = (flg || !is_space (c));
-  return (flg);
+	while (c = getc(f), !is_eofnl(c))
+		flg = (flg || !is_space(c));
+
+	return (flg);
 }
 
- /** ¥³¥ó¥È¥í¡¼¥ë¥³¡¼¥É·Á¼°¤Î¥³¡¼¥ÉÉ½µ­°ìÊ¸»úÊ¬¤ò¤È¤ë¡£¥¨¥é¡¼¤¬¤¢¤ì¤ÐÊÖÃÍ¡â0*/
+/** ¥³¥ó¥È¥í¡¼¥ë¥³¡¼¥É·Á¼°¤Î¥³¡¼¥ÉÉ½µ­°ìÊ¸»úÊ¬¤ò¤È¤ë¡£¥¨¥é¡¼¤¬¤¢¤ì¤ÐÊÖÃÍ¡â0*/
 static int
-get_ctrl (cptr)
-     int *cptr;
+get_ctrl(int *cptr)
 {
-  int c;
+	int c;
+
+	if (!(' ' <= (c = getc(convert_hyo))
+	      && c < '\177'))
+		return (1);
+
+	*cptr = (c == '?' ? '\177' : c & 0x1f);
 
-  if (!(' ' <= (c = getc (convert_hyo)) && c < '\177'))
-    return (1);
-  *cptr = (c == '?' ? '\177' : c & 0x1f);
-  return (0);
+	return (0);
 }
 
  /** ¥Ð¥Ã¥¯¥¹¥é¥Ã¥·¥å·Á¼°¤Î¥³¡¼¥ÉÉ½µ­°ìÊ¸»úÊ¬¤ò¤È¤ë¡£¥¨¥é¡¼¤¬¤¢¤ì¤ÐÈó0¤òÊÖ¤¹*/
 static int
-get_bcksla (cptr)
-     int *cptr;
+get_bcksla(int *cptr)
 {
-  int c, code = 0, digflg = 0;
+	int c, code = 0, digflg = 0;
 
-  switch (c = getc (convert_hyo))
-    {
-    case 'n':
-      *cptr = '\n';
-      return (0);
-    case 't':
-      *cptr = '\t';
-      return (0);
-    case 'b':
-      *cptr = '\b';
-      return (0);
-    case 'r':
-      *cptr = '\r';
-      return (0);
-    case 'f':
-      *cptr = '\f';
-      return (0);
-    case 'e':
-    case 'E':
-      *cptr = ESCCHR;
-      return (0);
-    case 'o':
-      while (c = getc (convert_hyo), is_octal (c))
-        {
-          code <<= 3;
-          code += charvalue (c);
-          digflg = 1;
-        }
-      ungetc (c, convert_hyo);
-      *cptr = code;
-      return (digflg == 0);
-    case 'd':
-      while (c = getc (convert_hyo), is_digit (c))
-        {
-          code *= 10;
-          code += charvalue (c);
-          digflg = 1;
-        }
-      ungetc (c, convert_hyo);
-      *cptr = code;
-      return (digflg == 0);
-    case 'x':
-      while (c = getc (convert_hyo), is_xdigit (c))
-        {
-          code <<= 4;
-          code += charvalue (c);
-          digflg = 1;
-        }
-      ungetc (c, convert_hyo);
-      *cptr = code;
-      return (digflg == 0);
-    default:
-      if (is_octal (c))
-        {
-          code = charvalue (c);
-          while (c = getc (convert_hyo), is_octal (c))
-            {
-              code <<= 3;
-              code += charvalue (c);
-            }
-          ungetc (c, convert_hyo);
-          *cptr = code;
-          return (0);
-        }
-      else
-        {
-          *cptr = c;
-          return (0);
-        }
-    }
+	switch (c = getc(convert_hyo)) {
+	case 'n':
+		*cptr = '\n';
+		return (0);
+	case 't':
+		*cptr = '\t';
+		return (0);
+	case 'b':
+		*cptr = '\b';
+		return (0);
+	case 'r':
+		*cptr = '\r';
+		return (0);
+	case 'f':
+		*cptr = '\f';
+		return (0);
+	case 'e':
+	case 'E':
+		*cptr = ESCCHR;
+		return (0);
+	case 'o':
+		while (c = getc(convert_hyo), is_octal(c)) {
+			code <<= 3;
+			code += charvalue(c);
+			digflg = 1;
+		}
+		ungetc(c, convert_hyo);
+		*cptr = code;
+		return (digflg == 0);
+	case 'd':
+		while (c = getc(convert_hyo), is_digit(c)) {
+			code *= 10;
+			code += charvalue(c);
+			digflg = 1;
+		}
+
+		ungetc(c, convert_hyo);
+		*cptr = code;
+		return (digflg == 0);
+	case 'x':
+		while (c = getc(convert_hyo), is_xdigit(c)) {
+			code <<= 4;
+			code += charvalue(c);
+			digflg = 1;
+		}
+		ungetc(c, convert_hyo);
+		*cptr = code;
+		return (digflg == 0);
+	default:
+		if (is_octal(c)) {
+			code = charvalue(c);
+			while (c = getc(convert_hyo), is_octal(c)) {
+				code <<= 3;
+				code += charvalue(c);
+			}
+			ungetc(c, convert_hyo);
+			*cptr = code;
+			return (0);
+		} else {
+			*cptr = c;
+			return (0);
+		}
+	}
 }
 
- /**    ¥³¡¼¥ÉÉ½µ­¤ò¤È¤Ã¤Æ¡¢cptr¤Î»Ø¤·Àè¤Ë¤½¤Î¥³¡¼¥É¤òÆþ¤ì¤ë¡£
-        Ê¸Ë¡¥¨¥é¡¼È¯¸«»þ¤ÏÈó0¤òÊÖ¤¹¡£*/
+/**    ¥³¡¼¥ÉÉ½µ­¤ò¤È¤Ã¤Æ¡¢cptr¤Î»Ø¤·Àè¤Ë¤½¤Î¥³¡¼¥É¤òÆþ¤ì¤ë¡£
+       Ê¸Ë¡¥¨¥é¡¼È¯¸«»þ¤ÏÈó0¤òÊÖ¤¹¡£*/
 static int
-get_code (cptr)
-     int *cptr;
+get_code(int *cptr)
 {
-  int c;
+	int c;
 
-  switch (c = getc (convert_hyo))
-    {
-    case '\\':
-      return (get_bcksla (cptr));
-    case '^':
-      return (get_ctrl (cptr));
-    default:
-      *cptr = c;
-      return (0);
-    }
+	switch (c = getc(convert_hyo)) {
+	case '\\':
+		return (get_bcksla(cptr));
+	case '^':
+		return (get_ctrl(cptr));
+	default:
+		*cptr = c;
+		return (0);
+	}
 }
 
 #ifdef TERMCAP
- /**    tgetstr¤ÈÆ±Åù¤Î´Ø¿ô¡£Ã¢¤·¡¢¥¨¥ó¥È¥êÌ¾¡Ö!del¡×¡ÊDEL¥­¡¼¤ÎÊÑ´¹¤ò¤¹¤ë¤¿¤á
-        »ÃÄêÅª¤ËÄÉ²Ã¤·¤Æ¤¢¤ë¥¨¥ó¥È¥ê¡Ë¤ËÂÐ¤·¤Æ¤Ï¡¢ÄêÊ¸»úÎó"\177"¤òÊÖ¤¹¡£*/
+/**    tgetstr¤ÈÆ±Åù¤Î´Ø¿ô¡£Ã¢¤·¡¢¥¨¥ó¥È¥êÌ¾¡Ö!del¡×¡ÊDEL¥­¡¼¤ÎÊÑ´¹¤ò¤¹¤ë¤¿¤á
+       »ÃÄêÅª¤ËÄÉ²Ã¤·¤Æ¤¢¤ë¥¨¥ó¥È¥ê¡Ë¤ËÂÐ¤·¤Æ¤Ï¡¢ÄêÊ¸»úÎó"\177"¤òÊÖ¤¹¡£*/
 static char *
-my_tgetstr (name, ptr)
-     char *name, **ptr;
+my_tgetstr(char *name,
+	   char **ptr)
 {
-  extern char *tgetstr ();
-  static char *del = "\177";
+	extern char *tgetstr ();
+	static char *del = "\177";
 
-  if (strcmp (name, "!del") == 0)
-    return (del);
-  return (tgetstr (name, ptr));
+	if (strcmp(name, "!del") == 0)
+		return (del);
+
+	return (tgetstr(name, ptr));
 }
 #endif
 
 #ifdef TERMINFO
- /**    pp1¤Î»Ø¤·¤Æ¤¤¤ë¥¨¥ê¥¢¤Ëp2¤ÎÆâÍÆ¤òÆþ¤ì¤¿¸å¡¢pp1¤Î¥Ý¥¤¥ó¥¿¤ò¿Ê¤á¤Æ¤ª¤¯*/
+/**    pp1¤Î»Ø¤·¤Æ¤¤¤ë¥¨¥ê¥¢¤Ëp2¤ÎÆâÍÆ¤òÆþ¤ì¤¿¸å¡¢pp1¤Î¥Ý¥¤¥ó¥¿¤ò¿Ê¤á¤Æ¤ª¤¯*/
 static char *
-stradd (pp1, p2)
-     char **pp1, *p2;
+stradd(char **pp1, char *p2)
 {
-  if (p2 != NULL)
-    {
-      strcpy (*pp1, p2);
-      (*pp1) += strlen (p2 = *pp1) + 1;
-    }
-  return (p2);
+	if (p2 != NULL) {
+		strcpy(*pp1, p2);
+		(*pp1) += strlen(p2 = *pp1) + 1;
+	}
+
+	return (p2);
 }
 #endif
 
  /** termcap/info¤«¤éÆÉ¤ó¤À¥­¡¼¤Î¥Ç¡¼¥¿¤òÀìÍÑ¥¨¥ê¥¢¤Ë¥³¥Ô¡¼¡£*/
 static void
-convert_getstrs (flg)
-     int flg;                   /* verbose¥â¡¼¥É¤Çµ¯¤³¤¹¤«¤Î¥Õ¥é¥°¡Êº£¤Î½ê¤½¤ì¤À¤±¤À¤¬¡¢¾­Íè
-                                   ³ÈÄ¥¤¬¤¢¤ë¤«¤â¤·¤ì¤Ê¤¤¤Î¤Ç¡¢1¤«0¤ÇÍ¿¤¨¤Æ²¼¤µ¤¤¡£¤³¤Î¥Õ¥¡¥¤¥ë
-                                   Ãæ¤Î¡¢Ì¾Á°¤¬convert_¤Ç»Ï¤Þ¤ëÂ¾¤Î´Ø¿ô¤Ç¤âÆ±¤¸¤Ç¤¹¡Ë */
+convert_getstrs(int flg)
+/* verbose¥â¡¼¥É¤Çµ¯¤³¤¹¤«¤Î¥Õ¥é¥°¡Êº£¤Î½ê¤½¤ì¤À¤±¤À¤¬¡¢¾­Íè
+   ³ÈÄ¥¤¬¤¢¤ë¤«¤â¤·¤ì¤Ê¤¤¤Î¤Ç¡¢1¤«0¤ÇÍ¿¤¨¤Æ²¼¤µ¤¤¡£¤³¤Î¥Õ¥¡¥¤¥ë
+   Ãæ¤Î¡¢Ì¾Á°¤¬convert_¤Ç»Ï¤Þ¤ëÂ¾¤Î´Ø¿ô¤Ç¤âÆ±¤¸¤Ç¤¹¡Ë */
 {
-  char *tdataptr;
-  int i;
+	char *tdataptr;
+	int i;
 
-  tdataptr = tdataarea;
+	tdataptr = tdataarea;
 
 #ifdef TERMCAP
-  for (i = 0; i < ENTRY_CNT; i++)
-    keydef_key[i] = my_tgetstr (cvttbl_entry[i], &tdataptr);
+	for (i = 0; i < ENTRY_CNT; i++)
+		keydef_key[i] = my_tgetstr(cvttbl_entry[i], &tdataptr);
   /* keydef_key[i] ¤ÎÃÍ¤Ï¡¢NULLËô¤Ïtdataarea¤ÎÈÏ°ÏÆâ¤È¤Ï¸Â¤é¤Ê¤¤¡£
      "\177"¤Ê¤É¤ÎÆÃ¼ì¥Ç¡¼¥¿¤ò»Ø¤¹¤³¤È¤â¤¢¤ë¡£ */
 
-  if (flg)
-    fprintf (stderr, "convert_key: finished getting TERMCAP.\r\n");
+	if (flg)
+		fprintf (stderr, "convert_key: finished getting TERMCAP.\r\n");
 #endif
 
 #ifdef TERMINFO
-  i = 0;
-  keydef_key[i++] = stradd (&tdataptr, key_f0);
-  keydef_key[i++] = stradd (&tdataptr, key_f1);
-  keydef_key[i++] = stradd (&tdataptr, key_f2);
-  keydef_key[i++] = stradd (&tdataptr, key_f3);
-  keydef_key[i++] = stradd (&tdataptr, key_f4);
-  keydef_key[i++] = stradd (&tdataptr, key_f5);
-  keydef_key[i++] = stradd (&tdataptr, key_f6);
-  keydef_key[i++] = stradd (&tdataptr, key_f7);
-  keydef_key[i++] = stradd (&tdataptr, key_f8);
-  keydef_key[i++] = stradd (&tdataptr, key_f9);
-  keydef_key[i++] = stradd (&tdataptr, key_f10);
+	i = 0;
+	keydef_key[i++] = stradd(&tdataptr, key_f0);
+	keydef_key[i++] = stradd(&tdataptr, key_f1);
+	keydef_key[i++] = stradd(&tdataptr, key_f2);
+	keydef_key[i++] = stradd(&tdataptr, key_f3);
+	keydef_key[i++] = stradd(&tdataptr, key_f4);
+	keydef_key[i++] = stradd(&tdataptr, key_f5);
+	keydef_key[i++] = stradd(&tdataptr, key_f6);
+	keydef_key[i++] = stradd(&tdataptr, key_f7);
+	keydef_key[i++] = stradd(&tdataptr, key_f8);
+	keydef_key[i++] = stradd(&tdataptr, key_f9);
+	keydef_key[i++] = stradd(&tdataptr, key_f10);
 #ifdef SUPPORT_TWODIGIT_FUNCTIONS
-  keydef_key[i++] = stradd (&tdataptr, key_f11);
-  keydef_key[i++] = stradd (&tdataptr, key_f12);
-  keydef_key[i++] = stradd (&tdataptr, key_f13);
-  keydef_key[i++] = stradd (&tdataptr, key_f14);
-  keydef_key[i++] = stradd (&tdataptr, key_f15);
-  keydef_key[i++] = stradd (&tdataptr, key_f16);
-  keydef_key[i++] = stradd (&tdataptr, key_f17);
-  keydef_key[i++] = stradd (&tdataptr, key_f18);
-  keydef_key[i++] = stradd (&tdataptr, key_f19);
-  keydef_key[i++] = stradd (&tdataptr, key_f20);
-  keydef_key[i++] = stradd (&tdataptr, key_f21);
-  keydef_key[i++] = stradd (&tdataptr, key_f22);
-  keydef_key[i++] = stradd (&tdataptr, key_f23);
-  keydef_key[i++] = stradd (&tdataptr, key_f24);
-  keydef_key[i++] = stradd (&tdataptr, key_f25);
-  keydef_key[i++] = stradd (&tdataptr, key_f26);
-  keydef_key[i++] = stradd (&tdataptr, key_f27);
-  keydef_key[i++] = stradd (&tdataptr, key_f28);
-  keydef_key[i++] = stradd (&tdataptr, key_f29);
-  keydef_key[i++] = stradd (&tdataptr, key_f30);
-  keydef_key[i++] = stradd (&tdataptr, key_f31);
+	keydef_key[i++] = stradd(&tdataptr, key_f11);
+	keydef_key[i++] = stradd(&tdataptr, key_f12);
+	keydef_key[i++] = stradd(&tdataptr, key_f13);
+	keydef_key[i++] = stradd(&tdataptr, key_f14);
+	keydef_key[i++] = stradd(&tdataptr, key_f15);
+	keydef_key[i++] = stradd(&tdataptr, key_f16);
+	keydef_key[i++] = stradd(&tdataptr, key_f17);
+	keydef_key[i++] = stradd(&tdataptr, key_f18);
+	keydef_key[i++] = stradd(&tdataptr, key_f19);
+	keydef_key[i++] = stradd(&tdataptr, key_f20);
+	keydef_key[i++] = stradd(&tdataptr, key_f21);
+	keydef_key[i++] = stradd(&tdataptr, key_f22);
+	keydef_key[i++] = stradd(&tdataptr, key_f23);
+	keydef_key[i++] = stradd(&tdataptr, key_f24);
+	keydef_key[i++] = stradd(&tdataptr, key_f25);
+	keydef_key[i++] = stradd(&tdataptr, key_f26);
+	keydef_key[i++] = stradd(&tdataptr, key_f27);
+	keydef_key[i++] = stradd(&tdataptr, key_f28);
+	keydef_key[i++] = stradd(&tdataptr, key_f29);
+	keydef_key[i++] = stradd(&tdataptr, key_f30);
+	keydef_key[i++] = stradd(&tdataptr, key_f31);
 #endif /* SUPPORT_TWODIGIT_FUNCTIONS */
 /* °Ê²¼½ç¤Ë
-        "kcuu1", "kcuf1", "kcub1", "kcud1", "khome",
-        "kbs", "ktbc", "kclr", "kctab", "kdch1", "kdl1",
-        "krmir", "kel", "ked", "kich1", "kil1",
-        "kll", "knp", "kpp", "kind", "kri", "khts",
+   "kcuu1", "kcuf1", "kcub1", "kcud1", "khome",
+   "kbs", "ktbc", "kclr", "kctab", "kdch1", "kdl1",
+   "krmir", "kel", "ked", "kich1", "kil1",
+   "kll", "knp", "kpp", "kind", "kri", "khts",
 */
-  keydef_key[i++] = stradd (&tdataptr, key_up);
-  keydef_key[i++] = stradd (&tdataptr, key_right);
-  keydef_key[i++] = stradd (&tdataptr, key_left);
-  keydef_key[i++] = stradd (&tdataptr, key_down);
-  keydef_key[i++] = stradd (&tdataptr, key_home);
-  keydef_key[i++] = stradd (&tdataptr, key_backspace);
-  keydef_key[i++] = stradd (&tdataptr, key_catab);
-  keydef_key[i++] = stradd (&tdataptr, key_clear);
-  keydef_key[i++] = stradd (&tdataptr, key_ctab);
-  keydef_key[i++] = stradd (&tdataptr, key_dc);
-  keydef_key[i++] = stradd (&tdataptr, key_dl);
-  keydef_key[i++] = stradd (&tdataptr, key_eic);
-  keydef_key[i++] = stradd (&tdataptr, key_eol);
-  keydef_key[i++] = stradd (&tdataptr, key_eos);
-  keydef_key[i++] = stradd (&tdataptr, key_ic);
-  keydef_key[i++] = stradd (&tdataptr, key_il);
-  keydef_key[i++] = stradd (&tdataptr, key_ll);
-  keydef_key[i++] = stradd (&tdataptr, key_npage);
-  keydef_key[i++] = stradd (&tdataptr, key_ppage);
-  keydef_key[i++] = stradd (&tdataptr, key_sf);
-  keydef_key[i++] = stradd (&tdataptr, key_sr);
-  keydef_key[i++] = stradd (&tdataptr, key_stab);
-
-  if (flg)
-    fprintf (stderr, "convert_key: finished getting TERMINFO.\r\n");
+	keydef_key[i++] = stradd(&tdataptr, key_up);
+	keydef_key[i++] = stradd(&tdataptr, key_right);
+	keydef_key[i++] = stradd(&tdataptr, key_left);
+	keydef_key[i++] = stradd(&tdataptr, key_down);
+	keydef_key[i++] = stradd(&tdataptr, key_home);
+	keydef_key[i++] = stradd(&tdataptr, key_backspace);
+	keydef_key[i++] = stradd(&tdataptr, key_catab);
+	keydef_key[i++] = stradd(&tdataptr, key_clear);
+	keydef_key[i++] = stradd(&tdataptr, key_ctab);
+	keydef_key[i++] = stradd(&tdataptr, key_dc);
+	keydef_key[i++] = stradd(&tdataptr, key_dl);
+	keydef_key[i++] = stradd(&tdataptr, key_eic);
+	keydef_key[i++] = stradd(&tdataptr, key_eol);
+	keydef_key[i++] = stradd(&tdataptr, key_eos);
+	keydef_key[i++] = stradd(&tdataptr, key_ic);
+	keydef_key[i++] = stradd(&tdataptr, key_il);
+	keydef_key[i++] = stradd(&tdataptr, key_ll);
+	keydef_key[i++] = stradd(&tdataptr, key_npage);
+	keydef_key[i++] = stradd(&tdataptr, key_ppage);
+	keydef_key[i++] = stradd(&tdataptr, key_sf);
+	keydef_key[i++] = stradd(&tdataptr, key_sr);
+	keydef_key[i++] = stradd(&tdataptr, key_stab);
+	
+	if (flg)
+		fprintf(stderr, "convert_key: finished getting TERMINFO.\r\n");
 #endif
 }
 
- /**    TERMINFO ¤Î¾ì¹ç¤Ï setupterm()¡¢TERMCAP¤Î¾ì¹ç¤Ï tgetent()¤Î½èÍý¤ò¹Ô¤Ã¤¿
-        ¸å¡¢¥­¡¼¤¬È¯À¸¤¹¤ë¥·¡¼¥±¥ó¥¹¤Î¥Ç¡¼¥¿¤òÀìÍÑ¤Î¥¨¥ê¥¢¤Ë¥³¥Ô¡¼¤¹¤ë¡£
-        termcap/info¤Î¥Ç¡¼¥¿¥Ù¡¼¥¹¤¬¥ª¡¼¥×¥ó¤Ç¤­¤Ê¤«¤Ã¤¿¤éÈó0¤òÊÖ¤¹¡£*/
+/**    TERMINFO ¤Î¾ì¹ç¤Ï setupterm()¡¢TERMCAP¤Î¾ì¹ç¤Ï tgetent()¤Î½èÍý¤ò¹Ô¤Ã¤¿
+       ¸å¡¢¥­¡¼¤¬È¯À¸¤¹¤ë¥·¡¼¥±¥ó¥¹¤Î¥Ç¡¼¥¿¤òÀìÍÑ¤Î¥¨¥ê¥¢¤Ë¥³¥Ô¡¼¤¹¤ë¡£
+       termcap/info¤Î¥Ç¡¼¥¿¥Ù¡¼¥¹¤¬¥ª¡¼¥×¥ó¤Ç¤­¤Ê¤«¤Ã¤¿¤éÈó0¤òÊÖ¤¹¡£*/
 #ifdef TERMCAP
 int
-convert_getterm (termname, flg)
-     char *termname;
-     int flg;
-{
-  extern int tgetent ();
-  char tcaparea[AREASIZE];
-
-  if (flg)
-    fprintf (stderr, "convert_key: using TERMCAP entry %s...\r\n", termname);
-  if (tgetent (tcaparea, termname) <= 0)
-    {
-      errdsp2 ("Can't get termcap entry", termname);
-      return (1);
-    }
-  convert_getstrs (flg);
-  return (0);
+convert_getterm(char *termname,
+		int flg)
+{
+	extern int tgetent ();
+	char tcaparea[AREASIZE];
+
+	if (flg)
+		fprintf(stderr, "convert_key: using TERMCAP entry %s...\r\n",
+			 termname);
+
+	if (tgetent(tcaparea, termname) <= 0) {
+		errdsp2("Can't get termcap entry", termname);
+		return (1);
+	}
+
+	convert_getstrs(flg);
+
+	return (0);
 }
 #endif
 #ifdef TERMINFO
 int
-convert_getterm (termname, flg)
-     char *termname;
-     int flg;
-{
-  int fd, rsl;
-
-  if (flg)
-    fprintf (stderr, "convert_key: using TERMINFO entry %s...\r\n", termname);
-  fd = open ("/dev/null", O_WRONLY, 0);
-  setupterm (termname, fd, &rsl);
-  close (fd);
-  if (rsl != 1)
-    {
-      errdsp2 ("Can't get terminfo entry", termname);
-      /* ¤³¤Î¤È¤­resetterm()¤ÏÉ¬Í×¤«¡© */
-      return (1);
-    }
-  convert_getstrs (flg);
-  resetterm ();
-  return (0);
+convert_getterm(char *termname,
+		int flg)
+{
+	int fd, rsl;
+
+	if (flg)
+		fprintf (stderr,
+			 "convert_key: using TERMINFO entry %s...\r\n",
+			 termname);
+
+	fd = open("/dev/null", O_WRONLY, 0);
+	setupterm(termname, fd, &rsl);
+	close (fd);
+
+	if (rsl != 1) {
+		errdsp2("Can't get terminfo entry", termname);
+		/* ¤³¤Î¤È¤­resetterm()¤ÏÉ¬Í×¤«¡© */
+		return (1);
+	}
+
+	convert_getstrs(flg);
+	resetterm();
+	return (0);
 }
 #endif
 
- /**    termcap/info¤«¤é¼è¤Ã¤¿¥­¡¼¤Î¥Ç¡¼¥¿¤¬´û¤ËÀìÍÑ¥¨¥ê¥¢¤Ë¼ý¤Þ¤Ã¤Æ¤¤¤ë¤È
-        ¤·¤Æ¡¢¤½¤ì¤ò»È¤Ã¤Æconvert_key½èÍý¤Î½é´ü²½¤ò¤¹¤ë¡£ÊÖÃÍ¤ÏÀµ¾ï½ªÎ»»þ0¡¢
-        É½ÆÉ¤ß¹þ¤ß»þ¤ËWarning¤¬È¯À¸¤·¤¿»þ1¡¢Error¤ò¸¡½Ð¤·¤¿¤È¤­-1¡£*/
+/**    termcap/info¤«¤é¼è¤Ã¤¿¥­¡¼¤Î¥Ç¡¼¥¿¤¬´û¤ËÀìÍÑ¥¨¥ê¥¢¤Ë¼ý¤Þ¤Ã¤Æ¤¤¤ë¤È
+       ¤·¤Æ¡¢¤½¤ì¤ò»È¤Ã¤Æconvert_key½èÍý¤Î½é´ü²½¤ò¤¹¤ë¡£ÊÖÃÍ¤ÏÀµ¾ï½ªÎ»»þ0¡¢
+       É½ÆÉ¤ß¹þ¤ß»þ¤ËWarning¤¬È¯À¸¤·¤¿»þ1¡¢Error¤ò¸¡½Ð¤·¤¿¤È¤­-1¡£*/
 int
-convert_key_setup (filename, flg)
-     char *filename;
-     int flg;
-{
-  register int i;
-  int c, d, cnt = 0, warn_occur = 0, entry_found;
-  char name[ENTRY_LEN + 1];
-
-  int keydef_code[ENTRY_CNT];   /* convert code */
-
-  if (CHANGE_MAX < div_up (ENTRY_CNT, BITSIZ))
-    {
-      fprintf (stderr, "%s%s%d%s", "Sorry, please set CHANGE_MAX(in file ", "conv/cvt_head.h) larger than ", div_up (ENTRY_CNT, BITSIZ) - 1, ",\r\nand recompile.\r\n");
-      return (-1);
-    }
-
-  for (i = 0; i < ENTRY_CNT; i++)
-    keydef_code[i] = -1;
-  /* code¤¬ -1 ¤Î¤Þ¤Þ¤Ê¤é¡¢convert_keyÉ½¤Ë¥¨¥ó¥È¥ê¤¬¤Ê¤¤¤³¤È¤ò¼¨¤¹¡£ */
-
-  if (NULL != filename)
-    convert_filename = filename;
-  else
-    {
-      convert_filename = default_cvt_fn;
+convert_key_setup(char *filename,
+		  int flg)
+{
+	register int i;
+	int c, d, cnt = 0, warn_occur = 0, entry_found;
+	char name[ENTRY_LEN + 1];
+
+	int keydef_code[ENTRY_CNT];   /* convert code */
+
+	if (CHANGE_MAX < div_up (ENTRY_CNT, BITSIZ)) {
+		fprintf (stderr, "%s%s%d%s",
+			 "Sorry, please set CHANGE_MAX(in file ",
+			 "conv/cvt_head.h) larger than ",
+			 div_up (ENTRY_CNT, BITSIZ) - 1,
+			 ",\r\nand recompile.\r\n");
+		return (-1);
+	}
+
+	for (i = 0; i < ENTRY_CNT; i++)
+		keydef_code[i] = -1;
+	/* code¤¬ -1 ¤Î¤Þ¤Þ¤Ê¤é¡¢convert_keyÉ½¤Ë¥¨¥ó¥È¥ê¤¬¤Ê¤¤¤³¤È¤ò¼¨¤¹¡£ */
+
+	if (NULL != filename)
+		convert_filename = filename;
+	else {
+		convert_filename = default_cvt_fn;
 #ifdef  WNNDEFAULT
-      strcpy (convert_filename, LIBDIR);        /* /usr/local/lib/wnn */
-      strcat (convert_filename, CONVERT_FILENAME);      /* /cvt_key_tbl */
+		strcpy(convert_filename, LIBDIR);        /* /usr/local/lib/wnn */
+		strcat(convert_filename, CONVERT_FILENAME);      /* /cvt_key_tbl */
 #else
-      strcpy (convert_filename, CONVERT_FILENAME);
+		strcpy(convert_filename, CONVERT_FILENAME);
 #endif /* WNNDEFAULT */
-    }
-  if (flg)
-    fprintf (stderr, "convert_key: using convert_key table %s...\r\n", convert_filename);
-  if (NULL == (convert_hyo = fopen (convert_filename, "r")))
-    {
+	}
+
+	if (flg)
+		fprintf (stderr, "convert_key: using convert_key table %s...\r\n",
+			 convert_filename);
+
+	if (NULL == (convert_hyo = fopen(convert_filename, "r"))) {
 #ifdef NOFILE_NOT_ABORT
-      warn1 (convert_filename);
-      cnv_tbl_cnt = 0;
-      return (1);
+		warn1(convert_filename);
+		cnv_tbl_cnt = 0;
+		return (1);
 #else
-      errdsp1 ("Convert-table file is not found", convert_filename);
-      return (-1);
+		errdsp1("Convert-table file is not found",
+			convert_filename);
+		return (-1);
 #endif
-    }
+	}
 
-  /* É½¤«¤é¤ÎÆÉ¤ß¤³¤ß */
-  while (EOF != (d = getc (convert_hyo)))
-    {
-      if (d == '#' || d == ';')
-        {
-          /* '#'Ëô¤Ï';'¤Ç»Ï¤Þ¤ë¹Ô¤ÏÃí¼á¤È¤·¤ÆÆÉ¤ßÈô¤Ð¤¹¡£ */
-          linepass (convert_hyo);
-          continue;
-        }
-      ungetc (d, convert_hyo);
-
-      d = blank_ign_getc (convert_hyo);
-      if (is_eofnl (d))
-        continue;               /* ¶õ¹Ô */
-      else
-        ungetc (d, convert_hyo);
-      if (!get_entrynm (name))
-        {
-          errdsp1 ("Entry name too long", convert_filename);
-          fclose (convert_hyo);
-          return (-1);
-        }                       /* ¥¨¥ó¥È¥êÌ¾¤òÆÉ¤ß¹þ¤ó¤À¡£ */
-
-      d = blank_ign_getc (convert_hyo);
-      if (is_eofnl (d))
-        {
-          errdsp1 ("Convert code missing", convert_filename);
-          fclose (convert_hyo);
-          return (-1);
-        }
-      else
-        ungetc (d, convert_hyo);
-      if (get_code (&c) != 0 || linepass (convert_hyo) != 0)
-        {
-          errdsp1 ("Convert code illegal", convert_filename);
-          fclose (convert_hyo);
-          return (-1);
-        }                       /* ÊÑ´¹¥³¡¼¥É¤òÆÉ¤ß¹þ¤ó¤À¡£ */
+	/* É½¤«¤é¤ÎÆÉ¤ß¤³¤ß */
+	while (EOF != (d = getc(convert_hyo))) {
+		if (d == '#' || d == ';') {
+			/* '#'Ëô¤Ï';'¤Ç»Ï¤Þ¤ë¹Ô¤ÏÃí¼á¤È¤·¤ÆÆÉ¤ßÈô¤Ð¤¹¡£ */
+			linepass(convert_hyo);
+			continue;
+		}
+
+		ungetc(d, convert_hyo);
+
+		d = blank_ign_getc(convert_hyo);
+
+		if (is_eofnl(d))
+			/* ¶õ¹Ô */
+			continue;
+		else
+			ungetc(d, convert_hyo);
+
+		if (!get_entrynm(name)) {
+			errdsp1("Entry name too long",
+				convert_filename);
+			fclose(convert_hyo);
+			return (-1);
+		}
+		/* ¥¨¥ó¥È¥êÌ¾¤òÆÉ¤ß¹þ¤ó¤À¡£ */
+
+		d = blank_ign_getc(convert_hyo);
+
+		if (is_eofnl(d)) {
+			errdsp1("Convert code missing",
+				convert_filename);
+			fclose (convert_hyo);
+			return (-1);
+		} else
+			ungetc(d, convert_hyo);
+
+		if (get_code(&c) != 0
+		    || linepass(convert_hyo) != 0) {
+			errdsp1("Convert code illegal", convert_filename);
+			fclose(convert_hyo);
+			return (-1);
+		}
+		/* ÊÑ´¹¥³¡¼¥É¤òÆÉ¤ß¹þ¤ó¤À¡£ */
 #ifdef DEBUG
-      printf ("%s %d\n", name, c);
+		printf("%s %d\n", name, c);
 #endif
-      for (entry_found = i = 0; i < ENTRY_CNT; i++)
-        {
-          if (!strcmp (cvttbl_entry[i], name))
-            {
-              if (keydef_code[i] != -1)
-                {
-                  warn2 (name, convert_filename);
-                  warn_occur = 1;
-                }
-              keydef_code[i] = c;
-              entry_found = 1;
-              break;
-            }
-        }
-      if (!entry_found)
-        {
-          warn3 (name, convert_filename);
-          warn_occur = 1;
-        }
-    }
-
-  /* ÆÉ¤ß¤³¤ó¤À¥Ç¡¼¥¿¤ò¥Æ¡¼¥Ö¥ë¤Ë¥»¥Ã¥È */
-  for (i = 0; i < ENTRY_CNT; i++)
-    {
-      if (keydef_key[i] != NULL)
-        {
-          if (keydef_code[i] != -1 && ((int) strlen (keydef_key[i]) > 1 || *keydef_key[i] != keydef_code[i]))
-            {
-              tbl[cnt].fromkey = keydef_key[i];
-              tbl[cnt++].tokey = keydef_code[i];
-            }
-        }
-      else if (keydef_code[i] != -1)
-        {
-          warn4 (cvttbl_entry[i], convert_filename, keydef_code[i]);
-          warn_occur = 1;
-        }
-    }
-
-  cnv_tbl_cnt = cnt;
-  fclose (convert_hyo);
-  if (flg)
-    fprintf (stderr, "convert_key: finished setting up.\r\n");
-  return (warn_occur);
-}
-
- /**    convert_key½èÍý½é´ü²½¥ë¡¼¥Á¥ó¡£TERMINFO ¤Î¾ì¹ç¤Ï setupterm()¡¢TERMCAP¤Î
-        ¾ì¹ç¤Ï tgetent()¤ò¤½¤ì¤¾¤ì¥³¡¼¥ë¤·¤¿¸å¤Ë¸Æ¤Ö¡£ÊÖÃÍ¤Ïconvert_key_setup
-        »²¾È¡£*/
+		for (entry_found = i = 0; i < ENTRY_CNT; i++) {
+			if (!strcmp(cvttbl_entry[i], name)) {
+				if (keydef_code[i] != -1) {
+					warn2(name, convert_filename);
+					warn_occur = 1;
+				}
+				keydef_code[i] = c;
+				entry_found = 1;
+				break;
+			}
+		}
+
+		if (!entry_found) {
+			warn3(name, convert_filename);
+			warn_occur = 1;
+		}
+	}
+
+	/* ÆÉ¤ß¤³¤ó¤À¥Ç¡¼¥¿¤ò¥Æ¡¼¥Ö¥ë¤Ë¥»¥Ã¥È */
+
+	for (i = 0; i < ENTRY_CNT; i++) {
+		if (keydef_key[i] != NULL) {
+			if (keydef_code[i] != -1
+			    && ((int)strlen(keydef_key[i]) > 1
+				|| *keydef_key[i] != keydef_code[i])) {
+				tbl[cnt].fromkey = keydef_key[i];
+				tbl[cnt++].tokey = keydef_code[i];
+			}
+		} else if (keydef_code[i] != -1) {
+			warn4 (cvttbl_entry[i], convert_filename, keydef_code[i]);
+			warn_occur = 1;
+		}
+	}
+
+	cnv_tbl_cnt = cnt;
+	fclose(convert_hyo);
+
+	if (flg)
+		fprintf(stderr, "convert_key: finished setting up.\r\n");
+
+	return (warn_occur);
+}
+
+/**    convert_key½èÍý½é´ü²½¥ë¡¼¥Á¥ó¡£TERMINFO ¤Î¾ì¹ç¤Ï setupterm()¡¢TERMCAP¤Î
+       ¾ì¹ç¤Ï tgetent()¤ò¤½¤ì¤¾¤ì¥³¡¼¥ë¤·¤¿¸å¤Ë¸Æ¤Ö¡£ÊÖÃÍ¤Ïconvert_key_setup
+       »²¾È¡£*/
 int
-convert_key_init (filename, flg)
-     char *filename;
-     int flg;
+convert_key_init (char *filename,
+		  int flg)
 {
-  convert_getstrs (flg);
-  return (convert_key_setup (filename, flg));
+	convert_getstrs (flg);
+	return (convert_key_setup (filename, flg));
 }
 
- /**    TERMINFO ¤Î¾ì¹ç¤Ï setupterm()¡¢TERMCAP¤Î¾ì¹ç¤Ï tgetent()¤Þ¤Ç´Þ¤á¤Æ¼Â¹Ô
-        convert_key½èÍý½é´ü²½¥ë¡¼¥Á¥ó¡£ÊÖ¤¹ÃÍ¤Ïconvert_key_setup»²¾È¡£Ã¢¤·¡¢
-        termcap/info¤ÎÆÉ¤ß¹þ¤ß¤Ë¼ºÇÔ¤·¤¿¾ì¹ç¤Ï¡¢-2¤¬ÊÖ¤ë¡£*/
+/**    TERMINFO ¤Î¾ì¹ç¤Ï setupterm()¡¢TERMCAP¤Î¾ì¹ç¤Ï tgetent()¤Þ¤Ç´Þ¤á¤Æ¼Â¹Ô
+       convert_key½èÍý½é´ü²½¥ë¡¼¥Á¥ó¡£ÊÖ¤¹ÃÍ¤Ïconvert_key_setup»²¾È¡£Ã¢¤·¡¢
+       termcap/info¤ÎÆÉ¤ß¹þ¤ß¤Ë¼ºÇÔ¤·¤¿¾ì¹ç¤Ï¡¢-2¤¬ÊÖ¤ë¡£*/
 int
-convert_getterm_init (termname, filename, flg)
-     char *termname, *filename;
-     int flg;
-{
-  if (convert_getterm (termname, flg) != 0)
-    return (-2);
-  return (convert_key_setup (filename, flg));
+convert_getterm_init (char *termname,
+		      char *filename,
+		      int flg)
+{
+	if (convert_getterm (termname, flg) != 0)
+		return (-2);
+
+	return (convert_key_setup (filename, flg));
 }
