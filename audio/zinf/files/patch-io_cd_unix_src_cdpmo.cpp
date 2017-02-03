--- io/cd/unix/src/cdpmo.cpp.orig	2003-09-16 17:34:59 UTC
+++ io/cd/unix/src/cdpmo.cpp
@@ -113,7 +113,7 @@ Error CDPMO::SetTo(const char *url)
    if (IsError(Init(&blah))) 
        return kError_CDInitFailed;
 
-   char *tracknumber = strrchr(url, '/');
+   const char *tracknumber = strrchr(url, '/');
 
    if (!tracknumber)
        tracknumber = (char *)url;
