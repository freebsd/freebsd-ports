--- scripting/source/protocolhandler/scripthandler.cxx.orig	2019-08-20 18:18:17 UTC
+++ scripting/source/protocolhandler/scripthandler.cxx
@@ -41,6 +41,7 @@
 #include <com/sun/star/script/provider/XScriptProviderFactory.hpp>
 #include <com/sun/star/script/provider/ScriptFrameworkErrorType.hpp>
 
+#include <cstdio>
 #include <rtl/uri.hxx>
 #include <sfx2/objsh.hxx>
 #include <sfx2/frame.hxx>
