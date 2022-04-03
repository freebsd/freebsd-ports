--- src/CommonUtility/utils/ESAnyCastUtils.h.orig	2021-11-25 00:56:55 UTC
+++ src/CommonUtility/utils/ESAnyCastUtils.h
@@ -141,7 +141,11 @@ const T* SafeAnyDataCPtr( const ESAny& anyIn )
 template< typename T >
 T* SafeAnyDataPtr_WithLog( ESAny& anyIn, ES_CHAR_CPTR lpszFile = __ES_FILE__, const int nLine = __LINE__ )
 {
- if( anyIn.empty() || (anyIn.type() != typeid(T)) ){
+ // XXX changed to a string comparison of the type name here because, on FreeBSD, the hash_code()s for anyIn.type() and typeid(T) are differing for T = ESDictionary
+ //	even though the names of the types are the same!
+ //	It should work as it was.  It is not efficient now.  Why are the type hash_code()s different on FreeBSD??
+ // was: if( anyIn.empty() || (anyIn.type() != typeid(T)) ){
+ if( anyIn.empty() || ES_CMN_FUNCS::STRING::ToESString(anyIn.type().name()).compare(ES_CMN_FUNCS::STRING::ToESString(typeid(T).name())) != 0 ){
   if(anyIn.empty()){
    ES_Warning_Log3( __ES_FUNCTION__, lpszFile, nLine, ES_STRING("Boost Any Cast Warning Empty!!"));
   } else {
@@ -167,7 +171,11 @@ T* SafeAnyDataPtr_WithLog( ESAny& anyIn, ES_CHAR_CPTR 
 template< typename T >
 const T* SafeAnyDataCPtr_WithLog( const ESAny& anyIn, ES_CHAR_CPTR lpszFile = __ES_FILE__, const int nLine = __LINE__ )
 {
- if( anyIn.empty() || (anyIn.type() != typeid(T)) ){
+ // XXX changed to a string comparison of the type name here because, on FreeBSD, the hash_code()s for anyIn.type() and typeid(T) are differing for T = ESDictionary
+ //	even though the names of the types are the same!
+ //	It should work as it was.  It is not efficient now.  Why are the type hash_code()s different on FreeBSD??
+ // was: if( anyIn.empty() || (anyIn.type() != typeid(T)) ){
+ if( anyIn.empty() || ES_CMN_FUNCS::STRING::ToESString(anyIn.type().name()).compare(ES_CMN_FUNCS::STRING::ToESString(typeid(T).name())) != 0 ){
   if(anyIn.empty()){
    ES_Warning_Log3( __ES_FUNCTION__, lpszFile, nLine, ES_STRING("Boost Any Cast Warning Empty!!"));
   } else {
