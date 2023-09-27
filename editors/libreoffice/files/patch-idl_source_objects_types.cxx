--- idl/source/objects/types.cxx.orig	2023-05-11 20:19:01 UTC
+++ idl/source/objects/types.cxx
@@ -249,7 +249,7 @@ void SvMetaType::WriteSfxItem(
 
     // write the implementation part
     rOutStm.WriteOString( "#ifdef SFX_TYPEMAP" ) << endl;
-    rOutStm.WriteOString( "#if !defined(_WIN32) && (defined(DISABLE_DYNLOADING) && (defined(ANDROID) || defined(IOS) || defined(EMSCRIPTEN) || defined(LINUX)))" ) << endl;
+    rOutStm.WriteOString( "#if !defined(_WIN32) && (defined(DISABLE_DYNLOADING) && (defined(ANDROID) || defined(IOS) || defined(EMSCRIPTEN) || defined(LINUX) || defined(FREEBSD)))" ) << endl;
     rOutStm.WriteOString( "__attribute__((__weak__))" ) << endl;
     rOutStm.WriteOString( "#endif" ) << endl;
     rOutStm.WriteOString( aTypeName ).WriteOString( aVarName )
