--- ./src/BuiltIn/stringOpSymbol.cc.orig	2014-09-03 02:36:06.000000000 +0200
+++ ./src/BuiltIn/stringOpSymbol.cc	2014-09-03 02:32:45.000000000 +0200
@@ -472,7 +472,7 @@
 		const mpz_class& n0 = succSymbol->getNat(a0);
 		if (n0 <= 255)
 		  {
-		    char c = n0.get_si();
+		    char c[2] = { n0.get_si(), 0 };
 		    return rewriteToString(subject, context, crope(c));
 		  }
 	      }
