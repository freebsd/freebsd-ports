--- src/cle.c	Sat Dec  4 00:41:14 1999
+++ src/cle.c	Fri Mar 24 15:46:07 2006
@@ -147,8 +147,10 @@
         rl_prep_terminal(_rl_meta_flag);	/* Place the terminal in raw mode */
       } else {
 	/* We are still in echo mode. Register the line in the history */
-        add_history(s);
         len= strlen(s);
+		if (len > 0) {
+        	add_history(s);
+		  }
         s[len]= '\n';
         write(fd, s, len+1);
       }
