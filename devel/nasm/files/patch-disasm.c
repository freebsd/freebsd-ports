
$FreeBSD$

--- disasm.c.orig
+++ disasm.c
@@ -484,8 +484,8 @@
     return data - origdata;
 }
 
-long disasm (unsigned char *data, char *output, int segsize, long offset,
-	     int autosync, unsigned long prefer)
+long disasm (unsigned char *data, char *output, int outbufsize, int segsize, 
+	     long offset, int autosync, unsigned long prefer)
 {
     struct itemplate **p, **best_p;
     int length, best_length = 0;
@@ -582,27 +582,34 @@
 
     slen = 0;
 
+    /* TODO: snprintf returns the value that the string would have if
+    *	    the buffer were long enough, and not the actual length of 
+    *	    the returned string, so each instance of using the return
+    *	    value of snprintf should actually be checked to assure that
+    *	    the return value is "sane."  Maybe a macro wrapper could
+    *	    be used for that purpose.
+    */
     if (lock)
-	slen += sprintf(output+slen, "lock ");
+	slen += snprintf(output+slen, outbufsize-slen, "lock ");
     for (i = 0; i < ins.nprefix; i++)
 	switch (ins.prefixes[i]) {
-	  case P_REP:   slen += sprintf(output+slen, "rep "); break;
-	  case P_REPE:  slen += sprintf(output+slen, "repe "); break;
-	  case P_REPNE: slen += sprintf(output+slen, "repne "); break;
-	  case P_A16:   slen += sprintf(output+slen, "a16 "); break;
-	  case P_A32:   slen += sprintf(output+slen, "a32 "); break;
-	  case P_O16:   slen += sprintf(output+slen, "o16 "); break;
-	  case P_O32:   slen += sprintf(output+slen, "o32 "); break;
+	  case P_REP:   slen += snprintf(output+slen, outbufsize-slen, "rep "); break;
+	  case P_REPE:  slen += snprintf(output+slen, outbufsize-slen, "repe "); break;
+	  case P_REPNE: slen += snprintf(output+slen, outbufsize-slen, "repne "); break;
+	  case P_A16:   slen += snprintf(output+slen, outbufsize-slen, "a16 "); break;
+	  case P_A32:   slen += snprintf(output+slen, outbufsize-slen, "a32 "); break;
+	  case P_O16:   slen += snprintf(output+slen, outbufsize-slen, "o16 "); break;
+	  case P_O32:   slen += snprintf(output+slen, outbufsize-slen, "o32 "); break;
 	}
 
     for (i = 0; i < elements(ico); i++)
 	if ((*p)->opcode == ico[i]) {
-	    slen += sprintf(output+slen, "%s%s", icn[i],
+	    slen += snprintf(output+slen, outbufsize-slen, "%s%s", icn[i],
 			    whichcond(ins.condition));
 	    break;
 	}
     if (i >= elements(ico))
-	slen += sprintf(output+slen, "%s", insn_names[(*p)->opcode]);
+	slen += snprintf(output+slen, outbufsize-slen, "%s", insn_names[(*p)->opcode]);
     colon = FALSE;
     length += data - origdata;	       /* fix up for prefixes */
     for (i=0; i<(*p)->operands; i++) {
@@ -633,14 +640,14 @@
 	    ins.oprs[i].basereg = whichreg ((*p)->opd[i],
 					    ins.oprs[i].basereg);
 	    if ( (*p)->opd[i] & TO )
-		slen += sprintf(output+slen, "to ");
-	    slen += sprintf(output+slen, "%s",
+		slen += snprintf(output+slen, outbufsize-slen, "to ");
+	    slen += snprintf(output+slen, outbufsize-slen, "%s",
 			    reg_names[ins.oprs[i].basereg-EXPR_REG_START]);
 	} else if (!(UNITY & ~(*p)->opd[i])) {
 	    output[slen++] = '1';
 	} else if ( (*p)->opd[i] & IMMEDIATE ) {
 	    if ( (*p)->opd[i] & BITS8 ) {
-		slen += sprintf(output+slen, "byte ");
+		slen += snprintf(output+slen, outbufsize-slen, "byte ");
 		if (ins.oprs[i].segment & SEG_SIGNED) {
 		    if (ins.oprs[i].offset < 0) {
 			ins.oprs[i].offset *= -1;
@@ -649,17 +656,17 @@
 			output[slen++] = '+';
 		}
 	    } else if ( (*p)->opd[i] & BITS16 ) {
-		slen += sprintf(output+slen, "word ");
+		slen += snprintf(output+slen, outbufsize-slen, "word ");
 	    } else if ( (*p)->opd[i] & BITS32 ) {
-		slen += sprintf(output+slen, "dword ");
+		slen += snprintf(output+slen, outbufsize-slen, "dword ");
 	    } else if ( (*p)->opd[i] & NEAR ) {
-		slen += sprintf(output+slen, "near ");
+		slen += snprintf(output+slen, outbufsize-slen, "near ");
 	    } else if ( (*p)->opd[i] & SHORT ) {
-		slen += sprintf(output+slen, "short ");
+		slen += snprintf(output+slen, outbufsize-slen, "short ");
 	    }
-	    slen += sprintf(output+slen, "0x%lx", ins.oprs[i].offset);
+	    slen += snprintf(output+slen, outbufsize-slen, "0x%lx", ins.oprs[i].offset);
 	} else if ( !(MEM_OFFS & ~(*p)->opd[i]) ) {
-	    slen += sprintf(output+slen, "[%s%s%s0x%lx]",
+	    slen += snprintf(output+slen, outbufsize-slen, "[%s%s%s0x%lx]",
 			    (segover ? segover : ""),
 			    (segover ? ":" : ""),
 			    (ins.oprs[i].addr_size == 32 ? "dword " :
@@ -669,30 +676,30 @@
 	} else if ( !(REGMEM & ~(*p)->opd[i]) ) {
 	    int started = FALSE;
 	    if ( (*p)->opd[i] & BITS8 )
-		slen += sprintf(output+slen, "byte ");
+		slen += snprintf(output+slen, outbufsize-slen, "byte ");
 	    if ( (*p)->opd[i] & BITS16 )
-		slen += sprintf(output+slen, "word ");
+		slen += snprintf(output+slen, outbufsize-slen, "word ");
 	    if ( (*p)->opd[i] & BITS32 )
-		slen += sprintf(output+slen, "dword ");
+		slen += snprintf(output+slen, outbufsize-slen, "dword ");
 	    if ( (*p)->opd[i] & BITS64 )
-		slen += sprintf(output+slen, "qword ");
+		slen += snprintf(output+slen, outbufsize-slen, "qword ");
 	    if ( (*p)->opd[i] & BITS80 )
-		slen += sprintf(output+slen, "tword ");
+		slen += snprintf(output+slen, outbufsize-slen, "tword ");
 	    if ( (*p)->opd[i] & FAR )
-		slen += sprintf(output+slen, "far ");
+		slen += snprintf(output+slen, outbufsize-slen, "far ");
 	    if ( (*p)->opd[i] & NEAR )
-		slen += sprintf(output+slen, "near ");
+		slen += snprintf(output+slen, outbufsize-slen, "near ");
 	    output[slen++] = '[';
 	    if (ins.oprs[i].addr_size)
-		slen += sprintf(output+slen, "%s",
+		slen += snprintf(output+slen, outbufsize-slen, "%s",
 				(ins.oprs[i].addr_size == 32 ? "dword " :
 				 ins.oprs[i].addr_size == 16 ? "word " : ""));
 	    if (segover) {
-		slen += sprintf(output+slen, "%s:", segover);
+		slen += snprintf(output+slen, outbufsize-slen, "%s:", segover);
 		segover = NULL;
 	    }
 	    if (ins.oprs[i].basereg != -1) {
-		slen += sprintf(output+slen, "%s",
+		slen += snprintf(output+slen, outbufsize-slen, "%s",
 				reg_names[(ins.oprs[i].basereg -
 					   EXPR_REG_START)]);
 		started = TRUE;
@@ -700,11 +707,11 @@
 	    if (ins.oprs[i].indexreg != -1) {
 		if (started)
 		    output[slen++] = '+';
-		slen += sprintf(output+slen, "%s",
+		slen += snprintf(output+slen, outbufsize-slen, "%s",
 				reg_names[(ins.oprs[i].indexreg -
 					   EXPR_REG_START)]);
 		if (ins.oprs[i].scale > 1)
-		    slen += sprintf(output+slen, "*%d", ins.oprs[i].scale);
+		    slen += snprintf(output+slen, outbufsize-slen, "*%d", ins.oprs[i].scale);
 		started = TRUE;
 	    }
 	    if (ins.oprs[i].segment & SEG_DISP8) {
@@ -713,20 +720,20 @@
 		    ins.oprs[i].offset = - (signed char) ins.oprs[i].offset;
 		    sign = '-';
 		}
-		slen += sprintf(output+slen, "%c0x%lx", sign,
+		slen += snprintf(output+slen, outbufsize-slen, "%c0x%lx", sign,
 				ins.oprs[i].offset);
 	    } else if (ins.oprs[i].segment & SEG_DISP16) {
 		if (started)
 		    output[slen++] = '+';
-		slen += sprintf(output+slen, "0x%lx", ins.oprs[i].offset);
+		slen += snprintf(output+slen, outbufsize-slen, "0x%lx", ins.oprs[i].offset);
 	    } else if (ins.oprs[i].segment & SEG_DISP32) {
 		if (started)
 		    output[slen++] = '+';
-		slen += sprintf(output+slen, "0x%lx", ins.oprs[i].offset);
+		slen += snprintf(output+slen, outbufsize-slen, "0x%lx", ins.oprs[i].offset);
 	    }
 	    output[slen++] = ']';
 	} else {
-	    slen += sprintf(output+slen, "<operand%d>", i);
+	    slen += snprintf(output+slen, outbufsize-slen, "<operand%d>", i);
 	}
     }
     output[slen] = '\0';
@@ -741,8 +748,8 @@
     return length;
 }
 
-long eatbyte (unsigned char *data, char *output) 
+long eatbyte (unsigned char *data, char *output, int outbufsize) 
 {
-    sprintf(output, "db 0x%02X", *data);
+    snprintf(output, outbufsize, "db 0x%02X", *data);
     return 1;
 }
