--- src/context.cpp.orig	2005-07-19 03:25:16.000000000 +0400
+++ src/context.cpp	2014-11-24 16:07:54.000000000 +0300
@@ -247,7 +247,7 @@
 
 ssgSimpleState* Context::getState(int stateid)
 {
-	this->states.getStep(stateid);
+	return this->states.getStep(stateid);
 }
 
 void Context::addToPool(ssgEntity* obj)
