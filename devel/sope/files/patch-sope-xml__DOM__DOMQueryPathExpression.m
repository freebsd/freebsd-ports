--- sope-xml/DOM/DOMQueryPathExpression.m.orig	2015-09-16 18:26:50 UTC
+++ sope-xml/DOM/DOMQueryPathExpression.m
@@ -318,7 +318,7 @@
   qpexpr = [DOMQueryPathExpression queryPathWithString:_expr];
   //NSLog(@"Expr: %@", qpexpr);
   
-  pred =
+  pred = (_DOMQPPredicateExpression*)
     [[_DOMQPPredicateQPExpression alloc] initWithQueryPathExpression:qpexpr];
   
   return [pred autorelease];
