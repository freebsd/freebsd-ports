--- parse.c.orig	2008-06-26 01:19:07.000000000 +0400
+++ parse.c	2008-06-26 01:20:12.000000000 +0400
@@ -10705,7 +10705,7 @@
 		    rb_mem_clear(vars+i, len-i);
 		}
 		else {
-		    *vars++ = (VALUE)ruby_scope;
+		    *vars++ = 0;
 		    rb_mem_clear(vars, len);
 		}
 		ruby_scope->local_vars = vars;
@@ -10721,6 +10721,7 @@
                if (!(ruby_scope->flags & SCOPE_CLONE))
                    xfree(ruby_scope->local_tbl);
 	    }
+	    ruby_scope->local_vars[-1] = 0; /* no reference needed */
 	    ruby_scope->local_tbl = local_tbl();
 	}
     }
