--- ui/as/asbind.h.orig	2012-07-21 13:38:20.000000000 +0400
+++ ui/as/asbind.h	2014-02-06 06:32:49.000000000 +0400
@@ -268,7 +268,7 @@
 	}
 
 	// throw ?
-	template<typename T> const char * typestr() { ctassert<false>(); return "ERROR"; }
+	template<typename T> const char * typestr();
 
 	template<> inline const char *typestr<signed int>() { return "int"; }
 	template<> inline const char *typestr<unsigned int>() { return "uint"; }
@@ -436,13 +436,7 @@
 // function string
 
 template<typename R>
-struct FunctionStringProxy {
-	std::string operator()( const char *s )
-	{
-		ctassert<false>();
-		throw Exception( std::string("FunctionStringProxy base called with " ) + s );
-	}
-};
+struct FunctionStringProxy;
 
 template<typename R>
 struct FunctionStringProxy<R (*)()> {
@@ -539,13 +533,7 @@
 
 // method string
 
-template<typename T> struct MethodStringProxy {
-	std::string operator()( const char *s  )
-	{
-		ctassert<false>();
-		throw Exception( std::string( "MethodStringProxy: base class called in " ) + s );
-	}
-};
+template<typename T> struct MethodStringProxy;
 
 //==
 
@@ -902,17 +890,8 @@
 // functor object to call script-function
 
 // first define structs to get/set arguments (struct to partial-specialize)
-template<typename T> struct SetArg {
-	void operator()( asIScriptContext *ctx, int idx, T &t ) {
-		ctassert<false>();
-	}
-};
-template<typename T> struct GetArg {
-	T operator()() {
-		ctassert<false>();
-		return T();
-	}
-};
+template<typename T> struct SetArg;
+template<typename T> struct GetArg;
 
 template<> struct SetArg<signed int> {
 	void operator()( asIScriptContext *ctx, int idx, signed int &t ) { ctx->SetArgDWord( idx, t ); }
@@ -1042,15 +1021,7 @@
 //=================
 
 template<typename R>
-struct FunctionPtr : FunctionPtrBase {
-	FunctionPtr( asIScriptFunction *fptr=NULL ) : FunctionPtrBase( fptr ) {}
-	R operator()( void )
-	{
-		ctassert<false>();
-		throw std::runtime_error( "FunctionPtr baseclass called!" );
-		return R();
-	}
-};
+struct FunctionPtr;
 
 //==
 
