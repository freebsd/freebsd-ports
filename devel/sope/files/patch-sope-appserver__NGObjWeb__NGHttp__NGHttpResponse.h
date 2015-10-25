--- sope-appserver/NGObjWeb/NGHttp/NGHttpResponse.h.orig	2015-09-16 18:26:49 UTC
+++ sope-appserver/NGObjWeb/NGHttp/NGHttpResponse.h
@@ -122,7 +122,7 @@ static inline BOOL NGIsClientErrorHttpSt
   return ((_code >= 400) && (_code < 500)) ? YES : NO;
 }
 static inline BOOL NGIsServerErrorHttpStatusCode(NGHttpStatusCode _code) {
-  return ((_code >= 500) && (_code < 600)) ? YES : NO;
+  return ((_code >= 500) && ((int)_code < 600)) ? YES : NO;
 }
 
 #endif /* __NGHttp_NGHttpResponse_H__ */
