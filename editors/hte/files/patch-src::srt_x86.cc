--- srt/srt_x86.cc.orig	Mon Sep  2 02:05:13 2002
+++ srt/srt_x86.cc	Wed Aug  4 17:53:58 2004
@@ -60,13 +60,13 @@
 		k = &cpu->flags[(idx-8) % X86_FLAGS];
 		(*k)->done();
 		delete *k;
-		((Object*)*k) = o;
+		k = (sym_bool **)o;
 	} else {
 		sym_int **k;
 		k = &cpu->regs[idx & 7];
 		(*k)->done();
 		delete *k;
-		((Object*)*k) = o;
+		k = (sym_int **)o;
 	}
 }
 
