--- src/BuiltIn/stringOpSymbol.cc.orig	2008-09-12 01:03:36 UTC
+++ src/BuiltIn/stringOpSymbol.cc
@@ -472,7 +472,7 @@ StringOpSymbol::eqRewrite(DagNode* subject, RewritingC
 		const mpz_class& n0 = succSymbol->getNat(a0);
 		if (n0 <= 255)
 		  {
-		    char c = n0.get_si();
+		    char c[2] = { static_cast<char>(n0.get_si()), 0 };
 		    return rewriteToString(subject, context, crope(c));
 		  }
 	      }
