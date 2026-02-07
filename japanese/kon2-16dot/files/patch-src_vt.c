--- src/vt.c.orig	1997-01-25 17:55:02.000000000 +0900
+++ src/vt.c	2012-05-10 00:17:11.772692570 +0900
@@ -77,6 +77,7 @@
 
 static int	scroll;			 /* スクロール行数 */
 struct langInfo lInfo;
+static u_int prefix;
 
 static
     void SaveAttr()
@@ -107,7 +108,7 @@
 	con.bcol = saveAttr->bcol;
 	tmp = saveAttr;
 	saveAttr = tmp->prev;
-	free(tmp);
+	SafeFree(tmp);
     }
 }
 
@@ -185,6 +186,11 @@
 static void	VtSetMode(u_char mode, bool sw)
 {
     switch(mode) {
+#if defined(__FreeBSD__)
+    case 1:
+        con.cursor_key_mode = sw;
+        break;
+#endif
     case 4:
 	con.ins = sw;
 	break;
@@ -372,6 +378,10 @@
     case 'U':
 	con.g[0] = CS_GRAPH;
 	break;
+    case '0':
+	if (prefix == '(')
+	    con.g[0] = CS_GRAPH;
+	break;
     default:
 	while (fSRegs[i].sign0) {
 	    if (fSRegs[i].sign0 == ch) {
@@ -412,6 +422,7 @@
 static
     void EscStart(u_char ch)
 {
+    prefix = ch;
     con.esc = NULL;
     switch(ch) {
     case '[':
@@ -527,7 +538,8 @@
 	    con.esc = EscStart;
 	    continue;
 	case CHAR_SO:
-	    con.trans = con.g[1] | G1_SET;
+	    /* con.trans = con.g[1] | G1_SET; */
+	    con.trans = con.g[1];
 	    continue;
 	case CHAR_SI:
 	    con.trans = con.g[0];
@@ -585,7 +597,11 @@
 	    } else {
 		/* ANK モード */
 		if (con.ins) TextInsertChar(1);
-		TextSput(con.trans == CS_RIGHT ? ch | 0x80: ch);
+		if (con.trans == CS_RIGHT)
+			ch |= 0x80;
+		else if (con.trans == CS_GRAPH)
+			ch = (1 + ch) & 0x1f;
+		TextSput(ch);
 		con.x ++;
 		continue;
 	    }
@@ -601,20 +617,23 @@
 
 static int	ConfigCoding(const char *confstr)
 {
-    char reg[3][MAX_COLS];
+    char *name, *last, *sep = " \t\r\n";
     int n, i;
 
-    *reg[0] = *reg[1] = *reg[2] = '\0';
-    sscanf(confstr, "%s %s %s", reg[0], reg[1], reg[2]);
-    for (i = 0; i < 3 && *reg[i]; i ++) {
-	n = (int)CodingByRegistry(reg[i]);
+    name = strtok_r((char *)confstr, sep, &last);
+    for (i = 0; i < 3; i++) {
+	if (name == NULL) {
+	    error("invalid coding system\n");
+	    return FAILURE;
+	}
+	n = (int)CodingByRegistry(name);
 	if (n < 0) {
-	    if (!strcasecmp(reg[i], "EUC"))
+	    if (!strcasecmp(name, "EUC"))
 		lInfo.sc = CODE_EUC;
-	    else if (!strcasecmp(reg[i], "SJIS"))
+	    else if (!strcasecmp(name, "SJIS"))
 		lInfo.sc = CODE_SJIS;
 /*
-	    else if (!strcasecmp(reg[i], "BIG5"))
+	    else if (!strcasecmp(name, "BIG5"))
 		lInfo.sc = CODE_BIG5;
 */
 	    else
@@ -628,6 +647,7 @@
 fprintf(fp,"[<%s> %d %d %d %d]\n", reg[i], n, lInfo.sb, lInfo.db, lInfo.sc);
 fclose(fp);}
 #endif
+    	name = strtok_r(NULL, sep, &last);
     }
     return SUCCESS;
 }
@@ -654,4 +674,144 @@
     con.sb = lInfo.sb;
     con.db = lInfo.db|LATCH_1;
     con.active = cInfo.sw = TRUE;
+#if defined(__FreeBSD__)
+    con.cursor_key_mode = FALSE;
+#endif
+}
+
+#if defined(__FreeBSD__)
+
+static int ReplaceString(char *sp, const int len, const int maxlen,
+                         const int oldlen, const char *newstr)
+{
+  int newlen, copylen, diff;
+
+  newlen = strlen(newstr);
+  diff = newlen - oldlen;
+  copylen = len - oldlen;
+
+  if(len + diff > maxlen){
+    diff -= (len + diff - maxlen);
+    copylen = maxlen - newlen;
+  }
+  if(copylen > 0)
+    memcpy(sp + newlen, sp + oldlen, copylen);
+
+  copylen = newlen;
+  if(newlen > maxlen){
+    copylen = maxlen;
+    diff = maxlen - len;
+  }
+  if(copylen > 0)
+    memcpy(sp, newstr, copylen);
+
+  return(diff);
+}
+
+int cons25tovt100(u_char *buff, int len, const int max)
+{
+  u_char *p;
+  int i;
+  int newlen = len;
+
+  p = buff;
+
+  for(i=0; i<newlen; i++, p++){
+    switch(*p){
+    case '\177':
+      newlen += ReplaceString(p, len-i, max-i, 1, "\x1b[3~");
+      i += 3; p += 3;
+      break;
+    case '\033':                  /* ESC */
+      if(i + 2 <= newlen && *(p+1) == '['){
+        switch(*(p+2)){
+        case 'A':               /* up arrow */
+          if(con.cursor_key_mode)
+            newlen += ReplaceString(p, len-i, max-i, 3, "\x1bOA");
+          break;
+        case 'B':               /* down arrow */
+          if(con.cursor_key_mode)
+            newlen += ReplaceString(p, len-i, max-i, 3, "\x1bOB");
+          break;
+        case 'C':               /* right arrow */
+          if(con.cursor_key_mode)
+            newlen += ReplaceString(p, len-i, max-i, 3, "\x1bOC");
+          break;
+        case 'D':               /* left arrow */
+          if(con.cursor_key_mode)
+            newlen += ReplaceString(p, len-i, max-i, 3, "\x1bOD");
+          break;
+        case 'L':               /* insert */
+          newlen += ReplaceString(p, len-i, max-i, 3, "\x1b[2~");
+          i++; p++;
+          break;
+        case 'H':               /* home key */
+          newlen += ReplaceString(p, len-i, max-i, 3, "\x1b[4~");
+          i++; p++;
+          break;
+        case 'I':               /* prev page */
+          newlen += ReplaceString(p, len-i, max-i, 3, "\x1b[5~");
+          i++; p++;
+          break;
+        case 'G':               /* next page */
+          newlen += ReplaceString(p, len-i, max-i, 3, "\x1b[6~");
+          i++; p++;
+          break;
+        case 'M':               /* F1 */
+          newlen += ReplaceString(p, len-i, max-i, 3, "\x1b[11~");
+          i += 2; p += 2;
+          break;
+        case 'N':               /* F2 */
+          newlen += ReplaceString(p, len-i, max-i, 3, "\x1b[12~");
+          i += 2; p += 2;
+          break;
+        case 'O':               /* F3 */
+          newlen += ReplaceString(p, len-i, max-i, 3, "\x1b[13~");
+          i += 2; p += 2;
+          break;
+        case 'P':               /* F4 */
+          newlen += ReplaceString(p, len-i, max-i, 3, "\x1b[14~");
+          i += 2; p += 2;
+          break;
+        case 'Q':               /* F5 */
+          newlen += ReplaceString(p, len-i, max-i, 3, "\x1b[15~");
+          i += 2; p += 2;
+          break;
+        case 'R':               /* F6 */
+          newlen += ReplaceString(p, len-i, max-i, 3, "\x1b[17~");
+          i += 2; p += 2;
+          break;
+        case 'S':               /* F7 */
+          newlen += ReplaceString(p, len-i, max-i, 3, "\x1b[18~");
+          i += 2; p += 2;
+          break;
+        case 'T':               /* F8 */
+          newlen += ReplaceString(p, len-i, max-i, 3, "\x1b[19~");
+          i += 2; p += 2;
+          break;
+        case 'U':               /* F9 */
+          newlen += ReplaceString(p, len-i, max-i, 3, "\x1b[20~");
+          i += 2; p += 2;
+          break;
+        case 'V':               /* F10 */
+          newlen += ReplaceString(p, len-i, max-i, 3, "\x1b[21~");
+          i += 2; p += 2;
+          break;
+        case 'W':               /* F11 */
+          newlen += ReplaceString(p, len-i, max-i, 3, "\x1b[23~");
+          i += 2; p += 2;
+          break;
+        case 'X':               /* F12 */
+          newlen += ReplaceString(p, len-i, max-i, 3, "\x1b[24~");
+          i += 2; p += 2;
+          break;
+        }
+        i += 2; p += 2;
+      }
+    }
+  }
+
+  return(newlen);
 }
+
+#endif
