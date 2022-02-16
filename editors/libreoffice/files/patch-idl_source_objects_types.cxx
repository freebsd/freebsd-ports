--- idl/source/objects/types.cxx.orig	2022-01-26 14:35:29 UTC
+++ idl/source/objects/types.cxx
@@ -251,7 +251,7 @@ void SvMetaType::WriteSfxItem(
 
     // write the implementation part
     rOutStm.WriteCharPtr( "#ifdef SFX_TYPEMAP" ) << endl;
-    rOutStm.WriteCharPtr( "#if !defined(_WIN32) && (defined(DISABLE_DYNLOADING) && (defined(ANDROID) || defined(IOS) || defined(EMSCRIPTEN) || defined(LINUX)))" ) << endl;
+    rOutStm.WriteCharPtr( "#if !defined(_WIN32) && (defined(DISABLE_DYNLOADING) && (defined(ANDROID) || defined(IOS) || defined(EMSCRIPTEN) || defined(LINUX) || defined(FREEBSD)))" ) << endl;
     rOutStm.WriteCharPtr( "__attribute__((__weak__))" ) << endl;
     rOutStm.WriteCharPtr( "#endif" ) << endl;
     rOutStm.WriteOString( aTypeName ).WriteOString( aVarName )
