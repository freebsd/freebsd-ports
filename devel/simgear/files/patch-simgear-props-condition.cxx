--- simgear/props/condition.cxx.orig	2012-04-28 14:55:45.758238526 +0300
+++ simgear/props/condition.cxx	2012-04-28 14:57:16.771484540 +0300
@@ -297,19 +297,19 @@ doComparison (const SGPropertyNode * lef
   }
   case props::INT:
     return doComp<int>(left->getIntValue(), right->getIntValue(), 
-           precision ? abs(precision->getIntValue()/2) : 0 );
+           precision ? std::abs(precision->getIntValue()/2) : 0 );
 
   case props::LONG:
     return doComp<long>(left->getLongValue(), right->getLongValue(), 
-           precision ? abs(precision->getLongValue()/2L) : 0L );
+           precision ? std::abs(precision->getLongValue()/2L) : 0L );
 
   case props::FLOAT:
     return doComp<float>(left->getFloatValue(), right->getFloatValue(), 
-           precision ? fabs(precision->getFloatValue()/2.0f) : 0.0f );
+           precision ? std::fabs(precision->getFloatValue()/2.0f) : 0.0f );
 
   case props::DOUBLE:
     return doComp<double>(left->getDoubleValue(), right->getDoubleValue(), 
-           precision ? fabs(precision->getDoubleValue()/2.0) : 0.0 );
+           precision ? std::fabs(precision->getDoubleValue()/2.0) : 0.0 );
 
   case props::STRING:
   case props::NONE:
