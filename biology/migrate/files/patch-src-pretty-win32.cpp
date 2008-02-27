--- pretty-win32.cpp.orgi	2008-02-27 08:15:26.000000000 +0100
+++ pretty-win32.cpp	2008-02-27 08:16:07.000000000 +0100
@@ -13,9 +13,3 @@
   _set_new_handler(throw_new_handler);
 }
 #endif
-
-int dummy_function(int do_nothing)
-{
-  print("Some computer fail to compile MIGRATE with empty files\n");
-  return 0;
-}
