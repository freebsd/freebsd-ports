
$FreeBSD$

--- labels.c.orig
+++ labels.c
@@ -221,7 +221,7 @@
 	slen += strlen(lpostfix);
 	slen++; /* room for that null char */
 	xsymbol = nasm_malloc(slen);
-	sprintf(xsymbol,"%s%s%s",lprefix,lptr->defn.label,lpostfix);
+	snprintf(xsymbol,slen,"%s%s%s",lprefix,lptr->defn.label,lpostfix);
 
 	ofmt->symdef (xsymbol, segment, offset, exi, 
 		special ? special : lptr->defn.special);
@@ -286,7 +286,7 @@
 	slen += strlen(lpostfix);
 	slen++; /* room for that null char */
 	xsymbol = nasm_malloc(slen);
-	sprintf(xsymbol,"%s%s%s",lprefix,lptr->defn.label,lpostfix);
+	snprintf(xsymbol,slen,"%s%s%s",lprefix,lptr->defn.label,lpostfix);
 
 	ofmt->symdef (xsymbol, segment, offset, exi, 
 		special ? special : lptr->defn.special);
