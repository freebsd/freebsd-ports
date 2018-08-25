Remove the embedded build date and fix build with Clang 6

common/lc_application.cpp:209:23: error: no matching literal operator for call to 'operator""__DATE__' with arguments of types 'const char *' and 'unsigned int', and no matching literal operator template
                                printf("Compiled "__DATE__"\n");
                                                  ^

--- common/lc_application.cpp.orig	2018-08-25 03:56:08 UTC
+++ common/lc_application.cpp
@@ -206,7 +206,6 @@ bool lcApplication::Initialize(int argc, char* argv[],
 			else if ((strcmp(Param, "-v") == 0) || (strcmp(Param, "--version") == 0))
 			{
 				printf("LeoCAD Version " LC_VERSION_TEXT "\n");
-				printf("Compiled "__DATE__"\n");
 
 				return false;
 			}
