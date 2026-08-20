--- flow/MkCertCli.cpp.orig	2023-11-07 15:13:56 UTC
+++ flow/MkCertCli.cpp
@@ -216,7 +216,7 @@ int main(int argc, char** argv) {
 				fmt::print(stderr, "ERROR: unknown option '{}'\n", args.OptionText());
 				return FDB_EXIT_ERROR;
 			default:
-				fmt::print(stderr, "ERROR: unknown error {} with option '{}'\n", err, args.OptionText());
+				fmt::print(stderr, "ERROR: unknown error {} with option '{}'\n", static_cast<int>(err), args.OptionText());
 				return FDB_EXIT_ERROR;
 			}
 		} else {
