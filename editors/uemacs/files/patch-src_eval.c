

Patch attached with submission follows:

--- /usr/ports/editors/uemacs/work/src/eval.c	1996-01-02 20:13:24.000000000 +1100
+++ src/eval.c	2012-01-23 06:07:26.878469857 +1100
@@ -1480,7 +1480,7 @@
 	/* if we are turning this facility off, just flag so */
 	if (wclist == NULL || *wclist == 0) {
 		wlflag = FALSE;
-		return;
+		return NULL;
 	}
 
 	/* first clear the table */
@@ -1492,7 +1492,7 @@
 	while (*wclist)
 		wordlist[(unsigned char)(*wclist++)] = TRUE;	/* ep */
 	wlflag = TRUE;
-	return;
+	return NULL;
 }
 
 /*	getwlist:	place in a buffer a list of characters


