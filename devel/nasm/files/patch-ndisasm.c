
$FreeBSD$

--- ndisasm.c.orig
+++ ndisasm.c
@@ -243,10 +243,10 @@
 	    nextsync = next_sync (offset, &synclen);
 	}
 	while (p > q && (p - q >= INSN_MAX || lenread == 0)) {
-	    lendis = disasm (q, outbuf, bits, offset, autosync, prefer);
+	    lendis = disasm (q, outbuf, sizeof(outbuf), bits, offset, autosync, prefer);
 	    if (!lendis || lendis > (p - q) ||
 		(unsigned long)lendis > nextsync-offset)
-		lendis = eatbyte (q, outbuf);
+		lendis = eatbyte (q, outbuf, sizeof(outbuf));
 	    output_ins (offset, q, lendis, outbuf);
 	    q += lendis;
 	    offset += lendis;
