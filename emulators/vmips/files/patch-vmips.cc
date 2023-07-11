--- vmips.cc.orig	2013-05-25 22:21:31 UTC
+++ vmips.cc
@@ -591,9 +591,11 @@ vmips::run()
 	return 0;
 }
 
+#if 0
 static void vmips_unexpected() {
   fatal_error ("unexpected exception");
 }
+#endif
 
 static void vmips_terminate() {
   fatal_error ("uncaught exception");
@@ -602,7 +604,9 @@ static void vmips_terminate() {
 int
 main(int argc, char **argv)
 try {
+#if 0
 	std::set_unexpected(vmips_unexpected);
+#endif
 	std::set_terminate(vmips_terminate);
 
 	machine = new vmips(argc, argv);
