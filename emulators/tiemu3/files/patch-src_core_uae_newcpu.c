--- src/core/uae/newcpu.c.orig	2008-05-25 13:08:41 UTC
+++ src/core/uae/newcpu.c
@@ -148,7 +148,7 @@ static void build_cpufunctbl (void)
 	if (table68k[opcode].handler != -1) {
 	    f = cpufunctbl[table68k[opcode].handler];
 	    if (f == op_illg_1)
-		abort();
+		uae_abort();
 	    cpufunctbl[opcode] = f;
 	}
     }
@@ -1575,7 +1575,7 @@ void m68k_go (int may_quit)
 {
     if (in_m68k_go || !may_quit) {
 	write_log ("Bug! m68k_go is not reentrant.\n");
-	abort ();
+	uae_abort ();
     }
 
     reset_frame_rate_hack ();
