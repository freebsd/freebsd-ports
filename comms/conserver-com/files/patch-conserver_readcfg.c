--- conserver/readcfg.c.orig	2022-07-08 01:20:02 UTC
+++ conserver/readcfg.c
@@ -3128,9 +3128,9 @@ ConsoleAdd(CONSENT *c)
 
 	SwapStr(&pCEmatch->motd, &c->motd);
 	SwapStr(&pCEmatch->idlestring, &c->idlestring);
-	SwapStr(&pCEmatch->replstring, &c->breaklist);
+	SwapStr(&pCEmatch->replstring, &c->replstring);
 	SwapStr(&pCEmatch->tasklist, &c->tasklist);
-	SwapStr(&pCEmatch->breaklist, &c->tasklist);
+	SwapStr(&pCEmatch->breaklist, &c->breaklist);
 	pCEmatch->portinc = c->portinc;
 	pCEmatch->portbase = c->portbase;
 	pCEmatch->spinmax = c->spinmax;
