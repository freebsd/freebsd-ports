--- tools/settings_template_readonly.py.orig	2019-05-09 05:05:10 UTC
+++ tools/settings_template_readonly.py
@@ -17,6 +17,10 @@ EMSCRIPTEN_ROOT = os.path.expanduser(os.
 LLVM_ROOT = os.path.expanduser(os.getenv('LLVM', '{{{ LLVM_ROOT }}}')) # directory
 BINARYEN_ROOT = os.path.expanduser(os.getenv('BINARYEN', '')) # if not set, we will use it from ports
 
+# based on https://github.com/emscripten-core/emscripten/issues/8564#issuecomment-490682686
+LLVM_ADD_VERSION = 'devel'
+CLANG_ADD_VERSION = 'devel'
+
 # If not specified, defaults to sys.executable.
 # PYTHON = 'python'
 
