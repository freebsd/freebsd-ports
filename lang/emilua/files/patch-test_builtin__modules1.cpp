--- test/builtin_modules1.cpp.orig	2024-09-02 21:31:27 UTC
+++ test/builtin_modules1.cpp
@@ -21,11 +21,9 @@ namespace fs = std::filesystem;
 namespace hana = boost::hana;
 namespace fs = std::filesystem;
 
-#if EMILUA_CONFIG_USE_STANDALONE_ASIO
-namespace asio = ::asio;
-#else // EMILUA_CONFIG_USE_STANDALONE_ASIO
+#if !EMILUA_CONFIG_USE_STANDALONE_ASIO
 namespace asio = boost::asio;
-#endif // EMILUA_CONFIG_USE_STANDALONE_ASIO
+#endif // !EMILUA_CONFIG_USE_STANDALONE_ASIO
 
 extern char** environ;
 
