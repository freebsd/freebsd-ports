--- html_r.c.orig	2002-12-26 22:55:05.000000000 +0800
+++ html_r.c		2002-12-27 01:37:56.000000000 +0800
@@ -479,13 +479,28 @@
 
 void line_break(struct part *);
 
+#define IS_MULTIHI(c) ( ((c) >= 0xa1 && (c) <=0xF9) ? 1 : 0 )
+#define IS_MULTILO(c) ( (((c) >= 0x40 && (c) <=0x7E ) ||         \
+                         ((c) >= 0xA1 && (c) <=0xFE )    ) ? 1 : 0 )
+    
 int split_line(struct part *p)
 {
 	int i;
+       int db_char = 0;
+	int db_char_hi = 0;	
 	/*if (!p->data) goto r;*/
+	
+        if (p->data)
+            for (i=0; i <= rm(par_format); i++)
+                if (IS_MULTIHI(POS(i, p->cy) & 0xff) && IS_MULTILO(POS(i+1, p->cy) & 0xff))
+                    db_char_hi=i, i++;
+
 	/*printf("split: %d,%d   , %d,%d,%d\n",p->cx,p->cy,par_format.rightmargin,par_format.leftmargin,p->cx);*/
-	for (i = rm(par_format); i >= par_format.leftmargin; i--)
-		if (i < p->spl && p->spaces[i]) goto split;
+        for (i = rm(par_format); i >= par_format.leftmargin; i--) {
+            db_char = (p->data && i+1 == db_char_hi);
+            if (i < p->spl && (p->spaces[i] || db_char)) goto split;
+        }
+
 	/*for (i = p->cx - 1; i > rm(par_format) && i > par_format.leftmargin; i--)*/
 	for (i = par_format.leftmargin; i < p->cx ; i++)
 		if (i < p->spl && p->spaces[i]) goto split;
@@ -504,10 +519,11 @@
 	if (i + par_format.rightmargin > p->x) p->x = i + par_format.rightmargin;
 	if (p->data) {
 #ifdef DEBUG
-		if ((POS(i, p->cy) & 0xff) != ' ') internal("bad split: %c", (char)POS(i, p->cy));
+		if ((POS(i, p->cy) & 0xff) != ' ' && !db_char) internal("bad split: %c", (char)POS(i, p->cy));
 #endif
 		move_chars(p, i+1, p->cy, par_format.leftmargin, p->cy+1);
-		del_chars(p, i, p->cy);
+		if(!db_char)
+			del_chars(p, i, p->cy);
 	}
 	memmove(p->spaces, p->spaces + i + 1, p->spl - i - 1);
 	memset(p->spaces + p->spl - i - 1, 0, i + 1);

