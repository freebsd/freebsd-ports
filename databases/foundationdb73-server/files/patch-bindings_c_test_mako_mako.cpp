--- bindings/c/test/mako/mako.cpp.orig	2023-11-07 15:13:56 UTC
+++ bindings/c/test/mako/mako.cpp
@@ -2378,7 +2378,7 @@ int statsProcessMain(Arguments const& args,
 		fmt::fprintf(fp, "\"txntrace\": %d,", args.txntrace);
 		fmt::fprintf(fp, "\"txntagging\": %d,", args.txntagging);
 		fmt::fprintf(fp, "\"txntagging_prefix\": \"%s\",", args.txntagging_prefix);
-		fmt::fprintf(fp, "\"streaming_mode\": %d,", args.streaming_mode);
+		fmt::fprintf(fp, "\"streaming_mode\": %d,", static_cast<int>(args.streaming_mode));
 		fmt::fprintf(fp, "\"disable_ryw\": %d,", args.disable_ryw);
 		fmt::fprintf(fp, "\"transaction_timeout_db\": %d,", args.transaction_timeout_db);
 		fmt::fprintf(fp, "\"transaction_timeout_tx\": %d,", args.transaction_timeout_tx);
