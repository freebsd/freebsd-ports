Remove the embedded build date and fix build with Clang 6

common/lc_application.cpp:209:23: error: no matching literal operator for call to 'operator""__DATE__' with arguments of types 'const char *' and 'unsigned int', and no matching literal operator template
                                printf("Compiled "__DATE__"\n");
                                                  ^

--- common/lc_application.cpp.orig	2019-05-17 23:24:38 UTC
+++ common/lc_application.cpp
@@ -375,7 +375,6 @@ bool lcApplication::Initialize(QList<QPair<QString, bo
 			printf("LeoCAD Version " LC_VERSION_TEXT "\n");
 #endif
 			printf("LeoCAD Version " LC_VERSION_TEXT "\n");
-			printf("Compiled " __DATE__ "\n");
 
 			ShowWindow = false;
 			return true;
