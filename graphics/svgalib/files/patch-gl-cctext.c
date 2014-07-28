--- gl/cctext.c.orig	Sat Sep 30 20:48:05 2000
+++ gl/cctext.c	Mon Sep 20 23:00:19 1999
@@ -0,0 +1,322 @@
+/* Framebuffer Graphics Libary for Linux, 
+ * Copyright 1998 Wei Yongming
+ * This code is based on partially Harm Hanemaayer's work.
+ */
+/* cctext.c Chinese (two-byte) Character text writing and fonts */
+
+
+#include <stdlib.h>
+#include <stdio.h>
+#include <stdarg.h>
+#include <vga.h>
+#include "inlstring.h"		/* include inline string operations */
+
+#include "vgagl.h"
+#include "def.h"
+
+
+/* CCText/font functions */
+// The default font matrics values.
+static int afont_width = 8;
+static int cfont_width = 16;
+static int font_height = 16;
+static char *afont_address;
+static char *cfont_address;
+static int afont_charsize = 128;
+static int cfont_charsize = 256;
+// The writemode of cc font is always COMPRESSED.
+static int font_writemode = WRITEMODE_OVERWRITE;
+static int compressed_font_bg = 0;
+static int compressed_font_fg = 15;
+
+void gl_setccfont(int afw, int cfw, int fh, void *afont, void* cfont)
+{
+    afont_width = afw;
+    cfont_width = cfw;
+    font_height = fh;
+    afont_charsize = afont_width * font_height * BYTESPERPIXEL;
+    cfont_charsize = cfont_width * font_height * BYTESPERPIXEL;
+    afont_address = afont;
+    cfont_address = cfont;
+}
+
+void gl_setccwritemode(int m)
+{
+    font_writemode = m;
+}
+
+void gl_setccfontcolors(int bg, int fg)
+{
+    compressed_font_bg = bg;
+    compressed_font_fg = fg;
+}
+
+static int getnextchar(char* s, uchar* cc)
+{
+    if( s[0] == '\0') return 0;
+
+    cc[0] = (unsigned char)(*s);
+    cc[1] = (unsigned char)(*(s + 1));
+   
+    if( ((unsigned char)cc[0] > 0xa0) && ((unsigned char)cc[1] > 0xa0) )
+        return 1;
+    
+    cc[1] = '\0';
+ 
+    return 1;
+}
+
+static void expandcchar(int bg, int fg, uchar* c, unsigned char *bitmap)
+{
+    int x, y;
+    int c1, c2;
+    unsigned char *font;
+    int b = 0;                  /* keep gcc happy with b = 0 - MW */
+
+    c1 = c[0];
+    c2 = c[1];
+
+    font = cfont_address + ((c1 - 161)*94 + c2 - 161) * 
+                          (font_height * ((cfont_width + 7) / 8));
+
+    for (y = 0; y < font_height; y++)
+        for (x = 0; x < cfont_width; x++) {
+            if (x % 8 == 0)
+                b = *font++;
+            if (b & (128 >> (x % 8)))   /* pixel */
+                switch (BYTESPERPIXEL) {
+                case 1:
+                    *bitmap = fg;
+                    bitmap++;
+                    break;
+                case 2:
+                    *(ushort *) bitmap = fg;
+                    bitmap += 2;
+                    break;
+                case 3:
+                    *(ushort *) bitmap = fg;
+                    *(bitmap + 2) = fg >> 16;
+                    bitmap += 3;
+                    break;
+                case 4:
+                    *(uint *) bitmap = fg;
+                    bitmap += 4;
+            } else              /* background pixel */
+                switch (BYTESPERPIXEL) {
+                case 1:
+                    *bitmap = bg;
+                    bitmap++;
+                    break;
+                case 2:
+                    *(ushort *) bitmap = bg;
+                    bitmap += 2;
+                    break;
+                case 3:
+                    *(ushort *) bitmap = bg;
+                    *(bitmap + 2) = bg;
+                    bitmap += 3;
+                    break;
+                case 4:
+                    *(uint *) bitmap = bg;
+                    bitmap += 4;
+                }
+        }
+}
+
+static void expandchar(int bg, int fg, int c, unsigned char *bitmap)
+{
+    int x, y;
+    unsigned char *font;
+    int b = 0;			/* keep gcc happy with b = 0 - MW */
+
+    font = afont_address + c * (font_height * ((afont_width + 7) / 8));
+
+    for (y = 0; y < font_height; y++)
+	for (x = 0; x < afont_width; x++) {
+	    if (x % 8 == 0)
+		b = *font++;
+	    if (b & (128 >> (x % 8)))	/* pixel */
+		switch (BYTESPERPIXEL) {
+		case 1:
+		    *bitmap = fg;
+		    bitmap++;
+		    break;
+		case 2:
+		    *(ushort *) bitmap = fg;
+		    bitmap += 2;
+		    break;
+		case 3:
+		    *(ushort *) bitmap = fg;
+		    *(bitmap + 2) = fg >> 16;
+		    bitmap += 3;
+		    break;
+		case 4:
+		    *(uint *) bitmap = fg;
+		    bitmap += 4;
+	    } else		/* background pixel */
+		switch (BYTESPERPIXEL) {
+		case 1:
+		    *bitmap = bg;
+		    bitmap++;
+		    break;
+		case 2:
+		    *(ushort *) bitmap = bg;
+		    bitmap += 2;
+		    break;
+		case 3:
+		    *(ushort *) bitmap = bg;
+		    *(bitmap + 2) = bg;
+		    bitmap += 3;
+		    break;
+		case 4:
+		    *(uint *) bitmap = bg;
+		    bitmap += 4;
+		}
+	}
+}
+
+/* Write using compressed font. */
+
+void gl_ccwrite(int x, int y, char* s)
+{
+    unsigned char *bitmap;
+    uchar cc[2];
+
+    bitmap = (unsigned char *)alloca(cfont_width * font_height * BYTESPERPIXEL);
+    if( !(font_writemode & WRITEMODE_MASKED) ) {
+        while( getnextchar(s, cc) ) {
+            if( cc[1] != '\0') {
+                expandcchar(compressed_font_bg, compressed_font_fg,
+                            cc, bitmap);
+                gl_putbox(x, y, cfont_width, font_height, bitmap);
+                s += 2;
+                x += cfont_width;
+            }
+            else {
+                expandchar(compressed_font_bg, compressed_font_fg,
+                           cc[0], bitmap);
+                gl_putbox(x, y, afont_width, font_height, bitmap);
+                s += 1;
+                x += afont_width;
+            }
+        }
+    }
+    else {           // masked write.
+        while( getnextchar(s, cc) ) {
+            if( cc[1] != '\0') {
+                expandcchar(0, compressed_font_fg,
+                            cc, bitmap);
+                gl_putboxmask(x, y, cfont_width, font_height, bitmap);
+                s += 2;
+                x += cfont_width;
+            }
+            else {
+                expandchar(0, compressed_font_fg,
+                           cc[0], bitmap);
+                gl_putboxmask(x, y, afont_width, font_height, bitmap);
+                s += 1;
+                x += afont_width;
+            }
+        }
+    }
+}
+
+void gl_ccwriten(int x, int y, int n, char *s)
+{
+    char *str = alloca(n + 1);
+    memcpy(str, s, n);
+    str[n] = 0;
+    gl_ccwrite(x, y, str);
+}
+
+#ifndef SVGA_AOUT
+
+static int ccnprintf(int sx, int sy, 
+                        size_t bufs, const char *fmt, va_list args)
+{
+    char *buf;
+    static int x = 0, y = 0, x_start = 0;
+    int n;
+
+    buf = alloca(bufs);
+    n = vsnprintf(buf, bufs, fmt, args);
+    if (n < 0)
+	return n; /* buffer did not suffice, return and retry */
+
+    if ((sx >= 0) && (sy >= 0)) {
+	x = x_start = sx;
+	y = sy;
+    }
+	
+    for (; *buf; buf++)
+	switch (*buf) {
+	case '\a':		/* badly implemented */
+	    fputc('\a', stdout);
+	    fflush(stdout);
+	    break;
+	case '\b':
+	    x -= afont_width;
+	    if (x < x_start) {
+		x = WIDTH + (x_start % afont_width);
+		while(x + afont_width > WIDTH)
+		    x -= afont_width;
+		if (y >= font_height)
+		    y -= font_height;
+	    }
+	    break;
+	case '\n':
+	  newline:
+	    y += font_height;
+	    if (y + font_height > HEIGHT)
+		y %= font_height;
+	case '\r':
+	    x = x_start;
+	    break;
+	case '\t':
+	    x += ((TEXT_TABSIZE - 
+                 ((x - x_start) / afont_width) % TEXT_TABSIZE) * afont_width);
+	    goto chk_wrap;
+	    break;
+	case '\v':
+	    y += font_height;
+	    if (y + font_height > HEIGHT)
+		y %= font_height;
+	    break;
+	default:
+            if( ((unsigned char)(*buf) > 0xa0) 
+                && ((unsigned char)(*(buf + 1)) > 0xa0)) {
+                gl_ccwriten(x, y, 2, buf);
+                buf += 1;
+	        x += cfont_width;
+            }
+            else {
+                gl_ccwriten(x, y, 1, buf);
+                x += afont_width;
+            }
+        chk_wrap:
+	    if (x + afont_width > WIDTH)
+		goto newline;
+	}
+    return n;
+}
+
+int gl_ccprintf(int x, int y, const char *fmt, ...)
+{
+    size_t bufs = BUFSIZ;
+    int result;
+    va_list args;
+
+    va_start(args, fmt);
+
+    /* Loop until buffer size suffices */
+    do {
+	result = ccnprintf(x, y, bufs, fmt, args);
+	bufs <<= 1;
+    } while(result < 0);
+	
+    va_end(args);
+    return result;
+}
+
+#endif
+
