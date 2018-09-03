--- cube/cube.cpp.orig	2018-08-07 18:51:55 UTC
+++ cube/cube.cpp
@@ -2922,7 +2922,7 @@ int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPre
     return (int)msg.wParam;
 }
 
-#elif __linux__
+#elif __unix__
 
 int main(int argc, char **argv) {
     Demo demo;
