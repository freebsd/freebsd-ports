--- data/reg2xml.c	2012-11-06 09:15:59.000000000 -0600
+++ data/reg2xml.c	2012-11-06 09:33:59.000000000 -0600
@@ -111,7 +111,9 @@
 						fsetpos(fp, &pos);
 					}
 					token = strstr(buffer, ": ");
-					tag = strndup(buffer, token - buffer);
+					tag = malloc((token-buffer) + 1);
+					strncpy(tag, buffer, token-buffer);
+					tag[token-buffer] = 0;
 					token += 2;
 					xmlNewChild(ent, NULL,
 						    (const xmlChar *)lt_strlower(tag),
