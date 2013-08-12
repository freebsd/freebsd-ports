--- src/teletext.c.orig	2013-07-02 06:03:54.000000000 +0200
+++ src/teletext.c	2013-08-07 20:24:40.000000000 +0200
@@ -1258,180 +1258,177 @@
 	int pdc_hr;
 
 	/* XXX nested function not portable, to be removed */
-	void
-	flush(int column)
-	{
-		int row = inv_row + active_row;
-		int i;
-
-		if (row >= ROWS)
-			return;
-
-		if (type == OBJECT_TYPE_PASSIVE && !mac.unicode) {
-			active_column = column;
-			return;
-		}
-
-		printv("flush [%04x%c,F%d%c,B%d%c,S%d%c,O%d%c,H%d%c] %d ... %d\n",
-			ac.unicode, mac.unicode ? '*' : ' ',
-			ac.foreground, mac.foreground ? '*' : ' ',
-			ac.background, mac.background ? '*' : ' ',
-			ac.size, mac.size ? '*' : ' ',
-			ac.opacity, mac.opacity ? '*' : ' ',
-			ac.flash, mac.flash ? '*' : ' ',
-			active_column, column - 1);
-
-		for (i = inv_column + active_column; i < inv_column + column;) {
-			vbi_char c;
-
-			if (i > 39)
-				break;
-
-			c = acp[i];
-
-			if (mac.underline) {
-				int u = ac.underline;
-
-				if (!mac.unicode)
-					ac.unicode = c.unicode;
-
-				if (vbi_is_gfx(ac.unicode)) {
-					if (u)
-						ac.unicode &= ~0x20; /* separated */
-					else
-						ac.unicode |= 0x20; /* contiguous */
-					mac.unicode = ~0;
-					u = 0;
-				}
-
-				c.underline = u;
-			}
-			if (mac.foreground)
-				c.foreground = (ac.foreground != VBI_TRANSPARENT_BLACK) ?
-					ac.foreground : (row_color_transparent) ?
-					VBI_TRANSPARENT_BLACK : row_color;
-			if (mac.background)
-				c.background = (ac.background != VBI_TRANSPARENT_BLACK) ?
-					ac.background : (row_color_transparent) ?
-					VBI_TRANSPARENT_BLACK : row_color;
-			if (invert) {
-				int t = c.foreground;
-
-				c.foreground = c.background;
-				c.background = t;
-			}
-			if (mac.opacity)
-				c.opacity = ac.opacity;
-			if (mac.flash)
-				c.flash = ac.flash;
-			if (mac.conceal)
-				c.conceal = ac.conceal;
-			if (mac.unicode) {
-				c.unicode = ac.unicode;
-				mac.unicode = 0;
-
-				if (mac.size)
-					c.size = ac.size;
-				else if (c.size > VBI_DOUBLE_SIZE)
-					c.size = VBI_NORMAL_SIZE;
-			}
-
-			acp[i] = c;
-
-			if (type == OBJECT_TYPE_PASSIVE)
-				break;
-
-			i++;
-
-			if (type != OBJECT_TYPE_PASSIVE
-			    && type != OBJECT_TYPE_ADAPTIVE) {
-				int raw;
-
-				raw = (row == 0 && i < 9) ?
-					0x20 : vbi_unpar8 (vtp->data.lop.raw[row][i - 1]);
-
-				/* set-after spacing attributes cancelling non-spacing */
-
-				switch (raw) {
-				case 0x00 ... 0x07:	/* alpha + foreground color */
-				case 0x10 ... 0x17:	/* mosaic + foreground color */
-					printv("... fg term %d %02x\n", i, raw);
-					mac.foreground = 0;
-					mac.conceal = 0;
-					break;
-
-				case 0x08:		/* flash */
-					mac.flash = 0;
-					break;
-
-				case 0x0A:		/* end box */
-				case 0x0B:		/* start box */
-					if (i < COLUMNS && vbi_unpar8 (vtp->data.lop.raw[row][i]) == raw) {
-						printv("... boxed term %d %02x\n", i, raw);
-						mac.opacity = 0;
-					}
-
-					break;
-
-				case 0x0D:		/* double height */
-				case 0x0E:		/* double width */
-				case 0x0F:		/* double size */
-					printv("... size term %d %02x\n", i, raw);
-					mac.size = 0;
-					break;
-				}
-
-				if (i > 39)
-					break;
-
-				raw = (row == 0 && i < 8) ?
-					0x20 : vbi_unpar8 (vtp->data.lop.raw[row][i]);
-
-				/* set-at spacing attributes cancelling non-spacing */
-
-				switch (raw) {
-				case 0x09:		/* steady */
-					mac.flash = 0;
-					break;
-
-				case 0x0C:		/* normal size */
-					printv("... size term %d %02x\n", i, raw);
-					mac.size = 0;
-					break;
-
-				case 0x18:		/* conceal */
-					mac.conceal = 0;
-					break;
-
-					/*
-					 *  Non-spacing underlined/separated display attribute
-					 *  cannot be cancelled by a subsequent spacing attribute.
-					 */
-
-				case 0x1C:		/* black background */
-				case 0x1D:		/* new background */
-					printv("... bg term %d %02x\n", i, raw);
-					mac.background = 0;
-					break;
-				}
-			}
-		}
-
-		active_column = column;
-	}
+#define flush(column)   \
+	({       \
+		int row = inv_row + active_row; \
+		int i;  \
+        \
+		if (row >= ROWS)        \
+			break; \
+        \
+		if (type == OBJECT_TYPE_PASSIVE && !mac.unicode) {      \
+			active_column = column; \
+			break; \
+		}       \
+        \
+		printv("flush [%04x%c,F%d%c,B%d%c,S%d%c,O%d%c,H%d%c] %d ... %d\n",      \
+			ac.unicode, mac.unicode ? '*' : ' ',    \
+			ac.foreground, mac.foreground ? '*' : ' ',      \
+			ac.background, mac.background ? '*' : ' ',      \
+			ac.size, mac.size ? '*' : ' ',  \
+			ac.opacity, mac.opacity ? '*' : ' ',    \
+			ac.flash, mac.flash ? '*' : ' ',        \
+			active_column, column - 1);     \
+        \
+		for (i = inv_column + active_column; i < inv_column + column;) {        \
+			vbi_char c;     \
+        \
+			if (i > 39)     \
+				break;  \
+        \
+			c = acp[i];     \
+        \
+			if (mac.underline) {    \
+				int u = ac.underline;   \
+        \
+				if (!mac.unicode)       \
+					ac.unicode = c.unicode; \
+        \
+				if (vbi_is_gfx(ac.unicode)) {   \
+					if (u)  \
+						ac.unicode &= ~0x20; /* separated */    \
+					else    \
+						ac.unicode |= 0x20; /* contiguous */    \
+					mac.unicode = ~0;       \
+					u = 0;  \
+				}       \
+        \
+				c.underline = u;        \
+			}       \
+			if (mac.foreground)     \
+				c.foreground = (ac.foreground != VBI_TRANSPARENT_BLACK) ?       \
+					ac.foreground : (row_color_transparent) ?       \
+					VBI_TRANSPARENT_BLACK : row_color;      \
+			if (mac.background)     \
+				c.background = (ac.background != VBI_TRANSPARENT_BLACK) ?       \
+					ac.background : (row_color_transparent) ?       \
+					VBI_TRANSPARENT_BLACK : row_color;      \
+			if (invert) {   \
+				int t = c.foreground;   \
+        \
+				c.foreground = c.background;    \
+				c.background = t;       \
+			}       \
+			if (mac.opacity)        \
+				c.opacity = ac.opacity; \
+			if (mac.flash)  \
+				c.flash = ac.flash;     \
+			if (mac.conceal)        \
+				c.conceal = ac.conceal; \
+			if (mac.unicode) {      \
+				c.unicode = ac.unicode; \
+				mac.unicode = 0;        \
+        \
+				if (mac.size)   \
+					c.size = ac.size;       \
+				else if (c.size > VBI_DOUBLE_SIZE)      \
+					c.size = VBI_NORMAL_SIZE;       \
+			}       \
+        \
+			acp[i] = c;     \
+        \
+			if (type == OBJECT_TYPE_PASSIVE)        \
+				break;  \
+        \
+			i++;    \
+        \
+			if (type != OBJECT_TYPE_PASSIVE \
+			    && type != OBJECT_TYPE_ADAPTIVE) {  \
+				int raw;        \
+        \
+				raw = (row == 0 && i < 9) ?     \
+					0x20 : vbi_unpar8 (vtp->data.lop.raw[row][i - 1]);      \
+        \
+				/* set-after spacing attributes cancelling non-spacing */       \
+        \
+				switch (raw) {  \
+				case 0x00 ... 0x07:	/* alpha + foreground color */  \
+				case 0x10 ... 0x17:	/* mosaic + foreground color */ \
+					printv("... fg term %d %02x\n", i, raw);        \
+					mac.foreground = 0;     \
+					mac.conceal = 0;        \
+					break;  \
+        \
+				case 0x08:		/* flash */     \
+					mac.flash = 0;  \
+					break;  \
+        \
+				case 0x0A:		/* end box */   \
+				case 0x0B:		/* start box */ \
+					if (i < COLUMNS && vbi_unpar8 (vtp->data.lop.raw[row][i]) == raw) {     \
+						printv("... boxed term %d %02x\n", i, raw);     \
+						mac.opacity = 0;        \
+					}       \
+        \
+					break;  \
+        \
+				case 0x0D:		/* double height */     \
+				case 0x0E:		/* double width */      \
+				case 0x0F:		/* double size */       \
+					printv("... size term %d %02x\n", i, raw);      \
+					mac.size = 0;   \
+					break;  \
+				}       \
+        \
+				if (i > 39)     \
+					break;  \
+        \
+				raw = (row == 0 && i < 8) ?     \
+					0x20 : vbi_unpar8 (vtp->data.lop.raw[row][i]);  \
+        \
+				/* set-at spacing attributes cancelling non-spacing */  \
+        \
+				switch (raw) {  \
+				case 0x09:		/* steady */    \
+					mac.flash = 0;  \
+					break;  \
+        \
+				case 0x0C:		/* normal size */       \
+					printv("... size term %d %02x\n", i, raw);      \
+					mac.size = 0;   \
+					break;  \
+        \
+				case 0x18:		/* conceal */   \
+					mac.conceal = 0;        \
+					break;  \
+        \
+					/*      \
+					 *  Non-spacing underlined/separated display attribute  \
+					 *  cannot be cancelled by a subsequent spacing attribute.      \
+					 */     \
+        \
+				case 0x1C:		/* black background */  \
+				case 0x1D:		/* new background */    \
+					printv("... bg term %d %02x\n", i, raw);        \
+					mac.background = 0;     \
+					break;  \
+				}       \
+			}       \
+		}       \
+        \
+		active_column = column; \
+	})
 
 	/* XXX nested function not portable, to be removed */
