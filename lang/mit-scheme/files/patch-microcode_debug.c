--- microcode/debug.c.orig	2022-09-07 06:01:33 UTC
+++ microcode/debug.c
@@ -1419,7 +1419,7 @@ verify_stack (SCHEME_OBJECT * sp, SCHEME_OBJECT * bott
 	  if (n_words > 1000)
 	    outf_error ("%#lx: Extraordinary finger size: %ld\n",
 			((unsigned long)sp), n_words);
-	  sp = STACK_LOCATIVE_OFFSET (sp, n_words);
+	  sp = STACK_LOCATIVE_ADD (sp, n_words);
 	}
       else if (type == TC_MANIFEST_CLOSURE
 	       || type == TC_BROKEN_HEART
