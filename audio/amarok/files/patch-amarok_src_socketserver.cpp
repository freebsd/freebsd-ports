
$FreeBSD$

--- amarok/src/socketserver.cpp.orig
+++ amarok/src/socketserver.cpp
@@ -47,8 +47,9 @@
 class AmaroKProcess : public KProcess {
     public:
     virtual int commSetupDoneC() {
+	int i = KProcess::commSetupDoneC();
         amaroK::closeOpenFiles(KProcess::out[0],KProcess::in[0], KProcess::err[0]);
-        return KProcess::commSetupDoneC();
+	return i;
     };
 };
 
