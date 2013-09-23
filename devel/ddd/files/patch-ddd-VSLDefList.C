--- ddd/VSLDefList.C.orig	2013-09-23 10:38:30.000000000 +0200
+++ ddd/VSLDefList.C	2013-09-23 10:39:12.000000000 +0200
@@ -60,7 +60,7 @@
     {
 	std::ostringstream s;
 	s << *arg;
-	VSLLib::eval_error("no suiting definition for " + f_name() + s);
+	VSLLib::eval_error("no suiting definition for " + f_name() + s.str().c_str());
     }
 
     return d ? d->eval(arg) : 0;
