--- compiler/types.cc.orig	Tue Nov 27 09:09:45 2001
+++ compiler/types.cc	Sun Dec  8 02:07:42 2002
@@ -49,7 +49,7 @@
 
 void
 IDLType::writeUnionAccessors(ostream &ostr,Indent &indent, string const &id, string const &discriminatorVal,
-									IDLTypedef const *activeTypedef = NULL) const{
+									IDLTypedef const *activeTypedef ) const{
 	string typespec,dcl;
 	getCPPStubDeclarator(IDL_PARAM_IN,"",typespec,dcl,activeTypedef);
 	ostr
@@ -64,7 +64,7 @@
 
 void
 IDLType::writeUnionModifiers(ostream &ostr,Indent &indent, string const &id, string const &discriminatorVal,
-									IDLTypedef const *activeTypedef = NULL) const{
+									IDLTypedef const *activeTypedef ) const{
 	string typespec,dcl;
 	getCPPStubDeclarator(IDL_PARAM_IN,"param",typespec,dcl,activeTypedef);
 	ostr
@@ -82,7 +82,7 @@
 
 void
 IDLType::writeUnionReferents(ostream &ostr,Indent &indent, string const &id, string const &discriminatorVal,
-							IDLTypedef const *activeTypedef = NULL) const{
+							IDLTypedef const *activeTypedef ) const{
 }
 
 IDLType const &
@@ -118,30 +118,30 @@
 
 	// misc stuff
 	void getCPPMemberDeclarator(string const &id,string &typespec,string &dcl,
-								IDLTypedef const *activeTypedef = NULL) const {
+								IDLTypedef const *activeTypedef ) const {
 		throw IDLExVoid();
 	}
 	void writeTypedef(ostream &ostr,Indent &indent,IDLCompilerState &state,
 					  IDLElement &dest,IDLScope const &scope,
-					  IDLTypedef const *activeTypedef = NULL) const {
+					  IDLTypedef const *activeTypedef ) const {
 		throw IDLExVoid();
 	}
 
 	// struct / exception stuff
 	void getCPPStructCtorDeclarator(string const &id,string &typespec, string &dcl,
-									IDLTypedef const *activeTypedef = NULL) const {
+									IDLTypedef const *activeTypedef ) const {
 		throw IDLExVoid();
 	}
 	void writeCPPStructCtor(ostream &ostr,Indent &indent,string const &id,
-							IDLTypedef const *activeTypedef = NULL) const {
+							IDLTypedef const *activeTypedef ) const {
 		throw IDLExVoid();
 	}
 	void writeCPPStructPacker(ostream &ostr,Indent &indent,string const &id,
-							  IDLTypedef const *activeTypedef = NULL) const {
+							  IDLTypedef const *activeTypedef ) const {
 		throw IDLExVoid();
 	}
 	void writeCPPStructUnpacker(ostream &ostr,Indent &indent,string const &id,
-								IDLTypedef const *activeTypedef = NULL) const {
+								IDLTypedef const *activeTypedef ) const {
 		throw IDLExVoid();
 	}
 	
@@ -158,68 +158,68 @@
 	}
 	void writeCPPStubMarshalCode(IDL_param_attr attr,string const &id,
 								 ostream &ostr, Indent &indent,
-								 IDLTypedef const *activeTypedef = NULL) const {
+								 IDLTypedef const *activeTypedef ) const {
 		throw IDLExVoid();
 	}
 	string getCPPStubParameterTerm(IDL_param_attr attr,string const &id,
-								   IDLTypedef const *activeTypedef = NULL) const {
+								   IDLTypedef const *activeTypedef ) const {
 		throw IDLExVoid();
 	}
 	void writeCPPStubDemarshalCode(IDL_param_attr attr,string const &id,
 								   ostream &ostr,Indent &indent,
-								   IDLTypedef const *activeTypedef = NULL) const {
+								   IDLTypedef const *activeTypedef ) const {
 		throw IDLExVoid();
 	}
 
 	// stub return stuff
 	void getCPPStubReturnDeclarator(string const &id,string &typespec, string &dcl,
-									IDLTypedef const *activeTypedef = NULL) const {
+									IDLTypedef const *activeTypedef ) const {
 		typespec = "void";
 		dcl = id;
 	}
 	void writeCPPStubReturnPrepCode(ostream &ostr,Indent &indent,
-									IDLTypedef const *activeTypedef = NULL) const {
+									IDLTypedef const *activeTypedef ) const {
 	}
 	string getCPPStubReturnAssignment() const {
 		return "";
 	}
 	void writeCPPStubReturnDemarshalCode(ostream &ostr,Indent &indent,
-										 IDLTypedef const *activeTypedef = NULL) const {
+										 IDLTypedef const *activeTypedef ) const {
 	}
 
 	// skel stuff
 	void getCSkelDeclarator(IDL_param_attr attr,string const &id,string &typespec,string &dcl,
-							IDLTypedef const *activeTypedef = NULL) const {
+							IDLTypedef const *activeTypedef ) const {
 		throw IDLExVoid();
 	}
 	void writeCPPSkelDemarshalCode(IDL_param_attr attr,string const &id,ostream &ostr,Indent &indent,
-								   IDLTypedef const *activeTypedef = NULL) const {
+								   IDLTypedef const *activeTypedef ) const {
 		throw IDLExVoid();
 	}
 	string getCPPSkelParameterTerm(IDL_param_attr attr,string const &id,
-								   IDLTypedef const *activeTypedef = NULL) const {
+								   IDLTypedef const *activeTypedef ) const {
 		throw IDLExVoid();
 	}
 	void writeCPPSkelMarshalCode(IDL_param_attr attr,string const &id,ostream &ostr,Indent &indent,
-								 IDLTypedef const *activeTypedef = NULL) const {
+								 IDLTypedef const *activeTypedef ) const {
 		throw IDLExVoid();
 	}
 
 	// skel return stuff
 	void getCSkelReturnDeclarator(string const &id,string &typespec,string &dcl,
-								  IDLTypedef const *activeTypedef = NULL) const {
+								  IDLTypedef const *activeTypedef ) const {
 		typespec = "void";
 		dcl = id;
 	}
 	void writeCPPSkelReturnPrepCode(ostream &ostr,Indent &indent,bool passthru,
-									IDLTypedef const *activeTypedef = NULL) const {
+									IDLTypedef const *activeTypedef ) const {
 	}
 	string getCPPSkelReturnAssignment(bool passthru,
-									  IDLTypedef const *activeTypedef = NULL) const {
+									  IDLTypedef const *activeTypedef ) const {
 		return "";
 	}
 	void writeCPPSkelReturnMarshalCode(ostream &ostr,Indent &indent,bool passthru,
-									   IDLTypedef const *activeTypedef = NULL) const {
+									   IDLTypedef const *activeTypedef ) const {
 	}
 	string getInvalidReturn() const {
 		return "return;";
@@ -245,13 +245,13 @@
 	
 	// misc stuff
 	void getCPPMemberDeclarator(string const &id,string &typespec,string &dcl,
-								IDLTypedef const *activeTypedef = NULL) const {
+								IDLTypedef const *activeTypedef ) const {
 		typespec = IDL_CORBA_NS "::String_mgr";
 		dcl = id;
 	}
 	void writeTypedef(ostream &ostr,Indent &indent,IDLCompilerState &state,
 					  IDLElement &dest,IDLScope const &scope,
-					  IDLTypedef const *activeTypedef = NULL) const {
+					  IDLTypedef const *activeTypedef ) const {
 		ostr
 		<< indent << "typedef char *" << ' '
 		<< dest.getCPPIdentifier() << ';' << endl;
@@ -263,21 +263,21 @@
 
 	// struct / exception stuff
 	void getCPPStructCtorDeclarator(string const &id,string &typespec,string &dcl,
-									IDLTypedef const *activeTypedef = NULL) const {
+									IDLTypedef const *activeTypedef ) const {
 		typespec = "char const";
 		dcl = "*_par_" + id;
 	}
 	void writeCPPStructCtor(ostream &ostr,Indent &indent,string const &id,
-							IDLTypedef const *activeTypedef = NULL) const {
+							IDLTypedef const *activeTypedef ) const {
 		ostr << indent << id << " = _par_" << id << ';' << endl;
 	}
 	void writeCPPStructPacker(ostream &ostr,Indent &indent,string const &id,
-							  IDLTypedef const *activeTypedef = NULL) const {
+							  IDLTypedef const *activeTypedef ) const {
 		ostr << indent << "_cstruct." << id
 		<< " = " IDL_CORBA_NS "::string_dup("<< id << ");" << endl;
 	}
 	void writeCPPStructUnpacker(ostream &ostr,Indent &indent,string const &id,
-								IDLTypedef const *activeTypedef = NULL) const {
+								IDLTypedef const *activeTypedef ) const {
 		ostr << indent << id
 		<< " = " IDL_CORBA_NS "::string_dup(_cstruct." << id << ");" << endl;
 	}
@@ -285,7 +285,7 @@
 	
 	void
 	writeUnionModifiers(ostream &ostr,Indent &indent, string const &id, string const &discriminatorVal,
-					  IDLTypedef const *activeTypedef = NULL) const{
+					  IDLTypedef const *activeTypedef ) const{
 		ostr
 		<< indent << "void " << id << "(char const *param){" << endl;
 		ostr
@@ -321,7 +321,7 @@
   
 	void
 	writeUnionAccessors(ostream &ostr,Indent &indent, string const &id, string const &discriminatorVal,
-					  IDLTypedef const *activeTypedef = NULL) const{
+					  IDLTypedef const *activeTypedef ) const{
 		ostr
 		<< indent << "char const *" << id << "() const {" << endl;
 		ostr
@@ -357,7 +357,7 @@
 		}
 	}
 	string getCPPStubParameterTerm(IDL_param_attr attr,string const &id,
-								   IDLTypedef const *activeTypedef = NULL) const {
+								   IDLTypedef const *activeTypedef ) const {
 		switch (attr) {
 		case IDL_PARAM_INOUT:
 			return "&"+id;
@@ -370,49 +370,49 @@
 
 	// stub return stuff
 	void getCPPStubReturnDeclarator(string const &id,string &typespec,string &dcl,
-									IDLTypedef const *activeTypedef = NULL) const {
+									IDLTypedef const *activeTypedef ) const {
 		typespec = "char";
 		dcl = "*" + id;
 	}
 	void writeCPPStubReturnPrepCode(ostream &ostr,Indent &indent,
-									IDLTypedef const *activeTypedef = NULL) const {
+									IDLTypedef const *activeTypedef ) const {
 		ostr << indent << "char *_retval = NULL;" << endl;
 	}
 	string getCPPStubReturnAssignment() const {
 		return "_retval = ";
 	}
 	void writeCPPStubReturnDemarshalCode(ostream &ostr,Indent &indent,
-										 IDLTypedef const *activeTypedef = NULL) const {
+										 IDLTypedef const *activeTypedef ) const {
 		ostr << indent << "return _retval;" << endl;
 	}
 
 	// skel stuff
 	void getCSkelDeclarator(IDL_param_attr attr,string const &id,string &typespec,string &dcl,
-							IDLTypedef const *activeTypedef = NULL) const {
+							IDLTypedef const *activeTypedef ) const {
 		typespec = attr == IDL_PARAM_IN ? "char const" : "char";
 		dcl = attr == IDL_PARAM_IN ? "*"+id : "**"+id;
 	}
 	string getCPPSkelParameterTerm(IDL_param_attr attr,string const &id,
-								   IDLTypedef const *activeTypedef = NULL) const {
+								   IDLTypedef const *activeTypedef ) const {
 		return attr == IDL_PARAM_IN ? id : "*"+id;
 	}
 
 	// skel return stuff
 	void getCSkelReturnDeclarator(string const &id,string &typespec,string &dcl,
-								  IDLTypedef const *activeTypedef = NULL) const {
+								  IDLTypedef const *activeTypedef ) const {
 		typespec = "char";
 		dcl = "*"+id;
 	}
 	void writeCPPSkelReturnPrepCode(ostream &ostr,Indent &indent,bool passthru,
-									IDLTypedef const *activeTypedef = NULL) const {
+									IDLTypedef const *activeTypedef ) const {
 		ostr << indent << "char *_retval = NULL;" << endl;
 	}
 	string getCPPSkelReturnAssignment(bool passthru,
-									  IDLTypedef const *activeTypedef = NULL) const {
+									  IDLTypedef const *activeTypedef ) const {
 		return "_retval = ";
 	}
 	void writeCPPSkelReturnMarshalCode(ostream &ostr,Indent &indent,bool passthru,
-									   IDLTypedef const *activeTypedef = NULL) const {
+									   IDLTypedef const *activeTypedef ) const {
 		ostr << indent << "return _retval;" << endl;
 	}
 	string getInvalidReturn() const {
@@ -523,12 +523,12 @@
 		return true;
 	}
 	void getCPPStructCtorDeclarator(string const &id,string &typespec,string &dcl,
-									IDLTypedef const *activeTypedef = NULL) const {
+									IDLTypedef const *activeTypedef ) const {
 		typespec = "const " + getTypeName() + "&";
 		dcl = "_par_" + id;
 	}
 	void writeCPPStructCtor(ostream &ostr,Indent &indent,string const &id,
-							IDLTypedef const *activeTypedef = NULL) const {
+							IDLTypedef const *activeTypedef ) const {
 		ostr << indent << id << " = _par_" << id << ';' << endl;
 	}
 	void getCPPStubDeclarator(IDL_param_attr attr,string const &id,string &typespec,string &dcl,
@@ -549,7 +549,7 @@
 		}
 	}
 	string getCPPStubParameterTerm(IDL_param_attr attr,string const &id,
-								   IDLTypedef const *activeTypedef = NULL) const {
+								   IDLTypedef const *activeTypedef ) const {
 		string retval;
 		switch (attr) {
 		case IDL_PARAM_IN:
@@ -565,26 +565,26 @@
 
 	// stub return stuff
 	void getCPPStubReturnDeclarator(string const &id,string &typespec,string &dcl,
-									IDLTypedef const *activeTypedef = NULL) const {
+									IDLTypedef const *activeTypedef ) const {
 		typespec = IDL_CORBA_NS "::Any";
 		dcl = "*" + id;
 	}
 	void writeCPPStubReturnPrepCode(ostream &ostr,Indent &indent,
-									IDLTypedef const *activeTypedef = NULL) const {
+									IDLTypedef const *activeTypedef ) const {
 		ostr << indent << "CORBA_any *_retval = NULL;" << endl;
 	}
 	string getCPPStubReturnAssignment() const {
 		return "_retval = ";
 	}
 	void writeCPPStubReturnDemarshalCode(ostream &ostr,Indent &indent,
-										 IDLTypedef const *activeTypedef = NULL) const {
+										 IDLTypedef const *activeTypedef ) const {
 		ostr << indent << "return " 
 			<< idlGetCast("_retval", IDL_CORBA_NS "::Any*" ) << ";" << endl;
 	}
 
 	// skel stuff
 	void getCSkelDeclarator(IDL_param_attr attr,string const &id,string &typespec,string &dcl,
-							IDLTypedef const *activeTypedef = NULL) const {
+							IDLTypedef const *activeTypedef ) const {
 		switch( attr ) {
 		case IDL_PARAM_IN:
 			typespec = "const CORBA_any";
@@ -600,7 +600,7 @@
 		}
 	}
 	string getCPPSkelParameterTerm(IDL_param_attr attr,string const &id,
-								   IDLTypedef const *activeTypedef = NULL) const {
+								   IDLTypedef const *activeTypedef ) const {
 		switch(attr) {
 		case IDL_PARAM_IN:
 			return idlGetCast("*"+id, "const " IDL_CORBA_NS "::Any&");
@@ -613,20 +613,20 @@
 
 	// skel return stuff
 	void getCSkelReturnDeclarator(string const &id,string &typespec,string &dcl,
-								  IDLTypedef const *activeTypedef = NULL) const {
+								  IDLTypedef const *activeTypedef ) const {
 		typespec = "CORBA_any";
 		dcl = "*"+id;
 	}
 	void writeCPPSkelReturnPrepCode(ostream &ostr,Indent &indent,bool passthru,
-									IDLTypedef const *activeTypedef = NULL) const {
+									IDLTypedef const *activeTypedef ) const {
 		ostr << indent << IDL_CORBA_NS "::Any *_retval = NULL;" << endl;
 	}
 	string getCPPSkelReturnAssignment(bool passthru,
-									  IDLTypedef const *activeTypedef = NULL) const {
+									  IDLTypedef const *activeTypedef ) const {
 		return "_retval = ";
 	}
 	void writeCPPSkelReturnMarshalCode(ostream &ostr,Indent &indent,bool passthru,
-									   IDLTypedef const *activeTypedef = NULL) const {
+									   IDLTypedef const *activeTypedef ) const {
 		ostr << indent << "return " 
 			<< idlGetCast( "_retval", "CORBA_any*") << ";" << endl;
 	}
@@ -712,7 +712,7 @@
 
 void
 IDLArray::getCPPMemberDeclarator(string const &id,string &typespec,string &dcl,
-							IDLTypedef const *activeTypedef = NULL) const {
+							IDLTypedef const *activeTypedef ) const {
 	if( activeTypedef ) {
 		typespec = activeTypedef->getQualifiedCPPIdentifier(activeTypedef->getRootScope());
 		dcl = id;
@@ -730,7 +730,7 @@
 void
 IDLArray::writeTypedef(ostream &ostr,Indent &indent,IDLCompilerState &state,
 					   IDLElement &dest,IDLScope const &scope,
-					   IDLTypedef const *activeTypedef = NULL) const {
+					   IDLTypedef const *activeTypedef ) const {
 
 	string typespec,dcl,str_static="";
 	m_elementType.getCPPMemberDeclarator("",typespec,dcl);
@@ -858,7 +858,7 @@
 
 void
 IDLArray::getCPPStructCtorDeclarator(string const &id,string &typespec,string &dcl,
-										IDLTypedef const *activeTypedef = NULL) const {
+										IDLTypedef const *activeTypedef ) const {
 	getCPPMemberDeclarator(id, typespec, dcl, activeTypedef);
 	typespec = "const " + typespec;
 	dcl = "_par_" + dcl;
@@ -866,7 +866,7 @@
 
 void
 IDLArray::writeCPPStructCtor(ostream &ostr,Indent &indent,string const &id,
-								IDLTypedef const *activeTypedef = NULL) const {
+								IDLTypedef const *activeTypedef ) const {
 	if(activeTypedef) {
 		ostr 
 		<< indent << activeTypedef->getQualifiedCPPIdentifier() << "_copy("
@@ -878,7 +878,7 @@
 
 void
 IDLArray::writeCPPStructPacker(ostream &ostr,Indent &indent,string const &id,
-								  IDLTypedef const *activeTypedef = NULL) const {
+								  IDLTypedef const *activeTypedef ) const {
 	if( activeTypedef ) {
 		ostr 
 		<< indent << activeTypedef->getQualifiedCPPIdentifier() << "_copy("
@@ -895,7 +895,7 @@
 
 void
 IDLArray::writeCPPStructUnpacker(ostream &ostr,Indent &indent,string const &id,
-									IDLTypedef const *activeTypedef = NULL) const {
+									IDLTypedef const *activeTypedef ) const {
 	if( activeTypedef ) {
 		ostr 
 		<< indent << activeTypedef->getQualifiedCPPIdentifier() << "_copy("
@@ -915,7 +915,7 @@
 
 void
 IDLArray::writeUnionModifiers(ostream &ostr,Indent &indent, string const &id, string const &discriminatorVal,
-									IDLTypedef const *activeTypedef = NULL) const{
+									IDLTypedef const *activeTypedef ) const{
 	string typespec,dcl;
 	getCPPStubDeclarator(IDL_PARAM_IN,"param",typespec,dcl,activeTypedef);
 	ostr
@@ -935,7 +935,7 @@
 
 void
 IDLArray::writeUnionAccessors(ostream &ostr,Indent &indent, string const &id, string const &discriminatorVal,
-									IDLTypedef const *activeTypedef = NULL) const{
+									IDLTypedef const *activeTypedef ) const{
 	string typespec,dcl;
 	g_assert(activeTypedef);
 	getCPPStubDeclarator(IDL_PARAM_IN,"",typespec,dcl,activeTypedef);
@@ -951,7 +951,7 @@
 
 void
 IDLArray::writeUnionReferents(ostream &ostr,Indent &indent, string const &id, string const &discriminatorVal,
-							IDLTypedef const *activeTypedef = NULL) const{
+							IDLTypedef const *activeTypedef ) const{
 	string typespec,dcl;
 	g_assert(activeTypedef);
 	getCPPStubDeclarator(IDL_PARAM_IN,"",typespec,dcl,activeTypedef);
@@ -969,7 +969,7 @@
 // stub stuff
 void
 IDLArray::getCPPStubDeclarator(IDL_param_attr attr,string const &id,string &typespec,string &dcl,
-							  IDLTypedef const *activeTypedef=NULL) const {
+							  IDLTypedef const *activeTypedef) const {
 	typespec = attr == IDL_PARAM_IN ? "const " : "";
 	typespec += activeTypedef ?
 		activeTypedef->getQualifiedCPPIdentifier() : getTypeName();
@@ -980,7 +980,7 @@
 
 void
 IDLArray::getCSkelDeclarator(IDL_param_attr attr,string const &id,string &typespec,string &dcl,
-							IDLTypedef const *activeTypedef = NULL) const {
+							IDLTypedef const *activeTypedef ) const {
 	g_assert(activeTypedef);
 	typespec = attr == IDL_PARAM_IN ? "const " : "";
 	typespec += activeTypedef->getNSScopedCTypeName();
@@ -993,7 +993,7 @@
 
 void
 IDLArray::getCPPStubReturnDeclarator(string const &id,string &typespec,string &dcl,
-									 IDLTypedef const *activeTypedef = NULL) const {
+									 IDLTypedef const *activeTypedef ) const {
 	g_assert(activeTypedef);
 	typespec = activeTypedef->getQualifiedCPPIdentifier() + "_slice";
 	dcl = "*" + id;
@@ -1001,7 +1001,7 @@
 
 void
 IDLArray::getCSkelReturnDeclarator(string const &id,string &typespec,string &dcl,
-								  IDLTypedef const *activeTypedef = NULL) const {
+								  IDLTypedef const *activeTypedef ) const {
 	g_assert(activeTypedef);
 	typespec = activeTypedef->getNSScopedCTypeName() + "_slice";
 	dcl = "*" + id;
@@ -1010,7 +1010,7 @@
 
 string
 IDLArray::getCPPStubParameterTerm(IDL_param_attr attr,string const &id,
-								   IDLTypedef const *activeTypedef = NULL) const {
+								   IDLTypedef const *activeTypedef ) const {
 	string typespec,dcl;
 	getCSkelDeclarator(attr,"",typespec,dcl,activeTypedef);
 	
@@ -1026,7 +1026,7 @@
 
 string
 IDLArray::getCPPSkelParameterTerm(IDL_param_attr attr,string const &id,
-								   IDLTypedef const *activeTypedef = NULL) const {
+								   IDLTypedef const *activeTypedef ) const {
 	string typespec,dcl;
 	getCPPStubDeclarator(attr,"",typespec,dcl,activeTypedef);
 	string term;
@@ -1088,7 +1088,7 @@
 void 
 IDLInterface::writeTypedef(ostream &ostr,Indent &indent,IDLCompilerState &state,
 						   IDLElement &dest,IDLScope const &scope,
-						   IDLTypedef const *activeTypedef = NULL) const {
+						   IDLTypedef const *activeTypedef ) const {
 	string id = dest.getCPPIdentifier();
 	ostr
 	<< indent << "typedef " << getCPPIdentifier() << ' ' << id << ';' << endl
@@ -1124,7 +1124,7 @@
 
 void 
 IDLInterface::writeCPPStructPacker(ostream &ostr,Indent &indent,string const &id,
-								      IDLTypedef const *activeTypedef = NULL) const {
+								      IDLTypedef const *activeTypedef ) const {
 	ostr
 	<< indent << IDL_IMPL_NS "::release_guarded(_cstruct." << id << ");" << endl
 	<< indent << "_cstruct." << id << " = "
@@ -1136,7 +1136,7 @@
 
 void 
 IDLInterface::writeCPPStructUnpacker(ostream &ostr,Indent &indent,string const &id,
-									    IDLTypedef const *activeTypedef = NULL) const {
+									    IDLTypedef const *activeTypedef ) const {
 	ostr
 	<< id << " = " 
 	<< getQualifiedCPPCast(IDL_IMPL_NS "::duplicate_guarded(_cstruct."+id+")")
@@ -1148,7 +1148,7 @@
 
 void 
 IDLInterface::getCPPStubDeclarator(IDL_param_attr attr,string const &id,string &typespec,string &dcl,
-								   IDLTypedef const *activeTypedef=NULL) const {
+								   IDLTypedef const *activeTypedef) const {
 	dcl = id;
 
 	switch (attr) {
@@ -1169,7 +1169,7 @@
 
 string 
 IDLInterface::getCPPStubParameterTerm(IDL_param_attr attr,string const &id,
-									  IDLTypedef const *activeTypedef = NULL) const {
+									  IDLTypedef const *activeTypedef ) const {
 	string ctype = getNSScopedCTypeName();
 
 	switch (attr) {
@@ -1186,7 +1186,7 @@
 
 void
 IDLInterface::writeCPPStubReturnDemarshalCode(ostream &ostr,Indent &indent,
-											  IDLTypedef const *activeTypedef = NULL) const {
+											  IDLTypedef const *activeTypedef ) const {
 	// must return stub ptr and not ptr in order to work when smart pointers are used
 	ostr
 		<< indent << "return reinterpret_cast< " << getQualifiedCPPStub() << " *>(_retval);" << endl;
@@ -1196,7 +1196,7 @@
 
 void 
 IDLInterface::getCSkelDeclarator(IDL_param_attr attr,string const &id,string &typespec,string &dcl,
-								 IDLTypedef const *activeTypedef = NULL) const {
+								 IDLTypedef const *activeTypedef ) const {
 	typespec = getNSScopedCTypeName();
 
 	switch (attr) {
@@ -1217,7 +1217,7 @@
 
 void 
 IDLInterface::writeCPPSkelDemarshalCode(IDL_param_attr attr,string const &id,ostream &ostr,Indent &indent,
-										IDLTypedef const *activeTypedef = NULL) const {
+										IDLTypedef const *activeTypedef ) const {
 	switch (attr) {
 	case IDL_PARAM_IN:
 		ostr
@@ -1245,7 +1245,7 @@
 
 void 
 IDLInterface::writeCPPSkelMarshalCode(IDL_param_attr attr,string const &id,ostream &ostr,Indent &indent,
-									  IDLTypedef const *activeTypedef = NULL) const {
+									  IDLTypedef const *activeTypedef ) const {
 	string ptrname = " _" + id + "_ptr";
 	switch (attr) {
 	case IDL_PARAM_INOUT:
@@ -1260,7 +1260,7 @@
 
 void
 IDLInterface::writeCPPSkelReturnMarshalCode(ostream &ostr,Indent &indent,bool passthru,
-									   IDLTypedef const *activeTypedef = NULL) const {
+									   IDLTypedef const *activeTypedef ) const {
 	if (passthru)
 		ostr << indent << "return _retval;" << endl;
 	else {
@@ -1364,7 +1364,7 @@
 		return "CORBA::Object";
 	}
 	
-	virtual string getQualifiedCPPStub(IDLScope const *up_to = NULL) const {
+	virtual string getQualifiedCPPStub(IDLScope const *up_to ) const {
 		// fixme - doesn't do the scope thing
 		return "CORBA::Object";
 	}
@@ -1383,16 +1383,16 @@
 		return "CORBA::Object_out";
 	}
 
-	virtual string getQualifiedCPP_ptr(IDLScope const *up_to = NULL) const {
+	virtual string getQualifiedCPP_ptr(IDLScope const *up_to ) const {
 		return "CORBA::Object_ptr";
 	}
-	virtual string getQualifiedCPP_var(IDLScope const *up_to = NULL) const {
+	virtual string getQualifiedCPP_var(IDLScope const *up_to ) const {
 		return "CORBA::Object_var";
 	}
-	virtual string getQualifiedCPP_mgr(IDLScope const *up_to = NULL) const {
+	virtual string getQualifiedCPP_mgr(IDLScope const *up_to ) const {
 		return "CORBA::Object_mgr";
 	}
-	virtual string getQualifiedCPP_out(IDLScope const *up_to = NULL) const {
+	virtual string getQualifiedCPP_out(IDLScope const *up_to ) const {
 		return "CORBA::Object_out";
 	}
 
@@ -1431,7 +1431,7 @@
 		return "CORBA::TypeCode";
 	}
 	
-	virtual string getQualifiedCPPStub(IDLScope const *up_to = NULL) const {
+	virtual string getQualifiedCPPStub(IDLScope const *up_to ) const {
 		// fixme - doesn't do the scope thing
 		return "CORBA::TypeCode";
 	}
@@ -1450,22 +1450,22 @@
 		return "CORBA::TypeCode_out";
 	}
 
-	virtual string getQualifiedCPP_ptr(IDLScope const *up_to = NULL) const {
+	virtual string getQualifiedCPP_ptr(IDLScope const *up_to ) const {
 		return "CORBA::TypeCode_ptr";
 	}
-	virtual string getQualifiedCPP_var(IDLScope const *up_to = NULL) const {
+	virtual string getQualifiedCPP_var(IDLScope const *up_to ) const {
 		return "CORBA::TypeCode_var";
 	}
-	virtual string getQualifiedCPP_mgr(IDLScope const *up_to = NULL) const {
+	virtual string getQualifiedCPP_mgr(IDLScope const *up_to ) const {
 		return "CORBA::TypeCode_mgr";
 	}
-	virtual string getQualifiedCPP_out(IDLScope const *up_to = NULL) const {
+	virtual string getQualifiedCPP_out(IDLScope const *up_to ) const {
 		return "CORBA::TypeCode_out";
 	}
 
 	void
 	writeCPPSkelReturnMarshalCode(ostream &ostr,Indent &indent,bool passthru,
-								  IDLTypedef const *activeTypedef = NULL) const {
+								  IDLTypedef const *activeTypedef ) const {
 		ostr << indent << "return reinterpret_cast< " << getNSScopedCTypeName() << ">(_retval);" << endl;		
 	}
 
@@ -1517,7 +1517,7 @@
 
 void
 IDLStruct::getCPPMemberDeclarator(string const &id,string &typespec,string &dcl,
-								  IDLTypedef const *activeTypedef = NULL) const {
+								  IDLTypedef const *activeTypedef ) const {
 	typespec = getQualifiedCPPIdentifier(getRootScope());
 	dcl = id;
 };
@@ -1525,7 +1525,7 @@
 void
 IDLStruct::writeTypedef(ostream &ostr,Indent &indent,IDLCompilerState &state,
 						IDLElement &dest,IDLScope const &scope,
-						IDLTypedef const *activeTypedef = NULL) const {
+						IDLTypedef const *activeTypedef ) const {
 	ostr
 	<< indent << "typedef " << getQualifiedCPPIdentifier()
 	<< " " << dest.getCPPIdentifier() << ";" << endl;
@@ -1544,32 +1544,32 @@
 
 void
 IDLStruct::getCPPStructCtorDeclarator(string const &id,string &typespec,string &dcl,
-									  IDLTypedef const *activeTypedef = NULL) const {
+									  IDLTypedef const *activeTypedef ) const {
 	ORBITCPP_NYI("struct getCPPStructCtorDeclarator");
 }
 
 void
 IDLStruct::writeCPPStructCtor(ostream &ostr,Indent &indent,string const &id,
-							  IDLTypedef const *activeTypedef = NULL) const {
+							  IDLTypedef const *activeTypedef ) const {
 	ORBITCPP_NYI("struct writeCPPStructCtor");
 }
 
 void
 IDLStruct::writeCPPStructPacker(ostream &ostr,Indent &indent,string const &id,
-								IDLTypedef const *activeTypedef = NULL) const {
+								IDLTypedef const *activeTypedef ) const {
 	ORBITCPP_NYI("struct writeCPPStructPacker");
 }
 
 void
 IDLStruct::writeCPPStructUnpacker(ostream &ostr,Indent &indent,string const &id,
-								  IDLTypedef const *activeTypedef = NULL) const {
+								  IDLTypedef const *activeTypedef ) const {
 	ORBITCPP_NYI("struct writeCPPStructUnpacker");
 }
 
 
 void
 IDLStruct::writeUnionReferents(ostream &ostr,Indent &indent, string const &id, string const &discriminatorVal,
-							IDLTypedef const *activeTypedef = NULL) const{
+							IDLTypedef const *activeTypedef ) const{
 	ostr
 	<< indent << getQualifiedCPPIdentifier() << " &" << id << "() {" << endl;
 	ostr	
@@ -1581,7 +1581,7 @@
 
 
 void IDLStruct::getCPPStubDeclarator(IDL_param_attr attr,string const &id,string &typespec,string &dcl,
-									 IDLTypedef const *activeTypedef=NULL) const {
+									 IDLTypedef const *activeTypedef) const {
 	dcl = id;
 
 	string name = activeTypedef ?
@@ -1603,7 +1603,7 @@
 
 string 
 IDLStruct::getCPPStubParameterTerm(IDL_param_attr attr,string const &id,
-								   IDLTypedef const *activeTypedef = NULL) const {
+								   IDLTypedef const *activeTypedef ) const {
 
 	string typespec,dcl;
 	getCSkelDeclarator(attr,"",typespec,dcl,activeTypedef);
@@ -1623,7 +1623,7 @@
 
 void
 IDLStruct::getCPPStubReturnDeclarator(string const &id,string &typespec,string &dcl,
-									  IDLTypedef const *activeTypedef = NULL) const {
+									  IDLTypedef const *activeTypedef ) const {
 	typespec = getQualifiedCPPIdentifier();
 	if(isVariableLength())
 		dcl = "*" + id;
@@ -1633,7 +1633,7 @@
 
 void
 IDLStruct::writeCPPStubReturnPrepCode(ostream &ostr,Indent &indent,
-									  IDLTypedef const *activeTypedef = NULL) const {
+									  IDLTypedef const *activeTypedef ) const {
 
 	ostr
 	<< indent << getNSScopedCTypeName();
@@ -1651,7 +1651,7 @@
 
 void
 IDLStruct::writeCPPStubReturnDemarshalCode(ostream &ostr,Indent &indent,
-										   IDLTypedef const *activeTypedef = NULL) const {
+										   IDLTypedef const *activeTypedef ) const {
 	ostr << indent << "return reinterpret_cast< " << getQualifiedCPPIdentifier();
 	if(isVariableLength())
 		ostr << "*";
@@ -1663,7 +1663,7 @@
 
 void 
 IDLStruct::getCSkelDeclarator(IDL_param_attr attr,string const &id,string &typespec,string &dcl,
-							  IDLTypedef const *activeTypedef = NULL) const {
+							  IDLTypedef const *activeTypedef ) const {
 	typespec = getNSScopedCTypeName();
 	
 	switch (attr) {
@@ -1688,7 +1688,7 @@
 
 void 
 IDLStruct::writeCPPSkelDemarshalCode(IDL_param_attr attr,string const &id,ostream &ostr,Indent &indent,
-									 IDLTypedef const *activeTypedef = NULL) const {
+									 IDLTypedef const *activeTypedef ) const {
 	// no demarshalling code required
 }
 
@@ -1697,7 +1697,7 @@
 
 string
 IDLStruct::getCPPSkelParameterTerm(IDL_param_attr attr,string const &id,
-								   IDLTypedef const *activeTypedef = NULL) const {
+								   IDLTypedef const *activeTypedef ) const {
 	string typespec,dcl;
 	getCPPStubDeclarator(attr,"",typespec,dcl);
 
@@ -1718,14 +1718,14 @@
 
 void 
 IDLStruct::writeCPPSkelMarshalCode(IDL_param_attr attr,string const &id,ostream &ostr,Indent &indent,
-								   IDLTypedef const *activeTypedef = NULL) const {
+								   IDLTypedef const *activeTypedef ) const {
 	// no marshalling code required
 }
 
 
 void
 IDLStruct::getCSkelReturnDeclarator(string const &id,string &typespec,string &dcl,
-									IDLTypedef const *activeTypedef = NULL) const {
+									IDLTypedef const *activeTypedef ) const {
 	typespec = getNSScopedCTypeName();
 	if (isVariableLength())
 		dcl = "*" + id;
@@ -1735,7 +1735,7 @@
 
 void
 IDLStruct::writeCPPSkelReturnPrepCode(ostream &ostr,Indent &indent,bool passthru,
-									  IDLTypedef const *activeTypedef = NULL) const {
+									  IDLTypedef const *activeTypedef ) const {
 	ostr << indent << getQualifiedCPPIdentifier();
 	if (isVariableLength())
 		ostr << " *_retval = NULL;" << endl;
@@ -1745,13 +1745,13 @@
 
 string
 IDLStruct::getCPPSkelReturnAssignment(bool passthru,
-									  IDLTypedef const *activeTypedef = NULL) const {
+									  IDLTypedef const *activeTypedef ) const {
 	return "_retval = ";		
 }
 
 void
 IDLStruct::writeCPPSkelReturnMarshalCode(ostream &ostr,Indent &indent,bool passthru,
-										 IDLTypedef const *activeTypedef = NULL) const {
+										 IDLTypedef const *activeTypedef ) const {
 	ostr << indent << "return reinterpret_cast< "
 	<< getNSScopedCTypeName();
 
@@ -1824,7 +1824,7 @@
 
 void
 IDLSequence::getCPPMemberDeclarator(string const &id,string &typespec,string &dcl,
-									IDLTypedef const *activeTypedef = NULL) const {
+									IDLTypedef const *activeTypedef ) const {
 	if(activeTypedef)
 		typespec = activeTypedef->getQualifiedCPPIdentifier(activeTypedef->getRootScope());
 	else
@@ -1869,7 +1869,7 @@
 void
 IDLSequence::writeTypedef(ostream &ostr,Indent &indent,IDLCompilerState &state,
 						  IDLElement &dest,IDLScope const &scope,
-						  IDLTypedef const *activeTypedef = NULL) const {
+						  IDLTypedef const *activeTypedef ) const {
 	if (activeTypedef == NULL) { // if this isn't a typedef of a typedef...
 		string id = getCPPType();
 		ostr
@@ -1954,7 +1954,7 @@
 
 void
 IDLSequence::getCPPStructCtorDeclarator(string const &id,string &typespec,string &dcl,
-										IDLTypedef const *activeTypedef = NULL) const {
+										IDLTypedef const *activeTypedef ) const {
 	getCPPMemberDeclarator(id, typespec, dcl, activeTypedef);
 	typespec = "const " + typespec;
 	dcl = "&_par_" + dcl;
@@ -1962,13 +1962,13 @@
 
 void
 IDLSequence::writeCPPStructCtor(ostream &ostr,Indent &indent,string const &id,
-								IDLTypedef const *activeTypedef = NULL) const {
+								IDLTypedef const *activeTypedef ) const {
 	ostr << indent << id << " = _par_" << id << ';' << endl;
 }
 
 void
 IDLSequence::writeCPPStructPacker(ostream &ostr,Indent &indent,string const &id,
-								  IDLTypedef const *activeTypedef = NULL) const {
+								  IDLTypedef const *activeTypedef ) const {
 	string type;
 	if( activeTypedef )
 		type = activeTypedef->getQualifiedCPPIdentifier();
@@ -1982,7 +1982,7 @@
 
 void
 IDLSequence::writeCPPStructUnpacker(ostream &ostr,Indent &indent,string const &id,
-									IDLTypedef const *activeTypedef = NULL) const {
+									IDLTypedef const *activeTypedef ) const {
 	string type;
 	if( activeTypedef )
 		type = activeTypedef->getQualifiedCPPIdentifier();
@@ -2000,7 +2000,7 @@
 
 void
 IDLSequence::writeUnionReferents(ostream &ostr,Indent &indent, string const &id, string const &discriminatorVal,
-							IDLTypedef const *activeTypedef = NULL) const{
+							IDLTypedef const *activeTypedef ) const{
 
 	g_assert(activeTypedef);      //activeTypedef cannot be null for sequences
 	ostr
@@ -2014,7 +2014,7 @@
 
 
 void IDLSequence::getCPPStubDeclarator(IDL_param_attr attr,string const &id,string &typespec,string &dcl,
-									   IDLTypedef const* activeTypedef=NULL) const {
+									   IDLTypedef const* activeTypedef) const {
 	dcl = id;
 
 	g_assert(activeTypedef);      //activeTypedef cannot be null for sequences
@@ -2036,7 +2036,7 @@
 
 string 
 IDLSequence::getCPPStubParameterTerm(IDL_param_attr attr,string const &id,
-									 IDLTypedef const *activeTypedef = NULL) const {
+									 IDLTypedef const *activeTypedef ) const {
 
 	string typespec,dcl, retval;
 	getCSkelDeclarator(attr,"",typespec,dcl,activeTypedef);
@@ -2057,7 +2057,7 @@
 
 void
 IDLSequence::getCPPStubReturnDeclarator(string const &id,string &typespec,string &dcl,
-IDLTypedef const *activeTypedef = NULL) const {
+IDLTypedef const *activeTypedef ) const {
 	typespec = activeTypedef->getQualifiedCPPIdentifier();
 	if (isVariableLength())
 		dcl = "*" + id;
@@ -2067,7 +2067,7 @@
 
 void
 IDLSequence::writeCPPStubReturnPrepCode(ostream &ostr,Indent &indent,
-IDLTypedef const *activeTypedef = NULL) const {
+IDLTypedef const *activeTypedef ) const {
 
 	ostr
 	<< indent << activeTypedef->getNSScopedCTypeName();
@@ -2085,7 +2085,7 @@
 
 void
 IDLSequence::writeCPPStubReturnDemarshalCode(ostream &ostr,Indent &indent,
-											 IDLTypedef const *activeTypedef = NULL) const {
+											 IDLTypedef const *activeTypedef ) const {
 	ostr << indent << "return reinterpret_cast< " << activeTypedef->getQualifiedCPPIdentifier();
 	if(isVariableLength())
 		ostr << "*";
@@ -2097,7 +2097,7 @@
 
 void 
 IDLSequence::getCSkelDeclarator(IDL_param_attr attr,string const &id,string &typespec,string &dcl,
-								IDLTypedef const *activeTypedef = NULL) const {
+								IDLTypedef const *activeTypedef ) const {
 	typespec = activeTypedef->getNSScopedCTypeName();
 
 	switch (attr) {
@@ -2119,13 +2119,13 @@
 
 void 
 IDLSequence::writeCPPSkelDemarshalCode(IDL_param_attr attr,string const &id,ostream &ostr,Indent &indent,
-									   IDLTypedef const *activeTypedef = NULL) const {
+									   IDLTypedef const *activeTypedef ) const {
 	// no demarshalling code required
 }
 
 string
 IDLSequence::getCPPSkelParameterTerm(IDL_param_attr attr,string const &id,
-									 IDLTypedef const *activeTypedef = NULL) const {
+									 IDLTypedef const *activeTypedef ) const {
 	string typespec,dcl;
 	getCPPStubDeclarator(attr,"",typespec,dcl,activeTypedef);
 
@@ -2146,21 +2146,21 @@
 
 void 
 IDLSequence::writeCPPSkelMarshalCode(IDL_param_attr attr,string const &id,ostream &ostr,Indent &indent,
-									 IDLTypedef const *activeTypedef = NULL) const {
+									 IDLTypedef const *activeTypedef ) const {
 	// no marshalling code required
 }
 
 
 void
 IDLSequence::getCSkelReturnDeclarator(string const &id,string &typespec,string &dcl,
-									  IDLTypedef const *activeTypedef = NULL) const {
+									  IDLTypedef const *activeTypedef ) const {
 	typespec = activeTypedef->getNSScopedCTypeName();
 	dcl = "*" + id;
 }
 
 void
 IDLSequence::writeCPPSkelReturnPrepCode(ostream &ostr,Indent &indent,bool passthru,
-										IDLTypedef const *activeTypedef = NULL) const {
+										IDLTypedef const *activeTypedef ) const {
 	ostr << indent << activeTypedef->getQualifiedCPPIdentifier();
 	if(isVariableLength())
 		ostr << " *_retval = NULL;" << endl;
@@ -2170,13 +2170,13 @@
 
 string
 IDLSequence::getCPPSkelReturnAssignment(bool passthru,
-										IDLTypedef const *activeTypedef = NULL) const {
+										IDLTypedef const *activeTypedef ) const {
 	return "_retval = ";		
 }
 
 void
 IDLSequence::writeCPPSkelReturnMarshalCode(ostream &ostr,Indent &indent,bool passthru,
-										   IDLTypedef const *activeTypedef = NULL) const {
+										   IDLTypedef const *activeTypedef ) const {
 	ostr << indent << "return reinterpret_cast< "
 	<< activeTypedef->getNSScopedCTypeName()
 	<< "*>(_retval);" << endl;
@@ -2208,7 +2208,7 @@
 
 // IDLUnion -------------------------------------------------------------
 IDLUnion::IDLUnion(string const &id,IDL_tree node,
-				   IDLType const &discriminatorType, IDLScope *parentscope = NULL)
+				   IDLType const &discriminatorType, IDLScope *parentscope)
 	: IDLStruct(id,node,parentscope),m_discriminatorType(discriminatorType) {
 }
