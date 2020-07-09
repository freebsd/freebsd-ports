--- src/popt.c.orig	2020-05-18 07:43:13 UTC
+++ src/popt.c
@@ -168,6 +168,7 @@ poptContext poptGetContext(const char * name, int argc
 	con->os->next = 1;		/* skip argv[0] */
 
     con->leftovers = calloc( (size_t)(argc + 1), sizeof(*con->leftovers) );
+    con->allocLeftovers = argc + 1;
     con->options = options;
     con->aliases = NULL;
     con->numAliases = 0;
@@ -1269,8 +1270,21 @@ int poptGetNextOpt(poptContext con)
 		    con->os->nextArg = xstrdup(origOptString);
 		    return 0;
 		}
-		if (con->leftovers != NULL)	/* XXX can't happen */
-		    con->leftovers[con->numLeftovers++] = origOptString;
+		if (con->leftovers != NULL) {	/* XXX can't happen */
+		    /* One might think we can never overflow the leftovers
+		       array.  Actually, that's true, as long as you don't
+		       use poptStuffArgs()... */
+		    if ((con->numLeftovers + 1) >= (con->allocLeftovers)) {
+			con->allocLeftovers += 10;
+			con->leftovers =
+			    realloc(con->leftovers,
+				    sizeof(*con->leftovers) * con->allocLeftovers);
+		    }
+		    con->leftovers[con->numLeftovers++]
+			= xstrdup(origOptString); /* so a free of a stuffed
+						     argv doesn't give us a
+						     dangling pointer */
+		}
 		continue;
 	    }
 
@@ -1519,6 +1533,8 @@ poptItem poptFreeItems(poptItem items, int nitems)
 
 poptContext poptFreeContext(poptContext con)
 {
+    int i;
+
     if (con == NULL) return con;
     poptResetContext(con);
 
@@ -1528,7 +1544,11 @@ poptContext poptFreeContext(poptContext con)
     con->execs = poptFreeItems(con->execs, con->numExecs);
     con->numExecs = 0;
 
+    for (i = 0; i < con->numLeftovers; i++) {
+        con->leftovers[i] = _free(&con->leftovers[i]);
+    }
     con->leftovers = _free(con->leftovers);
+
     con->finalArgv = _free(con->finalArgv);
     con->appName = _free(con->appName);
     con->otherHelp = _free(con->otherHelp);
