--- cpp/src/IceSSL/Instance.cpp.orig	2013-10-04 17:48:14.000000000 +0200
+++ cpp/src/IceSSL/Instance.cpp	2015-02-27 08:47:51.309914086 +0100
@@ -266,7 +266,7 @@
                     }
                 }
             }
-#ifndef _WIN32
+#if !defined(_WIN32) && !defined(__FreeBSD__)
             //
             // The Entropy Gathering Daemon (EGD) is not available on Windows.
             // The file should be a Unix domain socket for the daemon.
