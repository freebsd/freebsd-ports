--- src/webapp.cpp.orig	2016-03-05 06:10:45 UTC
+++ src/webapp.cpp
@@ -31,6 +31,13 @@ Foundation, Inc., 59 Temple Place, Suite
 #include <wx/sstream.h>
 #include <wx/protocol/http.h>
 
+#ifdef _LIBCPP_VERSION
+#define TO_WSTRING(x) std::to_wstring(x)
+#else
+#include <boost/lexical_cast.hpp>
+#define TO_WSTRING(x) boost::lexical_cast<std::wstring>(x)
+#endif
+
 //Expected WebAppVersion
 const wxString WebAppParam::ApiExpectedVersion = "1.0.1";
 
@@ -374,7 +381,7 @@ bool mmWebApp::WebApp_DownloadNewTransac
 
         for (int i = 0; i < static_cast<int>(jsonTransaction.Size()); i++)
         {
-            TrProgrStr = std::to_wstring(i);
+            TrProgrStr = TO_WSTRING(i);
             
             WebTran.ID = wxAtoi(wxString(json::String(jsonTransaction[TrProgrStr][L"ID"])));
             
