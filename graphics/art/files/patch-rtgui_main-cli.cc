- workaround for https://bitbucket.org/agriggio/art/issues/227 caused by https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=261360

--- rtgui/main-cli.cc.orig	2022-01-20 17:13:45 UTC
+++ rtgui/main-cli.cc
@@ -121,6 +121,8 @@ std::pair<bool, bool> dontLoadCache(int argc, char **a
 
 int main (int argc, char **argv)
 {
+	setenv("LIBOMP_NUM_HIDDEN_HELPER_THREADS", "0", 1);
+
 #ifdef WITH_MIMALLOC
     mi_version();
 #endif
