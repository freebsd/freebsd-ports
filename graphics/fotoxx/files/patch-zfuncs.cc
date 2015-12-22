--- zfuncs.cc.orig	2015-05-01 09:40:38 UTC
+++ zfuncs.cc
@@ -262,6 +262,7 @@ char *zstrdup(cchar *string, int addcc)
 
 void zmalloc_report()
 {
+#ifdef __linux__
    using namespace zfuncs;
 
    static double     ptime = 0;
@@ -282,6 +283,7 @@ void zmalloc_report()
 
    ptime = jobtime();                                                      //  reset some counters
    Nmalloc = Nstrdup = Nfree = 0;
+#endif
 
    return;
 }
