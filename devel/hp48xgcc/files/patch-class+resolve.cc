--- class/resolve.cc.orig	1995-06-24 08:36:34.000000000 +0400
+++ class/resolve.cc	2013-10-09 13:46:12.000000000 +0400
@@ -1,7 +1,7 @@
 
 #include "clld.h"
 
-#include <iostream.h>
+#include <iostream>
 #include <set_error.h>
 
 int resolve_references (List<InternalObjectFile> & obs, List<CodeImport> & cimports,
@@ -42,7 +42,7 @@ int resolve_references (List<InternalObj
 							
 							if (foundexp) {
 								if (foundexp->isfloat) {
-									cerr << "sorry, external floating point symbols not supported, yet.\n";
+									std::cerr << "sorry, external floating point symbols not supported, yet.\n";
 									searchob = (ListItem<InternalObjectFile> *)0;
 									break;
 								}
@@ -51,7 +51,7 @@ int resolve_references (List<InternalObj
 									if (searchob->shared) {
 										searchob->ShLibNumber = aktshlibnum++;
 										if (aktshlibnum >= 45) {
-											cerr << "ERROR: maximum number of shared libraries exceeded -\n"
+											std::cerr << "ERROR: maximum number of shared libraries exceeded -\n"
 											        "       use '-static' on one or more of your libraries\n";
 											searchob = (ListItem<InternalObjectFile> *)0;
 											break;
@@ -64,7 +64,7 @@ int resolve_references (List<InternalObj
 								
 								if (aktob->shared) {
 									if (foundexp->numerical) {
-										cerr << "ERROR: shared-library imports must be resolved by non-numerical\n"
+										std::cerr << "ERROR: shared-library imports must be resolved by non-numerical\n"
 										        "       symbols. Violated by symbol '" << aktimp->name << "',\n"
 										        "       imported by shared-library '" << aktob->name << "',\n"
 										        "       exported by object '" << searchob->name << "'.\n";
@@ -118,7 +118,7 @@ int resolve_references (List<InternalObj
 											add_error("WARNING: symbol '"+aktimp->name+"', imported by\n"
 											          "         object-file '"+aktob->name+"', exported by\n"
 											          "         object-file '"+searchob->name+"' with invalid value","");
-											cerr << get_error();
+											std::cerr << get_error();
 										} else {
 											unsigned long long tmp = aktob->body.peek(aktimp->offset, aktimp->nibsize);
 											tmp += foundexp->ivalue;
@@ -133,17 +133,17 @@ int resolve_references (List<InternalObj
 						if (! searchob) {
 							if (!shared) {
 								unrefs.insert(aktimp->name);
-								cerr << "ERROR: unable to resolve symbol '" << aktimp->name << "',\n"
+								std::cerr << "ERROR: unable to resolve symbol '" << aktimp->name << "',\n"
 								        "       referenced by object-file '" << aktob->name << "'\n";
 								if (unrefs.size() > 50) {
-									cerr << "ABORT, too many unresolved symbols\n";
+									std::cerr << "ABORT, too many unresolved symbols\n";
 									return -1;
 								}
 								result = -1;
 							} else {
 								// unreferenced symbol for shared library...
 								if (aktimp->nibsize < 5 || (! aktimp->reloc_demand) ) {
-									cerr << "ERROR: run-time imports for shared libraries must be\n"
+									std::cerr << "ERROR: run-time imports for shared libraries must be\n"
 									        "       non-numerical and >= 5 nibbles in size. This is\n"
 									        "       not the case with symbol '" << aktimp->name << "'\n"
 									        "       referenced by object-file '" << aktob->name << "'\n";
