--- frontend/pisa_main.cc.orig	2008-12-08 02:11:49.000000000 +0100
+++ frontend/pisa_main.cc	2008-12-26 00:42:07.000000000 +0100
@@ -41,6 +41,18 @@
 
 int g_gimp_plugin = 1;
 
+extern "C" {
+int __errno_location;
+#undef stderr;
+FILE *stderr;
+void __assert_fail(const char * assertion, const char * file, unsigned int
+line, const char * function)
+{
+	fprintf(stderr, "fail\n");
+}
+}
+
+
 /*----------------------------------------------------------*/
 int main ( int argc, char * argv [ ] )
 {
