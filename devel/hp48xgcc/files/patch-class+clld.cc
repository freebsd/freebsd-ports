--- class/clld.cc	3 Nov 2004 06:57:51 -0000	1.1
+++ class/clld.cc	4 Nov 2004 10:58:04 -0000	1.2
@@ -5,7 +5,7 @@
 
 #include <set_error.h>
 
-#include <fstream.h>
+#include <fstream>
 
 //extern "C" {
 //	#include <math.h>
@@ -22,7 +22,7 @@ int link_obs ( List<InternalObjectFile> 
 		// eventually warn about unused object-files
 		if (! aktob->used) {
 		    if (verbose)
-			cerr << "WARNING: file '"+aktob->name+"' will not be linked\n"
+			std::cerr << "WARNING: file '"+aktob->name+"' will not be linked\n"
 				     "         because none of its exported symbols were used\n";
 		} else {
 			
@@ -130,7 +130,7 @@ int read_objfile( List<InternalObjectFil
 	BIstream f;
 	f.open(name, ios::in | ios::binary);
 #else
-	ifstream f(name, ios::in | ios::bin);
+	std::ifstream f(name, std::ios::in | std::ios::binary);
 #endif
 	if (f.fail()) {
 	  if (!library)
@@ -175,7 +175,7 @@ int read_objfile( List<InternalObjectFil
 	obs.add_tail(ni);
 	
 	if (verbose) {
-		cerr << "read '"+name+"', " << ni->relocs.length() << " relocs, "
+		std::cerr << "read '"+name+"', " << ni->relocs.length() << " relocs, "
 		     << ni->imports.length() << " imports, "
 		     << ni->exports.size() << " exports.\n";
 	}
@@ -185,7 +185,7 @@ int read_objfile( List<InternalObjectFil
 
 int next_arg(int & argc, const char ** & aktarg, Str & p) {
 	if (argc <= 1) {
-		cerr << "missing parameter for option '" << *aktarg << "'\n";
+		std::cerr << "missing parameter for option '" << *aktarg << "'\n";
 		return -1;
 	}
 	aktarg++;
@@ -196,7 +196,7 @@ int next_arg(int & argc, const char ** &
 
 void print_syntax(void) {
 	
-	cerr << "clld [-v] [-o <target-filename>] [-static <*.slo-file>]\n"
+	std::cerr << "clld [-v] [-o <target-filename>] [-static <*.slo-file>]\n"
 	        "     [-shared] <object-file(s)>... \n";
 
 }
@@ -268,7 +268,7 @@ int main( int argc, const char ** argv )
 					return 20;
 				}
 			} else {
-				cerr << "unknown option '" << arg << "', type clld -h for help\n";
+				std::cerr << "unknown option '" << arg << "', type clld -h for help\n";
 				return 20; 
 			}
 			
@@ -279,11 +279,11 @@ int main( int argc, const char ** argv )
 	}
 	
 	if (verbose) {
-		cerr << "clld " << (version_tag+1) << "\nwritten by Lutz Vieweg 1994\n";
+		std::cerr << "clld " << (version_tag+1) << "\nwritten by Lutz Vieweg 1994\n";
 	}
 	
 	if (obs.length() == 0) {
-		cerr << "you need to specify at least one object file to link\n";
+		std::cerr << "you need to specify at least one object file to link\n";
 		return 20;
 	}
 	
@@ -293,7 +293,7 @@ int main( int argc, const char ** argv )
 		     p = p->get_next()
 		    ) {
 			if (p->shared) {
-				cerr << "ERROR: shared libraries have to be built from static\n"
+				std::cerr << "ERROR: shared libraries have to be built from static\n"
 				        "       object-files only, cannot link '" << p->name << "'\n";
 				return 20; 
 			}
@@ -307,7 +307,7 @@ int main( int argc, const char ** argv )
 	List<InternalObjectFileP> shlibs;
 	
 	if (resolve_references(obs, cimports, shlibs)) {
-		cerr << "linkage failed due to unresolved references\n";
+		std::cerr << "linkage failed due to unresolved references\n";
 		return 20;
 	}
 	
@@ -332,10 +332,10 @@ int main( int argc, const char ** argv )
 		BOstream shl_stream;
 		shl_stream.open ( shl_name, ios::out | ios::bin | ios::trunc );
 #else
-		ofstream shl_stream(shl_name, ios::out | ios::bin | ios::trunc );
+		std::ofstream shl_stream(shl_name, std::ios::out | std::ios::binary | std::ios::trunc );
 #endif
 		if (shl_stream.fail()) {
-			cerr << "ERROR: unable to open file '"+shl_name+"' for writing\n";
+			std::cerr << "ERROR: unable to open file '"+shl_name+"' for writing\n";
 			return 20;
 		}
 		
@@ -348,7 +348,7 @@ int main( int argc, const char ** argv )
 #endif
 
 		if (verbose) {
-				cerr << "wrote '"+shl_name+"', " << resobj.relocs.length() << " relocs, "
+				std::cerr << "wrote '"+shl_name+"', " << resobj.relocs.length() << " relocs, "
 				     << resobj.imports.length() << " imports, "
 				     << resobj.exports.size() << " exports.\n";
 		}
@@ -358,7 +358,7 @@ int main( int argc, const char ** argv )
 #else
 		if (shl.fail()) {
 #endif
-			cerr << "ERROR: write to file '"+shl_name+"' failed\n";
+			std::cerr << "ERROR: write to file '"+shl_name+"' failed\n";
 			return 20;
 		}
 	}
@@ -528,10 +528,10 @@ int main( int argc, const char ** argv )
 	BOstream dst_stream;
 	dst_stream.open (bin_name, ios::out | ios::bin | ios::trunc );
 #else
-	ofstream dst_stream(bin_name, ios::out | ios::bin | ios::trunc );
+	std::ofstream dst_stream(bin_name, std::ios::out | std::ios::binary | std::ios::trunc );
 #endif
 	if (dst_stream.fail()) {
-		cerr << "ERROR: unable to open file '"+bin_name+"' for writing\n";
+		std::cerr << "ERROR: unable to open file '"+bin_name+"' for writing\n";
 		return 20;
 	}
 	
@@ -544,12 +544,12 @@ int main( int argc, const char ** argv )
 	dst_stream.write( (char *)resobj.body, (resobj.body.length()+1)>>1 );
 	if (dst_stream.fail()) {
 #endif
-		cerr << "ERROR: write to file '"+bin_name+"' failed\n";
+		std::cerr << "ERROR: write to file '"+bin_name+"' failed\n";
 		return 20;
 	}
 	
 	if (verbose) {
-		cerr << "wrote '" << bin_name << "', " << resobj.body.length() << " nibbles, "
+		std::cerr << "wrote '" << bin_name << "', " << resobj.body.length() << " nibbles, "
 		     << shlibs.length() << " shared libraries, " << resobj.relocs.length()
 		     << " relocs.\n";
 	}
