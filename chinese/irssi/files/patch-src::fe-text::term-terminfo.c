--- src/fe-text/term-terminfo.c.orig	Mon Oct 20 03:10:02 2003
+++ src/fe-text/term-terminfo.c	Sun Dec 14 01:54:28 2003
@@ -421,16 +421,21 @@
 	if (vcy == term_height-1 && vcx == term_width-1)
 		return; /* last char in screen */
 
-        term_printed_text(1);
 	switch (term_type) {
 	case TERM_TYPE_UTF8:
+	  	term_printed_text(utf8_width(chr));
                 term_addch_utf8(window, chr);
 		break;
 	case TERM_TYPE_BIG5:
-		putc((chr >> 8) & 0xff, window->term->out);
+		if(chr>0xff) {
+			term_printed_text(2);
+			putc((chr >> 8) & 0xff, window->term->out);
+		} else
+			term_printed_text(1);
 		putc((chr & 0xff), window->term->out);
                 break;
 	default:
+		term_printed_text(1);
 		putc(chr, window->term->out);
                 break;
 	}
@@ -443,7 +448,7 @@
 	if (term_detached) return;
 
 	if (vcmove) term_move_real();
-	len = strlen(str);
+	len = strlen(str); // FIXME utf8 or big5
         term_printed_text(len);
 
 	if (vcy != term_height || vcx != 0)
