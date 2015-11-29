--- src/converter.cpp.orig	2015-10-21 17:26:38 UTC
+++ src/converter.cpp
@@ -88,7 +88,7 @@ main(int argc, char *argv[]) {
 		optind++;
 		const char *ofile = (optind < argc) ? argv[optind] : "converted.tq7";
 		ofstream out;
-		out.open(ofile, ios::out|ios::trunc|ios::binary);
+		out.open(ofile, std::ios::out|std::ios::trunc|std::ios::binary);
 		if (!out.is_open())
 			throw myexc(string("Unable to open ") + ofile);
 		bool haveout = false;
