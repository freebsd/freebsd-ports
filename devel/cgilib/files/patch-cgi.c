--- cgi.c.orig	2010-05-19 18:38:27.000000000 +0400
+++ cgi.c	2010-05-19 18:38:55.000000000 +0400
@@ -641,7 +641,7 @@ s_cgi *cgiReadVariables ()
 		free (result[k]->value);
 		free (value);
 		result[k]->value = sptr;
-		cgiDebugOutput (1, "%s: %s", result[i]->name, result[i]->value);
+		cgiDebugOutput (1, "%s: %s", result[k]->name, result[k]->value);
 	    }
 	}
 	cp = ++ip;
