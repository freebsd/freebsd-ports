--- ./vcl/unx/generic/app/wmadaptor.cxx.orig	2012-03-27 18:22:01.000000000 +0200
+++ ./vcl/unx/generic/app/wmadaptor.cxx	2012-04-16 14:24:48.000000000 +0200
@@ -2404,7 +2404,7 @@
 void WMAdaptor::setClientMachine( X11SalFrame* i_pFrame ) const
 {
     rtl::OString aWmClient( rtl::OUStringToOString( GetGenericData()->GetHostname(), RTL_TEXTENCODING_ASCII_US ) );
-    XTextProperty aClientProp = { (unsigned char*)aWmClient.getStr(), XA_STRING, 8, aWmClient.getLength() };
+    XTextProperty aClientProp = { (unsigned char*)aWmClient.getStr(), XA_STRING, 8, static_cast<unsigned long>(aWmClient.getLength()) };
     XSetWMClientMachine( m_pDisplay, i_pFrame->GetShellWindow(), &aClientProp );
 }
 
