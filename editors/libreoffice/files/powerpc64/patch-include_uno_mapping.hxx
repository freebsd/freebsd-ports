--- include/uno/mapping.hxx.orig	2020-11-28 00:12:11 UTC
+++ include/uno/mapping.hxx
@@ -248,6 +248,7 @@ inline Mapping::Mapping( const Mapping & rMapping )
         (*_pMapping->acquire)( _pMapping );
 }
 
+__attribute__ ((optnone))
 inline Mapping::~Mapping()
 {
     if (_pMapping)
