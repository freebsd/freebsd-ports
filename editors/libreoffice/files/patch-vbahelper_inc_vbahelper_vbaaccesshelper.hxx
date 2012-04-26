--- vbahelper/inc/vbahelper/vbaaccesshelper.hxx.orig	2012-04-26 10:20:44.869218717 +0200
+++ vbahelper/inc/vbahelper/vbaaccesshelper.hxx	2012-04-26 14:53:44.559610302 +0200
@@ -51,7 +51,7 @@
             return xVBAFactory;
         }
 
-        VBAHELPER_DLLPRIVATE inline css::uno::Reference< css::uno::XInterface > createVBAUnoAPIServiceWithArgs( SfxObjectShell* pShell,  const sal_Char* _pAsciiName, const css::uno::Sequence< css::uno::Any >& aArgs ) throw (css::uno::RuntimeException)
+        VBAHELPER_DLLPRIVATE inline css::uno::Reference< css::uno::XInterface > createVBAUnoAPIServiceWithArgs( SfxObjectShell* pShell,  const sal_Char* _pAsciiName, const css::uno::Sequence< css::uno::Any >& aArgs ) throw (css::uno::Exception)
         {
             OSL_PRECOND( pShell, "createVBAUnoAPIService: no shell!" );
             ::rtl::OUString sVarName( ::rtl::OUString::createFromAscii( _pAsciiName ) );
