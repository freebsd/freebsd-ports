--- src/fe-text/gui-readline.c.orig	Thu Nov 27 01:30:03 2003
+++ src/fe-text/gui-readline.c	Sun Dec 14 01:54:28 2003
@@ -187,7 +187,12 @@
 			out[utf16_char_to_utf8(arr[i], out)] = '\0';
 			g_string_append(str, out);
 		} else {
-			g_string_append_c(str, arr[i]);
+			if(term_type==TERM_TYPE_BIG5) {
+				if(arr[i]>0xff)
+					g_string_append_c(str, arr[i]>>8&0xff);
+				g_string_append_c(str, arr[i]&0xff);
+			} else
+				g_string_append_c(str, arr[i]);
 		}
 	}
 
