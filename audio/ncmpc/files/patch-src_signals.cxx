--- src/signals.cxx.orig	2020-10-17 18:45:52 UTC
+++ src/signals.cxx
@@ -19,6 +19,8 @@
 
 #include "Instance.hxx"
 
+#include <signal.h>
+
 void
 Instance::OnSigwinch() noexcept
 {
