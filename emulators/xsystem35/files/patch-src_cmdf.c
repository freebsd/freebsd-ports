--- src/cmdf.c.orig	Sat Dec 21 18:28:35 2002
+++ src/cmdf.c	Thu Jun 14 13:03:47 2007
@@ -82,22 +82,22 @@
 	DEBUG_COMMAND("F1 %d,%d:\n", str_number, skip);
 	
 	for (i = 0; i < skip; i++) {
-		(char *)(nact->datatbl_addr) += (strlen((const char *)nact->datatbl_addr) + 1);
+		nact->datatbl_addr += (strlen((const char *)nact->datatbl_addr) + 1);
 	}
 	
 	v_strcpy(str_number - 1 , (const char *)(nact->datatbl_addr));
-	(char *)(nact->datatbl_addr) += (strlen((const char *)nact->datatbl_addr) + 1);
+	nact->datatbl_addr += (strlen((const char *)nact->datatbl_addr) + 1);
 }
 
 static void commandF2() {
 	int *read_var = sys_getCaliVariable();
 	int skip      = sys_getCaliValue();
 	
-	((WORD *)nact->datatbl_addr) += skip;
+	nact->datatbl_addr += skip * sizeof(WORD);
 	
 	*read_var = LittleEndian_getW(nact->datatbl_addr, 0);
 	
-	((WORD *)nact->datatbl_addr)++;
+	nact->datatbl_addr += sizeof(WORD);
 	
 	DEBUG_COMMAND("F2 %d,%d:\n", *read_var, skip);
 }
@@ -118,7 +118,7 @@
 	
 	for (i = 0; i < count; i++) {
 		*read_var = LittleEndian_getW(nact->datatbl_addr, 0);
-		((WORD *)nact->datatbl_addr)++;
+		nact->datatbl_addr += sizeof(WORD);
 		read_var++;
 	}
 	
@@ -155,7 +155,7 @@
 	for (i = 0; i < count; i++) {
 		for (j = 0; j < data_width; j++) {
 			*(F6Index[j] + i) = LittleEndian_getW(nact->datatbl_addr, 0);
-			((WORD *)nact->datatbl_addr)++;
+			nact->datatbl_addr += sizeof(WORD);
 		}
 	}
 	
