$FreeBSD$

--- mg.c.orig	Tue Oct 29 16:24:52 2002
+++ mg.c	Tue Oct 29 16:32:26 2002
@@ -562,6 +562,8 @@ Perl_magic_get(pTHX_ SV *sv, MAGIC *mg)
 		(void)SvOK_off(sv);
 	    else if (PL_in_eval)
  		sv_setiv(sv, PL_in_eval & ~(EVAL_INREQUIRE));
+	    else
+		sv_setiv(sv, 0);
 	}
 	break;
     case '\024':		/* ^T */
