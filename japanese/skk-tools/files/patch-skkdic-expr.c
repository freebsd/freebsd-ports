--- skkdic-expr.c.orig	2011-04-11 04:42:08.000000000 +0900
+++ skkdic-expr.c	2012-10-13 05:40:10.000000000 +0900
@@ -336,7 +336,7 @@
 
     /* 語尾をtkeyにコピー */
     for (p = headtop; *s != '/'; s++, p++) {
-	if (*s < 0x20) return;
+	if (*s < 0x20) return 0;
 	*p = *s;
     }
     tkey.dsize = p - keybuf;
@@ -344,12 +344,12 @@
     /* 語幹部分をcontentにコピーする */
     p = content; 
     for( ; *s != ']'; s++, p++) {
-	if (*s < 0x20) return;
+	if (*s < 0x20) return 0;
 	*p = *s;
     }
     *p = '\0';
     if (*++s != '/') 
-	return ;		/* フォーマットエラー */
+	return 0;		/* フォーマットエラー */
     
     /* 古いものと比べて必要ならappend */
     otails = dbm_fetch(okuriheaddb, tkey);
@@ -555,7 +555,7 @@
 
     /* 語尾をtkeyにコピー */ 
     for (p = headtop; *s != '/'; s++, p++) {
-	if (*s < 0x20) return;
+	if (*s < 0x20) return 0;
 	*p = *s;
     }
     tkey.dsize = p - keybuf;
@@ -563,12 +563,12 @@
     /* 語幹部分をcontentにコピーする */
     p = content; 
     for( ; *s != ']'; s++, p++) {
-	if (*s < 0x20) return;
+	if (*s < 0x20) return 0;
 	*p = *s;
     }
     *p = '\0';
     if (*++s != '/') 
-	return ;		/* フォーマットエラー */
+	return 0;		/* フォーマットエラー */
     
     /* 古いものと比べて必要ならreplace/delete */
     otails = dbm_fetch(okuriheaddb, tkey);
@@ -600,12 +600,12 @@
 			goto next;
 		    }
 		}
-		return;
+		return 0;
 	    }
 	}
       next:;
     }
-    return;
+    return 0;
 }
 
 static void
@@ -708,7 +708,7 @@
 
     tails = dbm_fetch(okuritaildb, tkey);
     if (tails.dptr == NULL)  {
-	return;
+	return 0;
     } else {
 	fseek(dbcontent, getpos(tails.dptr), 0);
 	db_gets(tail_content, BLEN, dbcontent);
@@ -717,7 +717,7 @@
 	for(e = s; e[1] != '\0'; s = e + 2) {
 	    for (e = s; *e != '/'; e++)
 		if (*e < 0x20) 
-		    return;
+		    return 0;
 
 	    strncpy(headtop, s, e - s);
 	    tkey.dsize = (headtop - keybuf) + (e - s);
