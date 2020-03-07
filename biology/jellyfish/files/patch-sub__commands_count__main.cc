--- sub_commands/count_main.cc.orig	2018-04-16 12:46:09 UTC
+++ sub_commands/count_main.cc
@@ -360,7 +360,7 @@ int count_main(int argc, char *argv[])
         uint64_t max = args.upper_count_given ? args.upper_count_arg : std::numeric_limits<uint64_t>::max();
         try {
           merge_files(files, args.output_arg, header, min, max);
-        } catch(MergeError e) {
+        } catch(MergeError &e) {
           err::die(err::msg() << e.what());
         }
         if(!args.no_unlink_flag) {
