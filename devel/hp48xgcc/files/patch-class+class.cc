--- class/class.cc	3 Nov 2004 06:57:51 -0000	1.1
+++ class/class.cc	4 Nov 2004 10:58:04 -0000	1.2
@@ -39,8 +39,8 @@
 #include "fp_support.h"
 
 // We do our I/O via streams
-#include <iostream.h>
-#include <fstream.h>
+#include <iostream>
+#include <fstream>
 
 // Bstreams are the (re-)storable variant of streams
 #include <Bstream.h>
@@ -211,7 +211,7 @@ void norm_err(const Str & err) {
 	
 	++error_count;
 
-	cerr << "ERROR: " << err << '\n';
+	std::cerr << "ERROR: " << err << '\n';
 	
 	if (!akt_line) return;
 	
@@ -227,7 +227,7 @@ void norm_err(const Str & err) {
 	f = npara(a);
 	i = o + npara(a).val();
 	
-	cerr << "FILE: '" << f << "' LINE: " << i << '\n';
+	std::cerr << "FILE: '" << f << "' LINE: " << i << '\n';
 	
 	akt_line->obc = "";
 	akt_line->para = "";
@@ -740,9 +740,9 @@ void unused_labels(void) {
 			if (! p->accessed) {
 				if (f) {
 					f = false;
-					cerr << "following non-numerical labels were never used: \n";
+					std::cerr << "following non-numerical labels were never used: \n";
 				}
-				cerr << p->name << '\n';
+				std::cerr << p->name << '\n';
 			}
 		}
 		p = l_arr.get_next(p);
@@ -2369,7 +2369,7 @@ NibStr & line_nibs(void) {
 			static bool relwarn = true;
 			if (relwarn) {
 				relwarn = false;
-				cerr << "WARNING: RELTAB pseudo-op used, relocation table\n"
+				std::cerr << "WARNING: RELTAB pseudo-op used, relocation table\n"
 				        "         is dumped & cleared.\n";
 			}
 			obj.relocs.clear();
@@ -2846,17 +2846,17 @@ int read_file(Str f_name) {
 	bool macflag = false;
 	
 	if (verbose) {
-		cerr << "reading '" << f_name << "' \n";
+		std::cerr << "reading '" << f_name << "' \n";
 	}
 	line = 1;
 	src.add_tail(SourceLine("", "AKTFILE", "", f_name+(char)1+"1"+(char)1 )); 
 	
-	ifstream * f;
-	f = new ifstream( (char *)f_name);
+	std::ifstream * f;
+	f = new std::ifstream( (char *)f_name);
 	if (f->fail()) {
 		delete f;
 		f_name = incdir_name + f_name;
-		f = new ifstream( (char *)f_name);
+		f = new std::ifstream( (char *)f_name);
 		if (f->fail()) {
 			delete f;
 			fatal_err("couldn't open source-file '"+f_name+"'");
@@ -2995,7 +2995,7 @@ int read_file(Str f_name) {
 						if ( b == "") break;
 						mac_rpl[i] = b;
 						if ( b == mac_src[i] ) {
-							cerr << "ERROR: macro parameter replacement includes original\n";
+							std::cerr << "ERROR: macro parameter replacement includes original\n";
 							macflag = false;
 						}
 					}
@@ -3029,20 +3029,20 @@ int read_file(Str f_name) {
 			a = npara(a);
 			lis->para = "";
 			
-			streampos f_pos = f->tellg();
+			std::streampos f_pos = f->tellg();
 			delete f;
 			a = a.next_word();
 			if (verbose) {
-				cerr << "                           \r";
+				std::cerr << "                           \r";
 			}
 			if (read_file(a)) {
 				add_error("unable to read complete file '"+f_name+"'","");
 				return 20;
 			}
 			if (verbose) {
-				cerr << "reading '" << f_name << "' \r";
+				std::cerr << "reading '" << f_name << "' \r";
 			}
-			f = new ifstream ((char *)f_name);
+			f = new std::ifstream ((char *)f_name);
 			if (f == 0 || f->fail()) {
 				set_error("unable to reopen source file ",(char *)f_name);
 				return 20;
@@ -3055,12 +3055,12 @@ int read_file(Str f_name) {
 		
 		if ((line & 0xff) == 0) {
 			if (verbose) {
-				cerr << "reading '" << f_name << "' line " << line << '\r';		
+				std::cerr << "reading '" << f_name << "' line " << line << '\r';		
 			}
 		}
 	}
 	if (verbose) {
-		cerr << "                                                 \r";
+		std::cerr << "                                                 \r";
 	}
 	
 	delete f;
@@ -3112,7 +3112,7 @@ void pass1(void) {
 		adr += akt_line->binlen;
 
 		if ((line & 0xff) == 0 && verbose) {
-			cerr << "pass 1: " << line << " 	\r";
+			std::cerr << "pass 1: " << line << " 	\r";
 		}
 		
 		line++;
@@ -3121,7 +3121,7 @@ void pass1(void) {
 	
 	nib_len = adr;
 	if (verbose) {
-		cerr << "                        \r";
+		std::cerr << "                        \r";
 	}
 }
 
@@ -3141,7 +3141,7 @@ void pass2(void) {
 		adr += akt_line->binlen;
 		
 		if ((line & 0xff) == 0 && verbose) {
-			cerr << "pass 2: " << line << "   \r";
+			std::cerr << "pass 2: " << line << "   \r";
 		}
 		
 		line++;
@@ -3149,12 +3149,12 @@ void pass2(void) {
 	}
 		
 	if (adr != nib_len) {
-		cerr << "ERROR: file length changed between passes (" << nib_len <<
+		std::cerr << "ERROR: file length changed between passes (" << nib_len <<
 		         " / " << adr << ")\n";
 	}
 	
 	if (verbose) {
-		cerr << "                              \r";
+		std::cerr << "                              \r";
 	}
 }
 
@@ -3201,19 +3201,19 @@ void passn(void) {
 			p = l_arr.get_next(p);
 		}
 		if (verbose) {
-			cerr << "pass n[" << sc << "]\r";
+			std::cerr << "pass n[" << sc << "]\r";
 		}
 		if (solv_rdy || sc>msc) break;
 	}
 	if (verbose) {
-		cerr << "                       \r";
+		std::cerr << "                       \r";
 	}
 	if (sc > msc) {
-		cerr << "unresolvable reference(s) between following labels:\n";
+		std::cerr << "unresolvable reference(s) between following labels:\n";
 		AVLItem<Symbol> * p = l_arr.get_head(); 
 		while (p) {
 			if (! p->resolved) {
-				cerr << p->name << '\n';
+				std::cerr << p->name << '\n';
 			}
 			p = l_arr.get_next(p);
 		}		
@@ -3264,7 +3264,7 @@ int get_cli_line(int argc, char ** argv)
 		} else if (a == "-v") {
 			verbose = true;
 		} else {
-			cerr << syntax;
+			std::cerr << syntax;
 			fatal_err("unknown command-line parameter '"+a+"'");
 			return 20;
 		}
@@ -3273,7 +3273,7 @@ int get_cli_line(int argc, char ** argv)
 	}
 	
 	if ( src_name == "" ) {
-		cerr << syntax;
+		std::cerr << syntax;
 		fatal_err("no source-file specified");
 		return 20;
 	}
@@ -3292,7 +3292,7 @@ int main (int argc, char ** argv) {
 	}
 	
 	if (verbose) {
-		cerr << "CLASS " << (version_tag+1) << "\nwritten by Lutz Vieweg 1991-1994\n";
+		std::cerr << "CLASS " << (version_tag+1) << "\nwritten by Lutz Vieweg 1991-1994\n";
 	}
 	
 	def_macs();
@@ -3310,10 +3310,10 @@ int main (int argc, char ** argv) {
 	BOstream of;
 	of.open(obj.name, ios::out | ios::binary);
 #else
-	ofstream of( obj.name, ios::out | ios::bin );
+	std::ofstream of( obj.name, std::ios::out | std::ios::binary );
 #endif
 	if (of.fail()) {
-		cerr << "FATAL ERROR: unable to open output file '" << obj.name << "'\n";
+		std::cerr << "FATAL ERROR: unable to open output file '" << obj.name << "'\n";
 		return 20;
 	}
 
@@ -3322,7 +3322,7 @@ int main (int argc, char ** argv) {
 		of.write( (char *)obj.body , (obj.body.length()+1) >> 1 );
 		status = of.fail();
 		if (verbose) {
-			cerr << "assembled " << src_name << " to executable ";
+			std::cerr << "assembled " << src_name << " to executable ";
 		}
 	} else {
 #ifndef OBSOLETE_LIBGXX
@@ -3334,15 +3334,15 @@ int main (int argc, char ** argv) {
 		status = of.fail();
 #endif
 		if (verbose) {
-			cerr << "assembled " << src_name << " to object-file ";
+			std::cerr << "assembled " << src_name << " to object-file ";
 		}
 	}
 	
 	if (verbose) {
-		cerr << obj.name <<  " (" << nib_len << " nibbles)\n";
+		std::cerr << obj.name <<  " (" << nib_len << " nibbles)\n";
 	}
 	if (status) {
-		cerr << "FATAL ERROR: write operation on file '" << obj.name << "' failed\n";
+		std::cerr << "FATAL ERROR: write operation on file '" << obj.name << "' failed\n";
 		return 20;
 	}
 	
