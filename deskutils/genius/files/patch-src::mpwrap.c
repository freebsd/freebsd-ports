--- src/mpwrap.c.orig	Wed Nov 10 04:05:51 2004
+++ src/mpwrap.c	Fri Dec 24 17:25:26 2004
@@ -1933,8 +1933,9 @@
 			if G_UNLIKELY ( ! mpz_invert (r.data.ival,
 						      r.data.ival,
 						      mod->data.ival)) {
-				char *n1 = mpwl_getstring_for_error (&r);
-				char *n2 = mpwl_getstring_for_error (mod);
+				char *n1,*n2;
+				n1 = mpwl_getstring_for_error (&r);
+				n2 = mpwl_getstring_for_error (mod);
 				gel_errorout (_("Can't invert %s modulo %s "
 					       "in %s"),
 					      n1, n2, "powm");
