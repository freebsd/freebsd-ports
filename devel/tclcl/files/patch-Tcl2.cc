--- Tcl2.cc.orig	2013-05-13 09:23:36.000000000 +0200
+++ Tcl2.cc	2013-05-13 09:25:20.000000000 +0200
@@ -88,7 +88,7 @@
 	va_list ap;
 	va_start(ap, fmt);
 	vsprintf(bp_, fmt, ap);
-	tcl_->result = bp_;
+	Tcl_SetResult(tcl_, (char *)bp_, NULL);
 }
 
 void Tcl::add_errorf(const char* fmt, ...)