-	void
-	flush_row(void)
-	{
-		if (type == OBJECT_TYPE_PASSIVE || type == OBJECT_TYPE_ADAPTIVE)
-			flush(active_column + 1);
-		else
-			flush(COLUMNS);
-
-		if (type != OBJECT_TYPE_PASSIVE)
-			memset(&mac, 0, sizeof(mac));
-	}
+#define flush_row       do {\
+		if (type == OBJECT_TYPE_PASSIVE || type == OBJECT_TYPE_ADAPTIVE)        \
+			flush(active_column + 1);       \
+		else    \
+			flush(COLUMNS); \
+\
+		if (type != OBJECT_TYPE_PASSIVE)        \
+			memset(&mac, 0, sizeof(mac));   \
+	} while (0)
 
 	active_column = 0;
 	active_row = 0;
@@ -1554,7 +1551,7 @@
 				printv("enh set_active row %d col %d\n", row, column);
 
 				if (row > active_row)
-					flush_row();
+					flush_row;
 				else
 					flush(active_column + 1);
 
@@ -1752,7 +1749,7 @@
 				break;
 
 			case 0x15 ... 0x17:	/* object definition */
-				flush_row();
+				flush_row;
 				printv("enh obj definition 0x%02x 0x%02x\n", p->mode, p->data);
 				printv("enh terminated\n");
 				goto swedish;
@@ -1768,7 +1765,7 @@
 			case 0x1F:		/* termination marker */
 			default:
 	                terminate:
-				flush_row();
+				flush_row;
 				printv("enh terminated %02x\n", p->mode);
 				goto swedish;
 			}
