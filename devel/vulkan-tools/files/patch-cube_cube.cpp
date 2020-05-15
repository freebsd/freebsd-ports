--- cube/cube.cpp.orig	2020-04-08 02:52:46 UTC
+++ cube/cube.cpp
@@ -2999,7 +2999,7 @@ int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPre
     return (int)msg.wParam;
 }
 
-#elif __linux__
+#elif __unix__
 
 int main(int argc, char **argv) {
     Demo demo;
