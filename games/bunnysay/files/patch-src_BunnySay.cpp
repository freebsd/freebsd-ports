--- src/BunnySay.cpp.orig	2016-08-31 12:47:32 UTC
+++ src/BunnySay.cpp
@@ -34,8 +34,9 @@ L"/ 　 づ";
 // Writes wstring input to the stdout after chunking it and converting
 // all characters to their wide counterparts in unicode
 void BunnySay::writeBunnySay(std::wstring input) {
+  std::wstring_convert<std::codecvt_utf8<wchar_t>,wchar_t> convert;
   input = replaceString(input);
-  std::wcout << bunny;
+  std::cout << convert.to_bytes(bunny);
   bool left = true;
   std::vector<std::wstring> vs;
   vs = splitAtWidth(input + L"　", width);
@@ -54,9 +55,9 @@ void BunnySay::writeBunnySay(std::wstrin
 
     // Add the pipes
     curstring = L"｜" + curstring + L"｜\n";
-    std::wcout << curstring;
+    std::cout << convert.to_bytes(curstring);
    } 
-    std::wcout << bunny2 << std::endl;
+    std::cout << convert.to_bytes(bunny2) << std::endl;
 }
 // Helper function to split a sentance delimited with fixed-width spaces
 // into strings 10 chars or less
