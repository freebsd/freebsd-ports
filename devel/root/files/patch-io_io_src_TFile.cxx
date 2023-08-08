--- io/io/src/TFile.cxx.orig	2023-02-13 23:57:29 UTC
+++ io/io/src/TFile.cxx
@@ -77,7 +77,9 @@ The structure of a directory is shown in TDirectoryFil
 #include <sys/stat.h>
 #ifndef WIN32
 #include <unistd.h>
+#ifndef R__FBSD
 #include <sys/xattr.h>
+#endif
 #else
 #   define ssize_t int
 #   include <io.h>
@@ -4067,7 +4069,7 @@ TFile *TFile::Open(const char *url, Option_t *options,
    TString expandedUrl(url);
    gSystem->ExpandPathName(expandedUrl);
 
-#ifdef R__UNIX
+#if defined(R__UNIX) && !defined(R__FBSD)
    // If URL is a file on an EOS FUSE mount, attempt redirection to XRootD protocol.
    if (gEnv->GetValue("TFile.CrossProtocolRedirects", 1) == 1) {
       TUrl fileurl(expandedUrl, /* default is file */ kTRUE);
