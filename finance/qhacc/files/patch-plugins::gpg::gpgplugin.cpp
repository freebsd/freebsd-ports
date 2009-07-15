--- ./plugins/gpg/gpgplugin.cpp.orig	2009-06-30 00:55:33.000000000 -0400
+++ ./plugins/gpg/gpgplugin.cpp	2009-06-30 00:59:33.000000000 -0400
@@ -56,6 +56,7 @@
 const PluginInfo& GPGDBPlugin::info() const { return pinfo; }
 
 bool GPGDBPlugin::iconnect( QHacc *, const QString&, QString& error ){
+	gpgme_check_version( NULL );
 	madectx=( GPG_ERR_NO_ERROR==gpgme_new( &gpgctx ) );
 	if( madectx ){
 		gpgme_set_passphrase_cb( gpgctx, GPGDBPlugin::passphrase_cb, 
