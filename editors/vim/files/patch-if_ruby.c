--- if_ruby.c.orig	Thu Apr  5 02:32:59 2001
+++ if_ruby.c	Sun Apr 29 01:47:30 2001
@@ -66,6 +66,10 @@
 	}
 	line = rb_lastline_get();
 	if (!NIL_P(line)) {
+	    if (TYPE(line) != T_STRING) {
+		EMSG("$_ must be an instance of String");
+		return;
+	    }
 	    ml_replace(i, (char_u *) STR2CSTR(line), 1);
 	    changed();
 #ifdef SYNTAX_HL
