--- tools/settings_template_readonly.py.orig	2019-08-31 14:51:24 UTC
+++ tools/settings_template_readonly.py
@@ -17,6 +17,10 @@ EMSCRIPTEN_ROOT = os.path.expanduser(os.getenv('EMSCRI
 LLVM_ROOT = os.path.expanduser(os.getenv('LLVM', '{{{ LLVM_ROOT }}}')) # directory
 BINARYEN_ROOT = os.path.expanduser(os.getenv('BINARYEN', '')) # if not set, we will use it from ports
 
+# based on https://github.com/emscripten-core/emscripten/issues/8564#issuecomment-490682686
+LLVM_ADD_VERSION = 'devel'
+CLANG_ADD_VERSION = 'devel'
+
 # Add this if you have manually built the JS optimizer executable (in
 # Emscripten/tools/optimizer) and want to run it from a custom location.
 # Alternatively, you can set this as the environment variable
