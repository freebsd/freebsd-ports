--- src/cmd2F.c.orig	Mon Jul 21 02:30:16 2003
+++ src/cmd2F.c	Thu Jun 14 13:05:15 2007
@@ -1381,7 +1381,7 @@
 
 	for (i = 0; i < eNumof; i++) {
 		*vData = LittleEndian_getW(nact->datatbl_addr, 0);
-		((WORD *)nact->datatbl_addr)++;
+		nact->datatbl_addr += sizeof(WORD);
 		vData++;
 	}
 	
@@ -1397,14 +1397,14 @@
 	
 	for (i = 0; i < eNumof; i++) {
 		v_strcpy(eStrNum + i -1, (const char *)(nact->datatbl_addr));
-		(char *)(nact->datatbl_addr) += (strlen((const char *)nact->datatbl_addr) + 1);
+		nact->datatbl_addr += (strlen((const char *)nact->datatbl_addr) + 1);
 	}
 }
 
 void commands2F83() {
 	int eNumof  = sys_getCaliValue();
 
-	((WORD *)nact->datatbl_addr) += eNumof;
+	nact->datatbl_addr += eNumof * sizeof(WORD);
 	
 	DEBUG_COMMAND("dataSkipWORD %d:\n", eNumof);
 }
@@ -1414,7 +1414,7 @@
 	int i;
 	
 	for (i = 0; i < eNumof; i++) {
-		(char *)(nact->datatbl_addr) += (strlen((const char *)nact->datatbl_addr) + 1);
+		nact->datatbl_addr += (strlen((const char *)nact->datatbl_addr) + 1);
 	}
 	
 	DEBUG_COMMAND("dataSkipString %d:\n", eNumof);
