--- sub_commands/merge_main.cc.orig	2019-05-13 07:46:43 UTC
+++ sub_commands/merge_main.cc
@@ -33,7 +33,7 @@ int merge_main(int argc, char *argv[])
 
   try {
     merge_files(args.input_arg, args.output_arg, out_header, min, max);
-  } catch(MergeError e) {
+  } catch(MergeError &e) {
     err::die(err::msg() << e.what());
   }
 
