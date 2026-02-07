--- src/core/uae/readcpu.c.orig	2007-11-20 18:01:02 UTC
+++ src/core/uae/readcpu.c
@@ -172,7 +172,7 @@ STATIC_INLINE amodes mode_from_str (const char *str)
     if (strncmp (str, "PC16", 4) == 0) return PC16;
     if (strncmp (str, "PC8r", 4) == 0) return PC8r;
     if (strncmp (str, "Immd", 4) == 0) return imm;
-    abort ();
+    uae_abort ();
     return 0;
 }
 
@@ -198,7 +198,7 @@ STATIC_INLINE amodes mode_from_mr (int mode, int reg)
 	 case 7: return am_illg;
 	}
     }
-    abort ();
+    uae_abort ();
     return 0;
 }
 
@@ -316,10 +316,10 @@ static void build_insn (int insn)
 		    case 0: sz = sz_byte; break;
 		    case 1: sz = sz_word; break;
 		    case 2: sz = sz_long; break;
-		    default: abort();
+		    default: uae_abort();
 		    }
 		    break;
-		default: abort();
+		default: uae_abort();
 		}
 	    } else {
 		mnemonic[mnp] = opcstr[pos];
@@ -328,7 +328,7 @@ static void build_insn (int insn)
 		    switch (bitval[bitf]) {
 		    case 0: mnemonic[mnp] = 'R'; break;
 		    case 1: mnemonic[mnp] = 'L'; break;
-		    default: abort();
+		    default: uae_abort();
 		    }
 		}
 		mnp++;
@@ -353,7 +353,7 @@ static void build_insn (int insn)
 	    switch (opcstr[pos++]) {
 	    case 'r': srcreg = bitval[bitr]; srcgather = 1; srcpos = bitpos[bitr]; break;
 	    case 'R': srcreg = bitval[bitR]; srcgather = 1; srcpos = bitpos[bitR]; break;
-	    default: abort();
+	    default: uae_abort();
 	    }
 	    break;
 	case 'A':
@@ -361,7 +361,7 @@ static void build_insn (int insn)
 	    switch (opcstr[pos++]) {
 	    case 'r': srcreg = bitval[bitr]; srcgather = 1; srcpos = bitpos[bitr]; break;
 	    case 'R': srcreg = bitval[bitR]; srcgather = 1; srcpos = bitpos[bitR]; break;
-	    default: abort();
+	    default: uae_abort();
 	    }
 	    switch (opcstr[pos]) {
 	    case 'p': srcmode = Apdi; pos++; break;
@@ -424,7 +424,7 @@ static void build_insn (int insn)
 		    srcpos = bitpos[bitp];
 		}
 		break;
-	    default: abort();
+	    default: uae_abort();
 	    }
 	    break;
 	case 'd':
@@ -522,7 +522,7 @@ static void build_insn (int insn)
 		}
 	    }
 	    break;
-	default: abort();
+	default: uae_abort();
 	}
 	/* safety check - might have changed */
 	if (srcmode != Areg && srcmode != Dreg && srcmode != Aind
@@ -546,10 +546,10 @@ static void build_insn (int insn)
 	    switch (opcstr[pos++]) {
 	    case 'r': destreg = bitval[bitr]; dstgather = 1; dstpos = bitpos[bitr]; break;
 	    case 'R': destreg = bitval[bitR]; dstgather = 1; dstpos = bitpos[bitR]; break;
-	    default: abort();
+	    default: uae_abort();
 	    }
             if (dstpos < 0 || dstpos >= 32)
-		abort ();
+		uae_abort ();
 	    break;
 	case 'A':
 	    destmode = Areg;
@@ -557,10 +557,10 @@ static void build_insn (int insn)
 	    case 'r': destreg = bitval[bitr]; dstgather = 1; dstpos = bitpos[bitr]; break;
 	    case 'R': destreg = bitval[bitR]; dstgather = 1; dstpos = bitpos[bitR]; break;
 	    case 'x': destreg = 0; dstgather = 0; dstpos = 0; break;
-	    default: abort();
+	    default: uae_abort();
 	    }
             if (dstpos < 0 || dstpos >= 32)
-		abort ();
+		uae_abort ();
 	    switch (opcstr[pos]) {
 	    case 'p': destmode = Apdi; pos++; break;
 	    case 'P': destmode = Aipi; pos++; break;
@@ -580,7 +580,7 @@ static void build_insn (int insn)
 	    case 'J': destmode = immi; destreg = bitval[bitJ]; break;
 	    case 'k': destmode = immi; destreg = bitval[bitk]; break;
 	    case 'K': destmode = immi; destreg = bitval[bitK]; break;
-	    default: abort();
+	    default: uae_abort();
 	    }
 	    break;
 	case 'd':
@@ -680,7 +680,7 @@ static void build_insn (int insn)
 		}
 	    }
 	    break;
-	default: abort();
+	default: uae_abort();
 	}
 	/* safety check - might have changed */
 	if (destmode != Areg && destmode != Dreg && destmode != Aind
@@ -707,7 +707,7 @@ static void build_insn (int insn)
 		    table68k[opc].mnemo = lookuptab[find].mnemo;
 		    break;
 		}
-		if (strlen(lookuptab[find].name) == 0) abort();
+		if (strlen(lookuptab[find].name) == 0) uae_abort();
 	    }
 	}
 	else {
@@ -792,7 +792,7 @@ static void handle_merges (long int opcode)
 	    smsk = 3; sbitdst = 4; break;
 	 default:
 	    smsk = 0; sbitdst = 0;
-	    abort();
+	    uae_abort();
 	    break;
 	}
 	smsk <<= table68k[opcode].spos;
